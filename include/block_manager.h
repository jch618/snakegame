#ifndef BLOCK_MANAGER_H
#define BLOCK_MANAGER_H
#include <vector>
#include <ctime>
#include <cstdlib>
#include "gameset.h"
#include "block.h"
#include "gate.h"

#define GATE_TIME_INTERVAL 20000

class BlockManager {
  clock_t prevTime = 0;
  std::vector<Block> blocks;
  std::vector<Block> immuneBlocks;
  std::vector<Gate> gates;
public:
  BlockManager() {}
  void setTime() { prevTime = clock(); }
  void generate();
  bool checkTime();
  void addBlock(GameObject blockType, int y, int x);
  void makeGates();
  void addGates();
  void checkGateState();
  void removeInvalidGate();
  void drawBlocks() const;
};
#endif
