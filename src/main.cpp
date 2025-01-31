#include <iostream>
#include <glad/glad.h>

#include "gengine.h"
#include "gengine_internals.h"
#include "internal/ProgramRunner.hpp"
#define logERROR ERROR
#include <windows.h>

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

void deleteDirectory(const std::string& directory) {
	WIN32_FIND_DATA findFileData;
	HANDLE hFind = FindFirstFile((directory + "\\*").c_str(), &findFileData);

	if (hFind == INVALID_HANDLE_VALUE) {
		std::cerr << "Failed to find first file in directory: " << directory << std::endl;
		return;
	}

	do {
		const std::string fileOrDir = findFileData.cFileName;
		if (fileOrDir != "." && fileOrDir != "..") {
			const std::string fullPath = directory + "\\" + fileOrDir;
			if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
				deleteDirectory(fullPath);
			}
			else {
				if (!DeleteFile(fullPath.c_str())) {
					std::cerr << "Failed to delete file: " << fullPath << std::endl;
				}
			}
		}
	} while (FindNextFile(hFind, &findFileData) != 0);

	FindClose(hFind);

	if (!RemoveDirectory(directory.c_str())) {
		std::cerr << "Failed to remove directory: " << directory << std::endl;
	}
}


int main(int argc, char* argv[]) {
	Logger* logger = new Logger("Main");
	Window* window = new Window("Test window", Vector2(800, 600));
	Shader* shader = new Shader("./resources/shaders/default/vertex.vert", "./resources/shaders/default/fragment.frag");

	if (CreateDirectory("temp", NULL) || ERROR_ALREADY_EXISTS == GetLastError()) {
		logger->log(INFO, "Created 'temp' folder");
	}
	else {
		logger->log(logERROR, "Failed to create 'temp' folder");
	}

	logger->log(INFO, "Loaded logger, window, and default shaders");

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	if (hasArgument(argc, argv, "--wireframe", "-wf")) {
		logger->log(INFO, "Launching with wireframe mode");
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	glEnable(GL_MULTISAMPLE);

	float vertices[] = {
		// Position         // Color
		-0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,
		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f,
	};
	unsigned int indices[] = {
		0, 1, 2
	};

	unsigned int VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &EBO);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
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

		shader->use();
		glBindVertexArray(VAO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		window->update();
	}

	delete window;
	deleteDirectory("temp");

	return 1;
}