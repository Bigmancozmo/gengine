#include "Window.hpp"

namespace gengine {
	void Window::createWinHelper(std::string title, int width, int height)
	{
		glfwInit();

		glfwDefaultWindowHints();
		window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		glfwShowWindow(window);
		glfwMakeContextCurrent(window);
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
