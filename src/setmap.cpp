#include <memory.h>
#include "../include/setmap.h"
// #include "gameset.h"

using namespace std;
SetMap g_setMap;
int g_gameMap[MAP_HSIZE][MAP_WSIZE];
WINDOW* SetMap::win1 = nullptr;
WINDOW* SetMap::win2 = nullptr;
/* unuse */
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
  if (obj == GAMEOBJECT_EMPTY) {
    mvwaddch(win1, p.y, p.x, ' ');
  }
  else {
    mvwaddch(win1, p.y, p.x, obj);
  }
  // refresh();
  // wrefresh(win1);
  // wrefresh(win2);
}

/* unuse */
void SetMap::delay()
{
  using namespace std::this_thread;
  using namespace std::chrono;
  sleep_for(milliseconds(50));
}

void SetMap::printAll(WINDOW* win)
{
  for (int i = 0; i < MAP_HSIZE; i++) {
    for (int j = 0; j < MAP_WSIZE; j++) {
      mvwaddch(win, i, j, g_gameMap[i][j]);
    }
  }
  refresh(); // getch는 refresh를 포함한다.
  wrefresh(win);
}

void SetMap::drawBorder() const
{
  wattron(SetMap::win1, COLOR_PAIR(1));
  wborder(SetMap::win1, '*', '*', '*', '*', '*', '*', '*', '*');
  wattroff(SetMap::win1, COLOR_PAIR(1));
  wattron(SetMap::win1, COLOR_PAIR(2));
  wattron(SetMap::win2, COLOR_PAIR(2));
  wborder(SetMap::win2, '|', '|', '-', '-', '*', '*', '*', '*');
}
