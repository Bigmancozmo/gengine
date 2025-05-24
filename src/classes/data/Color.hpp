#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>
#include <cmath>
#include "../../dll.h"

namespace gengine {
	class GENGINE_API ColorRGB;

	/// @brief Floating point RGB color
	class GENGINE_API Color {
		public:
			/// @brief Red value
			float r;

			/// @brief Green value
			float g;

			/// @brief Blue value
			float b;

			/// @brief Constructor from 3 floats
			/// @param r Red value (0-1)
			/// @param g Green value (0-1)
			/// @param b Blue value (0-1)
			Color(float r, float g, float b) : r(r), g(g), b(b) {}

			/// @brief Constructor from ColorRGB
			/// @param col Integer ColorRGB
			Color(ColorRGB col);

			/// @brief Convrets from a floating point Color to an integer ColorRGB
			/// @return The convreted ColorRGB
			ColorRGB toRGB();
	};

	/// @brief An integer RGB color.
	class GENGINE_API ColorRGB {
		public:
			/// @brief Red value
			int r;

			/// @brief Green value
			int g;

			/// @brief Blue value
			int b;

			/// @brief Constructor from 3 integers
			/// @param r Red value (0-255)
			/// @param g Green value (0-255)
			/// @param b Blue value (0-255)
			ColorRGB(int r, int g, int b) : r(r), g(g), b(b) {}

			/// @brief Constructor from Color
			/// @param col Floating point Color
			ColorRGB(Color col);

			/// @brief Converts from an integer ColorRGB to a floating point Color
			/// @return The converted Color
			Color toColor();
	};
};

#endif // COLOR_HPP