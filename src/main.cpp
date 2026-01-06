#include "color.hpp"

#include <iostream>

int main() 
{
    //Image
    constexpr int image_width {256};
    constexpr int image_height {256};

    //Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int i = 0; i < image_height; i++)
    {
        std::clog << "\rScanlines remaining: "<<(image_height - i) << ' ' << std::flush;
        for (int j = 0; j < image_width; j++)
        {
            auto pixel_color = color(static_cast<double>(j)/(image_width - 1), static_cast<double>(i)/(image_height - 1), 0.0);
            write_color(std::cout, pixel_color, 1);
        }
    }

    std::clog << "\rDone \n";
    return 0;
}
