#include <iostream>
#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "gengine.h"
#include "gengine_internals.h"

using namespace gengine;

bool hasArgument(int argc, char* argv[], const std::string& longForm, const std::string& shortForm) {
	for (int i = 1; i < argc; ++i) {
		std::string arg = argv[i];
		if (arg == longForm || arg == shortForm) {
			return true;
		}
	}
	return false;
}

int main(int argc, char* argv[]) {
	Logger* logger = new Logger("Main");
	Window* window = new Window("Test window", Vector2(800, 600));
	Shader* shader = new Shader("./resources/shaders/default/vertex.vert", "./resources/shaders/default/fragment.frag");

	logger->log(INFO, "Loaded logger, window, and default shaders");

	window->polygonMode(GL_FRONT_AND_BACK, GL_FILL);
	if (hasArgument(argc, argv, "--wireframe", "-wf")) {
		logger->log(INFO, "Launching with wireframe mode");
		window->polygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	window->enable(GL_MULTISAMPLE);

	float vertices[] = {
		// Position         // Color
		-0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,
		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f,
	};
	unsigned int indices[] = {
		0, 1, 2
	};

	VAO* vao = new VAO();
	VBO* vbo = new VBO();
	EBO* ebo = new EBO();
	
	ebo->bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	vbo->bind();
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	logger->log(INFO, "Starting main loop");
	while (!(window->shouldClose())) {
		GLFWwindow* win = window->get();
		ColorRGB col = ColorRGB(12, 27, 54);
		window->setBackgroundColor(Color(col));

		glm::mat4 trans = glm::mat4(1.0f);
		trans = glm::translate(trans, glm::vec3(0.0f, 0.0f, 0.0f));
		trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));

		glm::mat4 view = glm::mat4(1.0f);
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

		glm::mat4 projection;
		projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

		shader->setMat4(std::string("transform"), trans);
		shader->setMat4(std::string("model"), model);
		shader->setMat4(std::string("view"), view);
		shader->setMat4(std::string("projection"), projection);
		shader->use();

		vao->bind();
		ebo->bind();
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

		window->update();
	}

	delete window;
	delete shader;
	delete logger;

	return 1;
}