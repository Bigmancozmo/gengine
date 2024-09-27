#include <gtest/gtest.h>

#include "../src/classes/math/vector/Vector2.hpp"

using namespace gengine;

TEST(Vector2, Create) {
	Vector2 vec = Vector2(2.5, 5.23);
	EXPECT_EQ(vec.x, 2.5);
	EXPECT_EQ(vec.y, 5.23);
}

TEST(Vector2, Add_Vector) {
	Vector2 vec1 = Vector2(2, 3);
	Vector2 vec2 = Vector2(5, 8);
	Vector2 added = vec1 + vec2;
	EXPECT_EQ(added.x, 7);
	EXPECT_EQ(added.y, 11);
}

TEST(Vector2, Add_Double) {
	Vector2 vec1 = Vector2(2, 3);
	Vector2 added = vec1 + 2;
	EXPECT_EQ(added.x, 4);
	EXPECT_EQ(added.y, 5);
}

TEST(Vector2, Subtract_Vector) {
	Vector2 vec1 = Vector2(2, 3);
	Vector2 vec2 = Vector2(5, 8);
	Vector2 calc = vec1 - vec2;
	EXPECT_EQ(calc.x, -3);
	EXPECT_EQ(calc.y, -5);
}

TEST(Vector2, Subtract_Double) {
	Vector2 vec1 = Vector2(2, 3);
	Vector2 calc = vec1 - 2;
	EXPECT_EQ(calc.x, 0);
	EXPECT_EQ(calc.y, 1);
}

TEST(Vector2, Multiply_Vector) {
	Vector2 vec1 = Vector2(2, 3);
	Vector2 vec2 = Vector2(5, 8);
	Vector2 calc = vec1 * vec2;
	EXPECT_EQ(calc.x, 10);
	EXPECT_EQ(calc.y, 24);
}

TEST(Vector2, Multiply_Double) {
	Vector2 vec1 = Vector2(2, 3);
	Vector2 calc = vec1 * 2;
	EXPECT_EQ(calc.x, 4);
	EXPECT_EQ(calc.y, 6);
}

TEST(Vector2, Divide_Vector) {
	Vector2 vec1 = Vector2(4, 8);
	Vector2 vec2 = Vector2(2, 4);
	Vector2 added = vec1 / vec2;
	EXPECT_EQ(added.x, 2);
	EXPECT_EQ(added.y, 2);
}

TEST(Vector2, Divide_Double) {
	Vector2 vec1 = Vector2(12, 5);
	Vector2 added = vec1 / 2;
	EXPECT_EQ(added.x, 6);
	EXPECT_EQ(added.y, 2.5);
}