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

	/********************************/

	ColorRGB::ColorRGB(Color col)
	{
		this->r = std::round(col.r * 255);
		this->g = std::round(col.g * 255);
		this->b = std::round(col.b * 255);
	}
	Color ColorRGB::toColor()
	{
		return Color((float)r/255, (float)g/255, (float)b/255);
	}
}
