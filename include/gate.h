#ifndef GATE_H
#define GATE_H
#include <ctime>
#include <cstdlib>
#include "block.h"
#include "setmap.h"

#define GATE_LIFE_TIME 10000

extern SetMap g_setMap;
class Gate {
friend class BlockManager;
  // GameObject type;
  clock_t bornTime;
  bool invalid;
  Point pos;
public:
  Gate(int y, int x): pos(y, x), invalid(false)
                      { bornTime = clock(); }
  void checkTime();
  void checkCollision();
  void draw() const;
};
#endif
