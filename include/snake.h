#ifndef SNAKE_H
#define SNAKE_H
#include <iostream>
#include <vector>
#include <ncurses.h>
#include "point.h"
#include "setmap.h"
#include "gameset.h"
#include "block_manager.h"

extern int g_gameMap[MAP_HSIZE][MAP_WSIZE];
extern SetMap g_setMap;
extern BlockManager g_blockManager;

enum Direction {
  DIRECTION_UP, DIRECTION_RIGHT, DIRECTION_DOWN, DIRECTION_LEFT
};

class Snake {
  Point head;
  std::vector<Point> body;
  Point lastPos;
  int size;
  Direction direction;
  bool die = false;
public:
  Snake(int y=MAP_HSIZE/2, int x=MAP_WSIZE/2);
  Point getPos() const { return head; }
  int getSize() const { return size; }
  void setDirection(Direction d) { direction = d; }
  void increaseSize();
  void decreaseSize();
  void onCollisionWithGate();
  void getArrow(int key);
  void move();
  void draw() const;
  void drawEmpty(const Point& pos) const {
    g_setMap.setOnMap(SetMap::win1, pos, GAMEOBJECT_EMPTY);
  }
  bool isDie() { return die; }
  void checkSnakeState();
  void printSnake() const;
  void checkCollision();
};
#endif
