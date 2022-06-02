#include "setmap.h"
#include "point.h"
#include <ctime>

extern SetMap g_setMap;

class Item {
friend ItemManager;
  clock_t bornTime;
  bool invalid = false;
public:
  GameObject type;
  Point pos;
  Item(GameObject type, int y, int x);
  void timeCheck();
  void draw() const;
};
