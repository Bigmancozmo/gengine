#include "Vector2.hpp"

namespace gengine {
    Vector2::Vector2() {
		this->x = 0;
		this->y = 0;
	}

	Vector2::Vector2(double x, double y) {
		this->x = x;
		this->y = y;
    }

	Vector2 Vector2::operator+(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}
	Vector2 Vector2::operator+(double value) const
	{
		return Vector2(x + value, y + value);
	}
	Vector2 Vector2::operator-(const Vector2& other) const
	{
		return Vector2(x - other.x, y - other.y);
	}
	Vector2 Vector2::operator-(double value) const
	{
		return Vector2(x - value, y - value);
	}
	Vector2 Vector2::operator*(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}
	Vector2 Vector2::operator*(double value) const
	{
		return Vector2(x * value, y * value);
	}
	Vector2 Vector2::operator/(const Vector2& other) const
	{
		return Vector2(x / other.x, y / other.y);
	}
	Vector2 Vector2::operator/(double value) const
	{
		return Vector2(x / value, y / value);
	}
}