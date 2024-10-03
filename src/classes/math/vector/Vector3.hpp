#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <iostream>

namespace gengine {
    class Vector3 {
        public:
            double x, y, z;
            Vector3::Vector3() : x(0), y(0), z(0) {};
            Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {};

            // Addition
            Vector3 operator+(const Vector3& other) const;
            Vector3 operator+(double value) const;

            // Subtraction
            Vector3 operator-(const Vector3& other) const;
            Vector3 operator-(double value) const;

            // Multiplication
            Vector3 operator*(const Vector3& other) const;
            Vector3 operator*(double value) const;

            // Division
            Vector3 operator/(const Vector3& other) const;
            Vector3 operator/(double value) const;
    };
}

#endif // VECTOR3_HPP