#include "../include/gate.h"

void Gate::checkCollision()
{
  if (g_gameMap[pos.y][pos.x] == GAMEOBJECT_SNAKE_HEAD) {
    invalid = true;
    draw();
  }
}

void Gate::draw() const
{
  if (invalid) {
    g_setMap.setOnMap(SetMap::win1, pos, GAMEOBJECT_BLOCK);
  }
  else {
    g_setMap.setOnMap(SetMap::win1, pos, GAMEOBJECT_PORTAL);
  }
}

void Gate::checkTime()
{
  if (clock() - bornTime >= GATE_LIFE_TIME) {
    invalid = true;
    draw(); // 이걸 안하면 배열에서 안사라진다
  }
}
