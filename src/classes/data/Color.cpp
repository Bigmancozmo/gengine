#include "Color.hpp"

namespace gengine {
	Color::Color(ColorRGB col)
	{
		this->r = col.r / 255;
		this->g = col.g / 255;
		this->b = col.b / 255;
	}
	ColorRGB Color::toRGB() {
		return ColorRGB(
			std::round(r * 255),
			std::round(g * 255),
			std::round(b * 255));
	}

	Color ColorRGB::toColor() {
		return Color(r / 255, g / 255, b / 255);
	}
}
