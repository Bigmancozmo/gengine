#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <iostream>

namespace gengine {
    class Vector2 {
        public:
            double x, y;
            Vector2();
            Vector2(double x, double y);

            // Addition
            Vector2 operator+(const Vector2& other) const;
            Vector2 operator+(double value) const;

            // Subtraction
            Vector2 operator-(const Vector2& other) const;
            Vector2 operator-(double value) const;

            // Multiplication
            Vector2 operator*(const Vector2& other) const;
            Vector2 operator*(double value) const;

            // Division
            Vector2 operator/(const Vector2& other) const;
            Vector2 operator/(double value) const;
    };
}

#endif // VECTOR2_HPP