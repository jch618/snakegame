#ifndef SETMAP_H
#define SETMAP_H
#include <iostream>
#include <chrono>
#include <thread>
#include <ncurses.h>
#include <vector>
#include "point.h"
#define MAP_HSIZE 30
#define MAP_WSIZE 40
#define WIN2_HSIZE 10
#define WIN2_WSIZE 19

class GameSet;
class Item;
class ItemManager;
class BlockManager;
enum GameObject {
  GAMEOBJECT_SNAKE_HEAD = '@',
  GAMEOBJECT_SNAKE_BODY = '+',
  GAMEOBJECT_BLOCK = 'B',
  GAMEOBJECT_IMMUNE_BLOCK = 'b',
  GAMEOBJECT_PORTAL = '*',
  GAMEOBJECT_APPLE = 'I',
  GAMEOBJECT_POISION = 'P',
  GAMEOBJECT_EMPTY = 0
};
class SetMap {
public:
  static WINDOW* win1;
  static WINDOW* win2;
  static WINDOW* win3;
  void clearMap();
  void refreshScreen();
  void setOnMap(WINDOW* win, const Point& p, GameObject obj);
  void printAll(WINDOW* win1);
  void drawBorder() const;
  void mvPrint(WINDOW* win, int y, int x, const char* chars) const;
  void mvAddChar(WINDOW* win, int y, int x, char c) const;

};
// void loadStage(int level);


#endif
