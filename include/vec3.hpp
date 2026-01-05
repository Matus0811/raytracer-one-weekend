#pragma once

// 3D vector class used throughout the ray tracer.
// Represents both geometric vectors and colors.
class vec3
{
public:
    // Constructors
    vec3();                                   // Initializes vector to (0, 0, 0)
    vec3(double x, double y, double z);       // Initializes vector with given components

    // Component accessors
    double x() const;                         // Returns x component
    double y() const;                         // Returns y component
    double z() const;                         // Returns z component

    // Unary minus operator (vector negation)
    vec3 operator-() const;

    // Indexed component access
    // 0 -> x, 1 -> y, 2 -> z
    double operator[](int i) const;            // Read-only access
    double& operator[](int i);                 // Writable access

    // Compound assignment operators
    vec3& operator+=(const vec3& v);           // Vector addition
    vec3& operator*=(double t);                // Scalar multiplication
    vec3& operator/=(double t);                // Scalar division

    // Vector length operations
    double length() const;                     // Returns vector magnitude
    double length_squared() const;             // Returns squared magnitude (avoids sqrt)

private:
    // Vector components
    double x_;
    double y_;
    double z_;
};

// Alias used for points in 3D space to improve code readability
using point3 = vec3;
