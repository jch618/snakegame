#include "setmap.h"
#include "item.h"
#include <vector>
#include <ctime>

// CLOCKS_PER_SEC 사용해서 초 계산
class ItemManager {
  clock_t time;
  vector<Item> items;
public:
  void addItem();
};
