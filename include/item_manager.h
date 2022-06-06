#include "setmap.h"
#include "item.h"
#include <deque>
#include <ctime>

#define APPLE_MAX 3
#define POISION_MAX 3
#define TIME_INTERVAL 10000 // 10초

extern int g_gameMap[MAP_HSIZE][MAP_WSIZE];
// CLOCKS_PER_SEC 사용해서 초 계산
class ItemManager {
  clock_t prevTime;
  std::deque<Item> apples;
  std::deque<Item> poisions;
public:
  // ItemManager(clock_t prevTime=0): prevTime(0) {}
  void setTime();
  void addItem(GameObject itemType);
  Item makeItem(GameObject itemType);

  void drawItems() const;
  void checkItemState();
  bool checkTime();
  bool isApplesFull() const;
  bool isPoisionsFull() const;
  void removeInvalidItem();
  void generate();
};
