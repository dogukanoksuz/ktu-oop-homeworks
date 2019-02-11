//
// Created by divergent / Doğukan ÖKSÜZ (365304) on 12/27/18.
// root@dogukanoksuz.com.tr
//

#ifndef IMAGE_IMAGE_H
#define IMAGE_IMAGE_H


#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

class Image
{
public:
    Image();
    Image(const Image &a);
    ~Image();

    // overloading input&output operators
    friend istream &operator>>(istream &input, Image &img);
    friend ostream &operator<<(ostream &output, Image &img);

    // overloading not, +, - operators
    Image operator+(Image &a);
    Image operator*(Image &a);
    Image operator!();

    uint8_t sobelPerElement(int x, int y);
    void sobel();
    void thresold(int val);

    uint8_t getWidth() const;
    uint8_t getHeight() const;
    uint8_t getPixel(int x, int y) const;
    void setPixel(uint8_t val, int loc);
    void generateArray(uint8_t width, uint8_t height);
    void setThresoldValue(int thresoldValue);

private:
    uint8_t width;
    uint8_t height;
    uint8_t *image;

    int thresoldValue;
};


#endif //IMAGE_IMAGE_H
