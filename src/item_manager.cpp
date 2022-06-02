#include "../include/item_manager"
#include <cstdlib>

Item* ItemManager::makeItem(GameObject itemType)
{
  int y = rand() % MAP_HSIZE;
  int x = rand() % MAP_WSIZE;
  while (g_gameMap[y][x] != 0) {
    y = rand() % MAP_HSIZE;
    x = rand() % MAP_WSIZE;
  }
  return new Item(itemType, y, x);
}

void ItemManager::addItem(GameObject itemType)
{
  Item* item = makeItem(itemType);
  if (itemType == GAMEOBJECT_APPLE) {
    apples.push_back(*item);
  }
  else if (itemType == GAMEOBJECT_POISION) {
    poisions.push_back(*item);
  }
}

void ItemManager::drawItems() const
{
  for (const auto& apple : apples) {
    apple.draw();
  }
  for (const auto& poision : poisions) {
    poision.draw();
  }
}
