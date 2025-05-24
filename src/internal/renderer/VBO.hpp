#ifndef VBO_HPP
#define VBO_HPP

#include "../../dll.h"
#include "glad/glad.h"

namespace gengine {
	class GENGINE_API VBO {
	private:
		unsigned int ID;
	public:
		VBO();
		void bind();
	};
}

#endif // VBO_HPP