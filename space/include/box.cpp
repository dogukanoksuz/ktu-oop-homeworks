#include "../src/box.h"

#include <iostream>
using namespace std;

Box::Box()
{
    width = 0, height = 0, x = 0, y = 0, density = 0;
}

Box::Box(int w, int h)
{
    if ((!(w * h <= 6)) || w < 0 || h < 0)
    {
        cout << "Invalid input or you exceeded the 6 box limit." << endl;
        exit(EXIT_FAILURE);
    }
    x = 0, y = 0;
    width = w;
    height = h;
    density = 0;
}

Box::~Box()
{
}

void Box::setCoordinates(int xt, int yt)
{
    if (xt >= 0 && yt >= 0)
    {
        x = xt, y = yt;
    }
    else
    {
        cout << "The coordinates can't be set as minus values" << endl;
        return;
    }
}

int Box::getX() const
{
    return x;
}

int Box::getY() const
{
    return y;
}

int Box::getW() const
{
    return width;
}

int Box::getH() const
{
    return height;
}

void Box::setDensity(int d)
{
    density = d;
}

int Box::getDensity() const
{
    return density;
}