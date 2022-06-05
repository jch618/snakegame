#include "../include/item_manager.h"
#include <cstdlib>

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

/* NEW  */
void ItemManager::setTime()
{
  prevTime = clock();
}

void ItemManager::generate()
{
  if (!timeCheck()) {
    return;
  }
  if (!isApplesFull() && !isPoisionsFull()) {
    if (rand() % 2 == 0) {
      addItem(GAMEOBJECT_APPLE);
    }
    else {
      addItem(GAMEOBJECT_POISION);
    }
  }
  else if (isApplesFull()) {
    addItem(GAMEOBJECT_POISION);
  }
  else if (isPoisionsFull()) {
    addItem(GAMEOBJECT_APPLE);
  }
  drawItems();
}

bool ItemManager::timeCheck()
{
  if (clock() - prevTime >= TIME_INTERVAL) {
    setTime();
    return true;
  }
  return false;
}

void ItemManager::checkInvalidItem()
{
  for (const auto& apple : apples) {
    if (apple.invalid) {
      apples.pop_front();
    }
  }
  for (const auto& poision : poisions) {
    if (poision.invalid) {
      poisions.pop_front();
    }
  }
}

/*  */

void ItemManager::drawItems() const
{
  for (const auto& apple : apples) {
    apple.draw();
  }
  for (const auto& poision : poisions) {
    poision.draw();
  }
}
