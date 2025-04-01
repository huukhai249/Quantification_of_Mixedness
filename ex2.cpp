// Reading black and white color image to calculate CoV


#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "tinyfiledialogs.h"
#include "bitmap_image.hpp"
#include <sstream>

struct concentration{
    unsigned int pixel_white;
    unsigned int pixel_black;
    unsigned int total_pixel;
};

concentration read_data(bitmap_image imagefile){
    concentration c{0,0,0};
    if (!imagefile)
   {
      printf("Error - Failed to open input file \n");
      return c;
   }
   const unsigned int height = imagefile.height();
   const unsigned int width  = imagefile.width();
   unsigned int Pixel_black=0;
   unsigned int Pixel_white=0;
   for (std::size_t y = 0; y < height; ++y)
   {
      for (std::size_t x = 0; x < width; ++x)
      {
         rgb_t colour;
         imagefile.get_pixel(x, y, colour);

         // Check if the pixel is black 
         if (colour.red == 0 && colour.green == 0 && colour.blue == 0)
         {
            // Process for the pixel have white color
            Pixel_black++;
            
         }
         else
         {
            // Process for the pixel have black color
            Pixel_white++;
         }
      }
   }
   c.pixel_white = Pixel_white;
   c.pixel_black = Pixel_black;
   c.total_pixel = height*width;
   printf("total pixel: %d, white: %d, black: %d\n",c.total_pixel,c.pixel_white,c.pixel_black);

   return c;
}
std::vector<bitmap_image> browse_and_load_images()
{
    std::vector<bitmap_image> list_image;

    // Open file dialog to select multiple images
    const char* lFilterPatterns[2] = { "*.bmp", "*.png" };
    char const* lTheOpenFileName;
    lTheOpenFileName = tinyfd_openFileDialog(
        "Select Image Files",
        "",
        2,
        lFilterPatterns,
        NULL,
        1);

    if (lTheOpenFileName)
    {
        // Split the selected file paths (if multiple files are selected)
        std::string file_paths = lTheOpenFileName;
        std::stringstream ss(file_paths);
        std::string file_path;

        while (std::getline(ss, file_path, '|')) {
            bitmap_image image(file_path);
            if (image.width() > 0 && image.height() > 0) {
                list_image.push_back(image);
            }
            else {
                std::cout << "Error - Failed to open: " << file_path << "\n";
            }
        }
    }
    else
    {
        std::cout << "No file selected.\n";
    }

    return list_image;
}


int main()
{
    std::vector<bitmap_image> list_image = browse_and_load_images();
    printf("read %ld files \n",list_image.size());
   return 0;
}