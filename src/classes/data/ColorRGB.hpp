#ifndef COLOR_RGB_HPP
#define COLOR_RGB_HPP

#include "Color.hpp"

namespace gengine {
	class ColorRGB {
		public:
			int r;
			int g;
			int b;

			ColorRGB(int r, int g, int b) : r(r), g(g), b(b) {}
			static Color toColor();
	};
};

#endif // COLOR_RGB_HPP