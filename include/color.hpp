#pragma once 

#include "vec3.hpp"
#include <iosfwd>

// Color is an alias for a 3D vector interpreted as RGB
using color = vec3;

// Writes a color to the output stream in PPM format
void  write_color(std::ostream& out, const color& pixel_color, int samples_per_pixel);
