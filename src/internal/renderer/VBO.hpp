#ifndef VBO_HPP
#define VBO_HPP

#include "glad/glad.h"

namespace gengine {
	class VBO {
	private:
		unsigned int ID;
	public:
		VBO();
		void bind();
	};
}

#endif // VBO_HPP