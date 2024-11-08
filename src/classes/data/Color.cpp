#include "Color.hpp"

namespace gengine {
	Color::Color(ColorRGB col)
	{
		this->r = (float)col.r / 255;
		this->g = (float)col.g / 255;
		this->b = (float)col.b / 255;
	}
	ColorRGB Color::toRGB() {
		return ColorRGB(
			std::round(r * 255),
			std::round(g * 255),
			std::round(b * 255));
	}
}
