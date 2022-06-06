#include "../include/item_manager.h"
#include <cstdlib>
#include <algorithm>
using namespace std;

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
  /* if time went enough create item */
  if (checkTime()) {
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
  }
  checkItemState();
  drawItems();
  removeInvalidItem();
}

bool ItemManager::isApplesFull() const
{
  return std::count_if(apples.begin(), apples.end(),
                       [](Item item) { return item.invalid; }) >= APPLE_MAX;
}

bool ItemManager::isPoisionsFull() const
{
  return std::count_if(poisions.begin(), poisions.end(),
                       [](Item item) { return item.invalid; }) >= POISION_MAX;
}

void ItemManager::checkItemState()
{
  for (auto& i : apples) {
    i.checkTime();
    i.checkCollision();
  }
  for (auto& i : poisions) {
    i.checkTime();
    i.checkCollision();
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

void ItemManager::removeItem(const Point& pos)
{
  auto it = apples.begin();
  while (it != apples.end()) {
    if (it->pos == pos) {
      it = apples.erase(it);
    }
    else {
      it++;
    }
  }
  it = poisions.begin();
  while (it != poisions.end()) {
    if (it->pos == pos) {
      it = poisions.erase(it);
    }
    else {
      it++;
    }
  }
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
