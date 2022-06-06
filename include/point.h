#ifndef POINT_H
#define POINT_H
class Point {
public: // 굳이 캡슐화를 해야할까?
  Point(int y=0, int x=0): y(y), x(x) {}
  // int prevX, prevY, y, x;
  int y, x;
  void setPos(const Point& p) { y = p.y; x = p.x; }
  Point& operator=(const Point& p) { y = p.y; x = p.x; return *this; }
};
bool operator==(const Point& p1, const Point& p2);

#endif
