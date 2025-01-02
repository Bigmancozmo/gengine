#include <gtest/gtest.h>

#include "../../src/classes/data/Color.hpp"

using namespace gengine;

TEST(Color, Create) {
	Color col = Color(0.1, 0.2, 0.3);
	// using EXPECT_NEAR due to floating point inaccuracies
	EXPECT_NEAR(col.r, 0.1, 1e-6);
	EXPECT_NEAR(col.g, 0.2, 1e-6);
	EXPECT_NEAR(col.b, 0.3, 1e-6);
}

TEST(Color, ToRGB) {
	Color col = Color(0.1, 0.2, 0.3);
	ColorRGB rgb = col.toRGB();
	EXPECT_EQ(rgb.r, 26);      // ColorRGB conversion is rounded,
	EXPECT_EQ(rgb.g, 51);      // so we also round the the checks.
	EXPECT_EQ(rgb.b, 77);
}

TEST(ColorRGB, Create) {
	ColorRGB rgb = ColorRGB(26, 51, 77);
	EXPECT_EQ(rgb.r, 26);
	EXPECT_EQ(rgb.g, 51);
	EXPECT_EQ(rgb.b, 77);
}

TEST(ColorRGB, ToColor) {
	ColorRGB rgb = ColorRGB(26, 51, 77);
	Color col = rgb.toColor();
	EXPECT_NEAR(col.r, 0.10196078, 1e-6);
	EXPECT_NEAR(col.g, 0.2, 1e-6);
	EXPECT_NEAR(col.b, 0.30196078, 1e-6);
}

using namespace gengine;