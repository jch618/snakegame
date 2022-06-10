#include "../include/item_manager.h"
#include <cstdlib>
#include <algorithm>
using namespace std;

ItemManager g_itemManager;
Item ItemManager::makeItem(GameObject itemType)
{
  int y = rand() % MAP_HSIZE;
  int x = rand() % MAP_WSIZE;
  while (g_gameMap[y][x] != 0) {
    y = rand() % MAP_HSIZE;
    x = rand() % MAP_WSIZE;
  }
  return Item(itemType, y, x);
}

void ItemManager::addItem(GameObject itemType)
{
  Item item = makeItem(itemType);
  if (itemType == GAMEOBJECT_APPLE) {
    apples.push_back(item);
  }
  else if (itemType == GAMEOBJECT_POISION) {
    poisions.push_back(item);
  }
}

void ItemManager::generate()
{
  /* if time went enough create item */
  checkItemState(); // check time and collision
  removeInvalidItem();
  if (checkTime()) {
    if (!isItemsFull()) {
      if (rand() % 2 == 0) {
        addItem(GAMEOBJECT_APPLE);
      }
      else {
        addItem(GAMEOBJECT_POISION);
      }
    }
  }
  drawItems();
}

bool ItemManager::isItemsFull() const
{
  return apples.size() + poisions.size() >= ITEM_MAX;
}

void ItemManager::checkItemState()
{
  for (auto& i : apples) {
    i.checkCollision();
    i.checkTime();
  }
  for (auto& i : poisions) {
    i.checkCollision();
    i.checkTime();
  }
}

bool ItemManager::checkTime()
{
  if (clock() - prevTime >= TIME_INTERVAL) {
    setTime();
    return true;
  }
  return false;
}

void ItemManager::removeInvalidItem()
{
  auto it = apples.begin();
  while (it != apples.end()) {
    if (it->invalid) {
      it = apples.erase(it);
    }
    else {
      it++;
    }
  }
  it = poisions.begin();
  while (it != poisions.end()) {
    if (it->invalid) {
      it = poisions.erase(it);
    }
    else {
      it++;
    }
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
