#include <iostream>
#include "gengine.h"
#include "gengine_internals.h"

using namespace gengine;

int main() {
	Window* window = new Window("Test window", Vector2(1280, 720));
	
	while (!(window->shouldClose())) {
		GLFWwindow* win = window->get();
		ColorRGB col = ColorRGB(150, 0, 0);
		window->setBackgroundColor(Color(col)); // TODO fix values other than 255/0 working

		window->update();
	}

	delete window;

	return 1;
}
