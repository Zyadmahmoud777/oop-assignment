#include "image_class.h"
#include <iostream>
#include <string>
using namespace std;
void HorizontalFlip(Image& image) {

    for(int i = 0; i < image.width/2; i++) {
        for(int j = 0; j < image.height; j++) {


            for(int k = 0; k < image.channels; k++) {

                swap(image(i,j,k),image(image.width-i-1,j,k));

            }
        }
    }
}

void VirticalFlip(Image& image) {

    for(int i = 0; i < image.width; i++) {
        for(int j = 0; j < image.height/2; j++) {


            for(int k = 0; k < image.channels; k++) {

                swap(image(i,j,k),image(i,image.height-j-1,k));

            }
        }
    }
}

int main() {

    Image imageH;
    if(imageH.loadNewImage("arrow.png")) {
        std::cout<<"Loaded"<<std::endl;
    }

    HorizontalFlip(imageH);
    int x = imageH.saveImage("FH.png");
    std::cout<<x;
    std::cout<<"Horizontal Flip Saved"<<std::endl;


    Image imageV;
    if(imageV.loadNewImage("arrow.png")) {
        std::cout<<"Loaded"<<std::endl;
    }

    VirticalFlip(imageV);
    int y = imageV.saveImage("FV.png");
    std::cout<<y;
    std::cout<<"Virtical Flip Saved"<<std::endl;


}