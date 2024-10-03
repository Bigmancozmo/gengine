#include "Vector3.hpp"

namespace gengine {
	Vector3 Vector3::operator+(const Vector3& other) const
	{
		return Vector3(x + other.x, y + other.y, z + other.z);
	}
	Vector3 Vector3::operator+(double value) const
	{
		return Vector3(x + value, y + value, z + value);
	}
	Vector3 Vector3::operator-(const Vector3& other) const
	{
		return Vector3(x - other.x, y - other.y, z - other.z);
	}
	Vector3 Vector3::operator-(double value) const
	{
		return Vector3(x - value, y - value, z - value);
	}
	Vector3 Vector3::operator*(const Vector3& other) const
	{
		return Vector3(x * other.x, y * other.y, z * other.z);
	}
	Vector3 Vector3::operator*(double value) const
	{
		return Vector3(x * value, y * value, z * value);
	}
	Vector3 Vector3::operator/(const Vector3& other) const
	{
		return Vector3(x / other.x, y / other.y, z / other.z);
	}
	Vector3 Vector3::operator/(double value) const
	{
		return Vector3(x / value, y / value, z / value);
	}
}