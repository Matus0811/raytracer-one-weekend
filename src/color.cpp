#include "color.hpp"

#include <iostream>

// Writes a color value to the output stream in PPM format.
// The color components are averaged over the number of samples
// per pixel and mapped to the integer range [0, 255].
void write_color(std::ostream& out, const color& pixel_color, int samples_per_pixel)
{
    // Extract RGB components from the color vector
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Average color values based on the number of samples per pixel
    const auto scale = 1.0 / samples_per_pixel;
    r *= scale;
    g *= scale;
    b *= scale;

    // Convert color values from [0,1] to [0,255]
    const int rbyte = static_cast<int>(255.999 * r);
    const int gbyte = static_cast<int>(255.999 * g);
    const int bbyte = static_cast<int>(255.999 * b);

    // Output the color components
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
