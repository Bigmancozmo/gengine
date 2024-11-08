#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>
#include <cmath>

namespace gengine {
	class ColorRGB;
	class Color {
		public:
			float r;
			float g;
			float b;

			Color(float r, float g, float b) : r(r), g(g), b(b) {}
			ColorRGB toRGB();

			static Color rgb(int r_, int g_, int b_);
	};
	class ColorRGB {
		public:
			int r;
			int g;
			int b;

			ColorRGB(int r, int g, int b) : r(r), g(g), b(b) {}
			Color toColor();
	};
};

#endif // COLOR_HPP