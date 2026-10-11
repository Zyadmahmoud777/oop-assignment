#include "image_class.h"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void sunlight(Image &image)
{

    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            for (int k = 0; k < image.channels; k++)
            {
                if (k == 0)
                    image(i, j, k) = min(255, (int)image(i, j, k) + 35);
                else if (k == 1)
                    image(i, j, k) = min(255, (int)image(i, j, k) + 20);
                else
                    image(i, j, k) = max(0, (int)image(i, j, k) - 25);
            }
        }
    }
}

int main()
{
    Image image;
    image.loadNewImage("Wano 2.jpg");

    sunlight(image);

    image.saveImage("sunlight.jpg");

    return 0;
}