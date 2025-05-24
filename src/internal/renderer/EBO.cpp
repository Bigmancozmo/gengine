#include "EBO.hpp"

namespace gengine {
	EBO::EBO()
	{
		glGenBuffers(1, &ID);
	}

	void EBO::bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	}
}