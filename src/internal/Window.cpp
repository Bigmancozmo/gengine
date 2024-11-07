#include "Window.hpp"

namespace gengine {
	void Window::createWinHelper(std::string title, int width, int height)
	{
		glfwInit();
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		glfwDefaultWindowHints();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		glfwShowWindow(window);
		glfwMakeContextCurrent(window);
		glViewport(0, 0, 800, 600);
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

	Window::~Window()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}
}
