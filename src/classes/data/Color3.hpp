#ifndef COLOR3_HPP
#define COLOR3_HPP

namespace gengine {
	class Color3 {
		public:
			float r;
			float g;
			float b;

			Color3(float r, float g, float b) : r(r), g(g), b(b) {}
			static Color3 rgb();
			static Color3 toRGB();
	};
};

#endif // COLOR3_HPP