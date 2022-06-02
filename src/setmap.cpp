#include <memory.h>
#include "../include/setmap.h"
// #include "gameset.h"

using namespace std;
SetMap g_setMap;
int g_gameMap[MAP_HSIZE][MAP_WSIZE];
WINDOW* SetMap::win1 = nullptr;
WINDOW* SetMap::win2 = nullptr;
// SetMap g_setMap = SetMap();
// int g_gameMap = { 0 };
// 과제 조건: map을 txt로 구현 ->
// 1. clearMap 2. setOnMap으로 움직이는 오브젝트 위치 설정
void SetMap::clearMap()
{
  memset(g_gameMap, 0, sizeof(g_gameMap));
}

void SetMap::refreshScreen(WINDOW* win1)
{
  refresh();
  wrefresh(win1);
  wrefresh(win2);
  using namespace std::this_thread;
  using namespace std::chrono;
  sleep_for(milliseconds(100));
}

void SetMap::setOnMap(WINDOW* win, const Point& p, GameObject obj)
{
  g_gameMap[p.y][p.x] = obj;
  // test
  // cout << obj << endl;
  mvwaddch(win1, p.y, p.x, obj);
  refresh();
  wrefresh(win1);
  // mvprintw(40, 40, )
}

void SetMap::delay()
{
  using namespace std::this_thread;
  using namespace std::chrono;
  sleep_for(milliseconds(50));
}
void SetMap::printAll(WINDOW* win1)
{
  // clear();
  for (int i = 0; i < MAP_HSIZE; i++) {
    for (int j = 0; j < MAP_WSIZE; j++) {
      mvwaddch(win1, i, j, g_gameMap[i][j]);
      // cout << g_gameMap[i][j] << ' ';
    }
    // cout << endl;
  }
  refresh(); // getch는 refresh를 포함한다.
  wrefresh(win1);

}
