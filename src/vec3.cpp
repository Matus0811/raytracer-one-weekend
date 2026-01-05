#include "vec3.hpp"

#include <cassert>   // for assert()
#include <cmath>     // for std::sqrt

// -----------------------------------------------------------------------------
// Constructors
// -----------------------------------------------------------------------------

// Default constructor initializes vector to (0, 0, 0)
vec3::vec3() : x_{0.0}, y_{0.0}, z_{0.0} {}

// Constructs vector with given components
vec3::vec3(double x, double y, double z) : x_{x}, y_{y}, z_{z} {}

// -----------------------------------------------------------------------------
// Component accessors
// -----------------------------------------------------------------------------

// Returns x component
double vec3::x() const { return x_; }

// Returns y component
double vec3::y() const { return y_; }

// Returns z component
double vec3::z() const { return z_; }

// -----------------------------------------------------------------------------
// Operators
// -----------------------------------------------------------------------------

// Unary minus operator (vector negation)
vec3 vec3::operator-() const
{
    return vec3(-x_, -y_, -z_);
}

// Read-only indexed access to vector components
// 0 -> x, 1 -> y, 2 -> z
double vec3::operator[](int i) const
{
    switch (i)
    {
        case 0: return x_;
        case 1: return y_;
        case 2: return z_;
        default:
            // Index out of valid range indicates a programming error
            assert(false && "vec3 index out of range (expected 0, 1 or 2)");
            return 0.0; // fallback for release builds
    }
}

// Writable indexed access to vector components
double& vec3::operator[](int i)
{
    switch (i)
    {
        case 0: return x_;
        case 1: return y_;
        case 2: return z_;
        default:
            assert(false && "vec3 index out of range (expected 0, 1 or 2)");
            return x_; // fallback for release builds
    }
}

// Compound vector addition
vec3& vec3::operator+=(const vec3& v)
{
    x_ += v.x_;
    y_ += v.y_;
    z_ += v.z_;
    return *this;
}

// Compound scalar multiplication
vec3& vec3::operator*=(double t)
{
    x_ *= t;
    y_ *= t;
    z_ *= t;
    return *this;
}

// Compound scalar division
vec3& vec3::operator/=(double t)
{
    // Division by zero should never occur in valid usage
    assert(t != 0.0 && "division by zero in vec3::operator/=");
    return *this *= (1.0 / t);
}

// -----------------------------------------------------------------------------
// Vector length
// -----------------------------------------------------------------------------

// Returns squared length of the vector
// Used to avoid unnecessary sqrt operations when possible
double vec3::length_squared() const
{
    return x_ * x_ + y_ * y_ + z_ * z_;
}

// Returns Euclidean length (magnitude) of the vector
double vec3::length() const
{
    return std::sqrt(length_squared());
}
