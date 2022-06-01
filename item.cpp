#include "item.h"

Item::Item(GameObject type, int y, int x)
: type(type)
{
  pos.y = y;
  pos.x = x;
  if (type != GAMEOBJECT_APPLE && type != GAMEOBJECT_POISION) {
    throw -1;
  }
}

void Item::draw() const
{
  g_setMap.setOnMap(SetMap::win1, pos, type);
}
