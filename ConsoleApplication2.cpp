#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "x64/Debug/stb-master/stb_image.h"

int main(int argc,char* argv[])
{
    std::string string = "'^\",:;I1!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
    int width, height, pixelSize;
    unsigned char* imageData = stbi_load(argv[1], &width, &height, &pixelSize, 0);
    if (imageData)
    {
        unsigned char* Pixels = imageData;
        for (int rowIndex = 0; rowIndex < height; rowIndex++)
        {
            for (int columnIndex = 0; columnIndex < width; columnIndex++)
            {
                unsigned char R = *Pixels++;
                unsigned char G = *Pixels++;
                unsigned char B = *Pixels++;
                if (pixelSize > 4)
                    unsigned char A = *Pixels++;
                float Avg = (R + G + B) / 3.0f;
                int charIndex = int(string.size() * (Avg / 255.0f));
                std::cout << string[charIndex];
            }
            std::cout << '\n';
        }
    }
    else
        std::cout << "Failed to load the image " << argv[1];
}

