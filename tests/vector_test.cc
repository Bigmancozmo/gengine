#include <gtest/gtest.h>

#include "../src/classes/math/vector/Vector2.hpp"

using namespace gengine;

TEST(Vector2, Create) {
	Vector2 vec = Vector2(2.5, 5.23);
	EXPECT_EQ(vec.x, 2.5);
	EXPECT_EQ(vec.y, 5.23);
}