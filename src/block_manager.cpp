#include "../include/block_manager.h"
//
#include <string>
#include <algorithm>
using namespace std;
//
BlockManager g_blockManager;
std::vector<Point> BlockManager::getGatePos() const
{
  return vector<Point>{ gates[0].pos, gates[1].pos };
}

void BlockManager::addBlock(GameObject blockType, int y, int x) {
  if (blockType == GAMEOBJECT_BLOCK) {
    blocks.emplace_back(blockType, y, x);
  }
  else if (blockType == GAMEOBJECT_IMMUNE_BLOCK) {
    immuneBlocks.emplace_back(blockType, y, x);
  }
}

// gate 위치 지정 && 객체 생성
void BlockManager::addGates()
{
  int idx1 = rand() % blocks.size();
  int idx2 = rand() % blocks.size();
  while (idx2 == idx1) { // idx1 != idx2
    idx2 = rand() % blocks.size();
  }
  if (idx1 > idx2) {
    swap(idx1, idx2);
  }
  gates.emplace_back(blocks[idx1].pos.y, blocks[idx1].pos.x);
  //
  // string str = to_string(blocks[idx1].pos.y);
  // str += "," + to_string(blocks[idx1].pos.x);
  // mvwprintw(SetMap::win2, 0, 0, str.c_str());
  // wrefresh(SetMap::win2);
  //
  gates.emplace_back(blocks[idx2].pos.y, blocks[idx2].pos.x);
  // 뒤의 것부터 먼저 지워야 함
  blocks.erase(blocks.begin() + idx2);
  blocks.erase(blocks.begin() + idx1);
}

void BlockManager::generate()
{
  //
  mvwprintw(SetMap::win2, 2, 0, "generate");
  wrefresh(SetMap::win2);
  //
  checkGateState(); // check time and collision
  removeInvalidGate();
  if (checkTime()) {
    //
    mvwprintw(SetMap::win2, 1, 0, "check");
    wrefresh(SetMap::win2);
    //
    addGates();
  }
  drawBlocks();
}

void BlockManager::checkGateState()
{
  for (auto& g : gates) {
    g.checkTime();
  }
}

void BlockManager::removeInvalidGate()
{
  if (!gates.empty() && gates[0].invalid) {
    addBlock(GAMEOBJECT_BLOCK, gates[0].pos.y, gates[0].pos.x);
    addBlock(GAMEOBJECT_BLOCK, gates[1].pos.y, gates[1].pos.x);
    gates.pop_back();
    gates.pop_back();
  }
}

bool BlockManager::checkTime()
{
  if (clock() - prevTime >= GATE_TIME_INTERVAL) {
    setTime();
    return true;
  }
  return false;
}

void BlockManager::drawBlocks() const
{
  for (const auto& block : blocks) {
    block.draw();
  }
  for (const auto& immuneBlock : immuneBlocks) {
    immuneBlock.draw();
  }
  for (const auto& gate : gates) {
    gate.draw();
  }
}
