#include "Node.hpp"

namespace gengine {
	Node::Node()
	{
		this->x = 0;
		this->y = 0;
		this->w = 0;
		this->h = 0;
	}

	Node::Node(double x, double y)
	{
		this->x = x;
		this->y = y;
		this->w = 0;
		this->h = 0;
	}

	Node::Node(double x, double y, double w, double h)
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}

	Node::Node(Vector2 pos)
	{
		this->x = pos.x;
		this->y = pos.y;
		this->w = 0;
		this->h = 0;
	}

	Node::Node(Vector2 pos, Vector2 size)
	{
		this->x = pos.x;
		this->y = pos.y;
		this->w = size.x;
		this->h = size.y;
	}


	Vector2 Node::getPosition()
	{
		return Vector2(this->x, this->y);
	}

	Vector2 Node::getScale()
	{
		return Vector2(this->w, this->h);
	}
}
