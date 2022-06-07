#include "../include/item.h"

Item::Item(GameObject type, int y, int x)
: type(type), invalid(false), pos(y, x)
{
  bornTime = clock();
  if (type != GAMEOBJECT_APPLE && type != GAMEOBJECT_POISION) {
    throw -1;
  }
}

void Item::checkCollision()
{
  if (g_gameMap[pos.y][pos.x] == GAMEOBJECT_SNAKE_HEAD) {
    invalid = true;
    draw();
  }
}

void Item::draw() const
{
  if (invalid) {
    g_setMap.setOnMap(SetMap::win1, pos, GAMEOBJECT_EMPTY);
  }
  else {
    g_setMap.setOnMap(SetMap::win1, pos, type);
  }
}

void Item::checkTime()
{
  if (clock() - bornTime >= LIFE_TIME) {
    invalid = true;
    draw(); // 이걸 안하면 배열에서 안사라진다
  }
}
