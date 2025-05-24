#include "Window.hpp"
#include "Window.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

namespace gengine {
	void Window::createWinHelper(std::string title, int width, int height)
	{
		logger = new Logger("Window");
		if(!glfwInit()) {
			logger->log(ERROR, "GLFW failed to initialize");
			return;
		}
		logger->log(INFO, "Initialized GLFW");

		glfwDefaultWindowHints();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_SAMPLES, 4);

		window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		if (!window) {
			logger->log(ERROR, "Failed to create GLFW window");
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(window);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			logger->log(ERROR, "Failed to initialize GLAD");
			return;
		}

		glfwShowWindow(window);
		glfwMakeContextCurrent(window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			logger->log(ERROR, "Failed to initialize GLAD");
			return;
		}
		
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
		glViewport(0, 0, width, height);
		logger->log(INFO, "Finished creating window");
	}

	Window::Window(std::string title)
	{
		createWinHelper(title, 800, 600);
	}
	Window::Window(std::string title, Vector2 size)
	{
		createWinHelper(title, (int)size.x, (int)size.y);
	}
	Window::Window(Vector2 size)
	{
		createWinHelper("Untitled Window", (int)size.x, (int)size.y);
	}

	bool Window::shouldClose()
	{
		return glfwWindowShouldClose(window);
	}

	void Window::update()
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	Vector2 Window::getPosition()
	{
		return Vector2();
	}
	Vector2 Window::getScale()
	{
		return Vector2();
	}

	GLFWwindow* Window::get()
	{
		return window;
	}

	void Window::setBackgroundColor(Color col)
	{
		glClearColor(col.r, col.g, col.b, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Window::setBackgroundColor(ColorRGB col)
	{
		Color converted = col.toColor();
		glClearColor(col.r, col.g, col.b, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	Window::~Window()
	{
		glfwDestroyWindow(window);
	}
}
