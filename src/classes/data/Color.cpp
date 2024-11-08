#include "Color.hpp"

namespace gengine {
	Color Color::rgb(int r_, int g_, int b_) {
  return Color(r_/255, g_/255, b_/255);
 }
 ColorRGB Color::toRGB() 
  return ColorRGB(
   std::round(r*255),
   std::round(g*255),
   std::round(b*255))
 }
}
