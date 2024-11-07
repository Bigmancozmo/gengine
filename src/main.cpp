#include <iostream>
#include "gengine.h"
#include "gengine_internals.h"

using namespace gengine;

int main() {
	Window* window = new Window("Test window", Vector2(1280, 720));
	
	while (!(window->shouldClose())) {
		GLFWwindow* win = window->get();
		window->update();
	}

	delete window;

	return 1;
}
