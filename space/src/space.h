#ifndef SPACE_H
#define SPACE_H

#include "box.h"

#include <fstream>

class Space
{
public:
  Space();
  Space(int w, int h);
  virtual ~Space();

  // minimum adette public fonksiyon kullanmaya çalıştım
  void fillRandomBox(int boxCount, int maxSize, int d);
  void printBoxCoordinates();
  void printCenterOfMass();
  void printSpace() const;

  void outputToFile();
  
private:
  void constructSpace();
  int checkSpace(int x, int y, int w, int h) const;
  void addBox(int x, int y, int w, int h, int d);
  void calculateCenterOfMass();
  
  int **space;
  Box *box;
  unsigned int boxCounter;
  unsigned int spaceWidth;
  unsigned int spaceHeight;
  unsigned int usedSpace;
  double centerOfMass_x;
  double centerOfMass_y;

  std::ofstream fp;
};

#endif