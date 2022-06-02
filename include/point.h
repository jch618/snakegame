#ifndef POINT_H
#define POINT_H
class Point {
public: // 굳이 캡슐화를 해야할까?
  Point(int y=0, int x=0) {}
  int prevX, prevY, y, x;
  void setPos(const Point& p) { prevY = y; prevX = x; y = p.y; x = p.x; }
  Point& operator=(const Point& p) { prevY = y; prevX = x; y = p.y; x = p.x; return *this; }
  // Point(int y, int x): _y(y), _x(x) {}
  // int getY() { return y; }
  // int getX() { return x; }
  // void setY(int y) { _y = y; }
  // void setX(int x) { _x = x; }
  // void move
};
#endif
