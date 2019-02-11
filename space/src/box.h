#ifndef BOX_H

#define BOX_H

class Box
{
public:
  Box();
  Box(int w, int h);
  virtual ~Box();

  // public variable bırakmadım, düzgün şekilde get/set fonksiyonlarını ayarladım
  void setCoordinates(int xt, int yt);
  void setDensity(int d);
  int getX() const;
  int getY() const;
  int getW() const;
  int getH() const;
  int getDensity() const;

private:
  unsigned int width;
  unsigned int height;
  unsigned int density;
  
  // coordinates
  int x;
  int y;
};

#endif