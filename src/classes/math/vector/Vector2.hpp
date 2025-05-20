#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <iostream>

namespace gengine {
    class Vector2 {
        public:
            /// @brief X value
            double x;

            /// @brief Y value
            double y;

            /// @brief Empty constructor - X and Y will be 0
            Vector2() : x(0), y(0) {}

            /// @brief Constructor with X and Y
            /// @param x X value
            /// @param y Y value
            Vector2(double x, double y) : x(x), y(y) {}

            // Addition
            
            /// @brief Add the X and Y of a Vector2 to this Vector2
            /// @param other The other Vector2
            /// @return The new Vector2
            Vector2 operator+(const Vector2& other) const;

            /// @brief Add the same value to both the X and Y of this Vector2
            /// @param value The value to add
            /// @return The new Vector2
            Vector2 operator+(double value) const;

            // Subtraction

            /// @brief Subtract the X and Y of a Vector2 from this Vector2
            /// @param other The other Vector2
            /// @return The new Vector2
            Vector2 operator-(const Vector2& other) const;

            /// @brief Subtract the same value from both the X and Y of this Vector2
            /// @param value The value to subtract
            /// @return The new Vector2
            Vector2 operator-(double value) const;

            // Multiplication

            /// @brief Multiply the X and Y of this Vector2 by the X and Y of another Vector2
            /// @param other The other Vector2
            /// @return The new Vector2
            Vector2 operator*(const Vector2& other) const;

            /// @brief Multiply the X and Y of this Vector2 by the same value
            /// @param value The value to multiply by
            /// @return The new Vector2
            Vector2 operator*(double value) const;

            // Division

            /// @brief Divide the X and Y of this Vector2 by the X and Y of another Vector2
            /// @param other The other Vector2
            /// @return The new Vector2
            Vector2 operator/(const Vector2& other) const;

            /// @brief Divide the X and Y of this Vector2 by the same number
            /// @param value The value to divide by
            /// @return The new Vector2
            Vector2 operator/(double value) const;
    };
}

#endif // VECTOR2_HPP