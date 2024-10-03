#include "Vector2.hpp"

namespace gengine {
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