#include <iostream>
#include "classes/math/vector/Vector2.hpp"
#include "classes/math/vector/Vector3.hpp"
#include "internal/Window.hpp"

using namespace gengine;

int main() {
	Window* window = new Window("Test window", Vector2(1280, 720));
	
	while (!(window->shouldClose())) {
		window->update();
	}

	delete window;

	return 1;
}
