#ifndef BLOCK_H
#define BLOCK_H
#include "point.h"
#include "setmap.h"

extern SetMap g_setMap;
extern int g_gameMap[MAP_HSIZE][MAP_WSIZE];

class Block {
friend BlockManager;
  GameObject blockType;
  Point pos;
public:
  Block(GameObject type=GAMEOBJECT_BLOCK, int y=0, int x=0);
  void draw() const;
};
#endif
