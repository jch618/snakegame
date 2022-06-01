#include "setmap.h"
#include "point.h"

extern SetMap g_setMap;

class Item {
public:
  GameObject type;
  Point pos;
  Item(GameObject type, int y, int x);
  void draw() const;
};
