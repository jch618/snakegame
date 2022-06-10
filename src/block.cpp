#include "../include/block.h"

Block::Block(GameObject type, int y, int x)
: blockType(type), pos(y, x)
{}

void Block::draw() const
{
  g_setMap.setOnMap(SetMap::win1, pos, blockType);
}
