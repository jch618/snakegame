#include "setmap.h"
#include "item.h"
#include <deque>
#include <ctime>

extern int g_gameMap[MAP_HSIZE][MAP_WSIZE];
// CLOCKS_PER_SEC 사용해서 초 계산
class ItemManager {
  clock_t time;
  std::deque<Item> apples;
  std::deque<Item> poisions;
public:
  void addItem(GameObect itemType);
  void drawItems() const;

  /* new  */
  void drawItems() const;
  bool timeCheck();
  bool isApplesFull() const;
  bool isPoisionsFull() const;
  void checkInvalidItem();
  void generate();
};
