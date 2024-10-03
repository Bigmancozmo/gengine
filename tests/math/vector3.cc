#include <gtest/gtest.h>

#include "../../src/classes/math/vector/Vector3.hpp"

using namespace gengine;

TEST(Vector3, Create) {
	Vector3 vec = Vector3(0.8, 14.21, 4);
	EXPECT_EQ(vec.x, 0.8);
	EXPECT_EQ(vec.y, 14.21);
	EXPECT_EQ(vec.z, 4);
}

TEST(Vector3, Add_Vector) {
	Vector3 vec = Vector3(0.8, 14.21, 4) + Vector3(1, 2, 3);
	EXPECT_EQ(vec.x, 1.8);
	EXPECT_EQ(vec.y, 16.21);
	EXPECT_EQ(vec.z, 7);
}

TEST(Vector3, Add_Double) {
	Vector3 vec = Vector3(0.8, 14.21, 4) + 1;
	EXPECT_EQ(vec.x, 1.8);
	EXPECT_EQ(vec.y, 15.21);
	EXPECT_EQ(vec.z, 5);
}

TEST(Vector3, Subtract_Vector) {
	Vector3 vec = Vector3(2, 14.21, 4) - Vector3(4, 2, 3);
	EXPECT_EQ(vec.x, -2);
	EXPECT_EQ(vec.y, 12.21);
	EXPECT_EQ(vec.z, 1);
}

TEST(Vector3, Subtract_Double) {
	Vector3 vec = Vector3(0.8, 14.21, 4) - 2;
	EXPECT_EQ(vec.x, -1.2);
	EXPECT_EQ(vec.y, 12.21);
	EXPECT_EQ(vec.z, 2);
}

TEST(Vector3, Multiply_Vector) {
	Vector3 vec = Vector3(0.8, 14.21, 4) * Vector3(0.5, 2, 3);
	EXPECT_EQ(vec.x, 0.4);
	EXPECT_EQ(vec.y, 28.42);
	EXPECT_EQ(vec.z, 12);
}

TEST(Vector3, Multiply_Double) {
	Vector3 vec = Vector3(0.8, 14.21, 4) * 2;
	EXPECT_EQ(vec.x, 1.6);
	EXPECT_EQ(vec.y, 28.42);
	EXPECT_EQ(vec.z, 8);
}

TEST(Vector3, Divide_Vector) {
	Vector3 vec = Vector3(0.8, 14.21, 9) / Vector3(1, 2, 3);
	EXPECT_EQ(vec.x, 0.8);
	EXPECT_EQ(vec.y, 7.105);
	EXPECT_EQ(vec.z, 3);
}

TEST(Vector3, Divide_Double) {
	Vector3 vec = Vector3(0.8, 14.21, 4) / 2;
	EXPECT_EQ(vec.x, 0.4);
	EXPECT_EQ(vec.y, 7.105);
	EXPECT_EQ(vec.z, 2);
}