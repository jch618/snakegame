#include "setmap.h"
#include "point.h"
#include <ctime>

#define LIFE_TIME 60000

extern SetMap g_setMap;
extern int g_gameMap[MAP_HSIZE][MAP_WSIZE];

class Item {
friend class ItemManager;
  clock_t bornTime;
  bool invalid;
  GameObject type;
  Point pos;
public:
  Item(GameObject type, int y, int x);
  void checkTime();
  void checkCollision();
  void draw() const;
};
