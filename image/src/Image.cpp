//
// Created by divergent / Doğukan ÖKSÜZ (365304) on 12/27/18.
// root@dogukanoksuz.com.tr
//

#include "../include/Image.h"

Image::Image()
{
    thresoldValue = 127;
}

Image::Image(const Image &a)
{
    width = a.getWidth();
    height = a.getHeight();
    image = new uint8_t[width * height];
    thresoldValue = 127;
}

Image::~Image()
{
    // delete[] image;
}

istream &operator>>(istream &input, Image &img)
{
    uint8_t wh[2];
    input.read((char *)wh, 2);
    img.width = wh[0];
    img.height = wh[1];
    img.image = new uint8_t[img.width * img.height];

    input.read((char *)img.image, img.width * img.height);

    return input;
}

Image Image::operator+(Image &a)
{
    Image output;
    output.generateArray(a.getWidth(), a.getHeight());

    uint8_t temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; ++j)
        {
            temp = (uint8_t)(this->getPixel(j, i) | a.getPixel(j, i));
            output.setPixel(temp, i);
        }
    }

    return output;
}

Image Image::operator*(Image &a)
{
    Image output1;
    output1.generateArray(a.getWidth(), a.getHeight());

    uint8_t temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; ++j)
        {
            temp = (uint8_t)(this->getPixel(j, i) & a.getPixel(j, i));
            output1.setPixel(temp, i);
        }
    }

    return output1;
}

Image Image::operator!()
{
    Image output2;
    output2.generateArray(this->width, this->height);

    uint8_t temp;
    for (int i = 0; i < width * height; i++)
    {
        temp = (uint8_t)(~this->image[i]);
        output2.setPixel(temp, i);
    }

    return output2;
}

ostream &operator<<(ostream &output, Image &img)
{
    for (int j = 0; j < img.width; j++)
    {
        for (int i = 0; i < img.height; i++)
        {
            if (img.getPixel(j, i) > img.thresoldValue)
            {
                output << "**";
            }

            if (img.getPixel(j, i) <= img.thresoldValue)
            {
                output << "--";
            }
        }
        output << endl;
    }
    return output;
}

void Image::thresold(int val)
{
    for (int i = 0; i < width * height; i++)
    {
        if (image[i] <= (uint8_t)val)
        {
            image[i] = 0;
        }
        else
        {
            image[i] = 255;
        }
    }
}

uint8_t Image::sobelPerElement(int x, int y)
{
    int Gx;
    int Gy;
    uint8_t result;

    Gx = -1 * getPixel((x - 1), (y - 1)) +
         -2 * getPixel((x), (y - 1)) +
         -1 * getPixel((x + 1), (y - 1)) +
         1 * getPixel((x - 1), (y + 1)) +
         2 * getPixel((x), (y + 1)) +
         1 * getPixel((x + 1), (y + 1));

    Gy = -1 * getPixel((x - 1), (y - 1)) +
         -2 * getPixel((x - 1), (y)) +
         -1 * getPixel((x - 1), (y + 1)) +
         1 * getPixel((x + 1), (y - 1)) +
         2 * getPixel((x + 1), (y)) +
         1 * getPixel((x + 1), (y + 1));

    Gx /= 4;
    Gy /= 4;
    result = sqrt(Gx * Gx + Gy * Gy);

    return result;
}

void Image::sobel()
{
    uint8_t *sobelBuffer = new uint8_t[width * height];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sobelBuffer[i * width + j] = sobelPerElement(j, i);
        }
    }
    image = sobelBuffer;
}

uint8_t Image::getWidth() const
{
    return width;
}

uint8_t Image::getHeight() const
{
    return height;
}

uint8_t Image::getPixel(int x, int y) const
{
    int index = y * width + x;
    if (index < 0)
    {
        return 0;
    }

    if (index >= width * height)
    {
        return 0;
    }
    return image[index];
}

void Image::generateArray(uint8_t width, uint8_t height)
{
    Image::width = width;
    Image::height = height;

    image = new uint8_t[Image::width * Image::height];
}

void Image::setPixel(uint8_t val, int loc)
{
    image[loc] = val;
}

void Image::setThresoldValue(int thresoldValue)
{
    Image::thresoldValue = thresoldValue;
}