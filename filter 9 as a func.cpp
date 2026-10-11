#include "Image_Class.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
Image marge(Image &image1, Image &image2)
{

    // for the dimensions using common are will avoiding code a resize func.

    int w = min(image1.width, image2.width);
    int h = min(image1.height, image2.height);

    Image result(w, h);

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            for (int k = 0; k < image1.channels; k++)
            {

                result(i, j, k) = (image1(i, j, k) + image2(i, j, k)) / 2;
            }
        }
    }
    return result;
}

int main()
{
    Image image1;
    if (image1.loadNewImage("toy1.jpg"))
    {
        std::cout << "Loaded" << std::endl;
    }
    Image image2;
    if (image2.loadNewImage("toy2.jpg"))
    {
        std::cout << "Loaded" << std::endl;
    }

    Image marged = marge(image1, image2);
    marged.saveImage("marged.jpg");
}