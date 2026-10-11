#include "image_class.h"
#include <iostream>
#include <string>
using namespace std;
void Grayscale(Image& image) {

    for(int i = 0; i < image.width; i++) {
        for(int j = 0; j < image.height; j++) {
            unsigned int avg = 0;

            for(int k = 0; k < image.channels; k++) {

                avg += image (i,j,k);


            }
            avg = avg/3;
            for(int k = 0; k < 3; k++) {

                image(i,j,k) = avg ;
            }

        }

    }




}

int main() {

    Image image;
    if(image.loadNewImage("luffy.jpg")) {
        std::cout<<"Loaded"<<std::endl;
    }

    Grayscale(image);

    int x = image.saveImage("Hello.png");
    std::cout<<x;              //byrg3 1 lw tmam w 0 lw not



    std::cout<<"Saved image"<<std::endl;

}