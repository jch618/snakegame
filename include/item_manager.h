#include "setmap.h"
#include "item.h"
#include <deque>
#include <ctime>

#define APPLE_MAX 3
#define POISION_MAX 3
#define TIME_INTERVAL 10 * CLOCKS_PER_SEC // 10초

extern int g_gameMap[MAP_HSIZE][MAP_WSIZE];
// CLOCKS_PER_SEC 사용해서 초 계산
class ItemManager {
  clock_t prevTime;
  std::deque<Item> apples;
  std::deque<Item> poisions;
public:
  void setTime();
  void addItem(GameObject itemType);
  Item makeItem(GameObject itemType);

  /* new  */
  void drawItems() const;
  bool timeCheck();
  bool isApplesFull() const { return apples.size() >= APPLE_MAX; }
  bool isPoisionsFull() const { return poisions.size() >= POISION_MAX; }
  void checkInvalidItem();
  void generate();
};
