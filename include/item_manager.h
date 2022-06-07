#include "setmap.h"
#include "item.h"
#include <vector>
#include <ctime>

#define ITEM_MAX 3
#define TIME_INTERVAL 10000 // 10초

extern int g_gameMap[MAP_HSIZE][MAP_WSIZE];
// CLOCKS_PER_SEC 사용해서 초 계산
class ItemManager {
  clock_t prevTime;
  std::vector<Item> apples;
  std::vector<Item> poisions;
public:
  ItemManager(clock_t prevTime=0): prevTime(prevTime) {}
  void setTime() { prevTime = clock(); }
  void addItem(GameObject itemType);
  Item makeItem(GameObject itemType);

  void drawItems() const;
  void checkItemState();
  bool checkTime();
  bool isItemsFull() const;
  void removeInvalidItem();
  void generate();
};
