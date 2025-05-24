#include "VBO.hpp"

namespace gengine {
	VBO::VBO()
	{
		glGenBuffers(1, &ID);
	}

	void VBO::bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, ID);
	}
}