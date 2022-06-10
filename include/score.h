#ifndef SCORE_H
#define SCORE_H
#include "setmap.h"

extern SetMap g_setMap;
class Score {
friend class Snake;
  const int gateMax[6] = { 0, 1, 1, 2, 2, 2 };
  const int appleMax[6] = { 0, 1, 2, 3, 4, 5 };
  const int poisionMax[6] = { 0, 1, 2, 2, 3, 4 };
  const int sizeMax[6] = { 0, 4, 5, 6, 7, 8 };
  int currGate, currApple, currPoision, currSize, level;
public:
  Score(int level, int size);
  void setSize(int size) { currSize = size; }
  void incApple() { currApple++; }
  void incPoision() { currPoision++; }
  void incGate() { currGate++; }
  void checkMission();
  bool isMissionFinished() const;
  void draw() const;
  bool completeSize() const { return currSize >= sizeMax[level]; }
  bool completeApple() const { return currApple >= appleMax[level]; }
  bool completeGate() const { return currGate >= gateMax[level]; }
  bool completePoision() const { return currPoision >= poisionMax[level]; }
};
#endif
