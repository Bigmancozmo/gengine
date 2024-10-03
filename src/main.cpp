#include <iostream>
#include "classes/math/vector/Vector2.hpp"
#include "classes/math/vector/Vector3.hpp"

using namespace gengine;

int main() {
	Vector2 test = Vector2(15, 15.5);
	Vector3 vec = Vector3(0.8, 14.21, 4) - Vector3(1, 2, 3);
	std::cout << "Hello, World! " << std::endl;
	std::cout << vec.x << " -0.2" << std::endl;
	return 1;
}
