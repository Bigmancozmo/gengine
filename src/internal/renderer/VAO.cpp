#include "VAO.hpp"

namespace gengine {
	VAO::VAO()
	{
		glGenVertexArrays(1, &ID);
		glBindVertexArray(ID);
	}

	void VAO::bind()
	{
		glBindVertexArray(ID);
	}
}