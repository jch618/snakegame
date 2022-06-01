#ifndef SETMAP_H
#define SETMAP_H
#include <iostream>
#include <chrono>
#include <thread>
#include <ncurses.h>
#include "point.h"
#define MAP_HSIZE 25
#define MAP_WSIZE 50

class GameSet;
enum GameObject {
  GAMEOBJECT_SNAKE_HEAD = '@',
  GAMEOBJECT_SNAKE_BODY = '+',
  GAMEOBJECT_BLOCK = 'B',
  GAMEOBEJCT_PORTAL = '*',
  GAMEOBJECT_ITEM = 'I',
  GAMEOBJECT_POISION = 'P',
};
class SetMap {
public:
  static WINDOW* win1;
  void clearMap();
  void delay();
  void refreshScreen(WINDOW* win1);
  void setOnMap(WINDOW* win, const Point& p, GameObject obj);
  void printAll(WINDOW* win1);
};

// 각각 GameObject 상수 index에 대응됨
// const char graphics[] = { '@', '+', 'B', '*', 'I', 'P'};
#endif
