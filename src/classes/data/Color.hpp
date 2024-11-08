#ifndef COLOR_HPP
#define COLOR_HPP

#include "ColorRGB.hpp"

namespace gengine {
	class Color {
		public:
			float r;
			float g;
			float b;

			Color(float r, float g, float b) : r(r), g(g), b(b) {}
			static Color rgb();
			static ColorRGB toRGB();
	};
};

#endif // COLOR_HPP