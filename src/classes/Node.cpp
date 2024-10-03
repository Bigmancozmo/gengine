#include "Node.hpp"

namespace gengine {
	Vector2 Node::getPosition()
	{
		return Vector2(this->x, this->y);
	}

	Vector2 Node::getScale()
	{
		return Vector2(this->w, this->h);
	}
}
