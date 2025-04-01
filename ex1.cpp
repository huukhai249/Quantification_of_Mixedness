
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>

#include "bitmap_image.hpp"

int main()
{
    bitmap_image image("blackbuck.bmp");

   if (!image)
   {
      printf("Error - Failed to open: blackbuck.bmp\n");
      return 1;
   }

   const unsigned int height = image.height();
   const unsigned int width  = image.width();

   bitmap_image bw_image(width, height);

   for (std::size_t y = 0; y < height; ++y)
   {
      for (std::size_t x = 0; x < width; ++x)
      {
         rgb_t colour;
         image.get_pixel(x, y, colour);

         // Check if the pixel is black (R=0, G=0, B=0)
         if (colour.red == 0 && colour.green == 0 && colour.blue == 0)
         {
            // Set the pixel to white in the black and white image
            bw_image.set_pixel(x, y, 255, 255, 255);
         }
         else
         {
            // Set the pixel to black in the black and white image
            bw_image.set_pixel(x, y, 0, 0, 0);
         }
      }
   }

   bw_image.save_image("output_bw.bmp");

   printf("Converted image saved as output_bw.bmp\n");

   return 0;
}