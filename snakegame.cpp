#include <clocale>
#include <ncurses.h>
#include <iostream>
#include <chrono>
#include <thread>

#define MAPSIZE 21
char map[21][21]; // 0~ 20 0~ 20
int main()
{
  setlocale(LC_ALL, "");
  initscr();
  cbreak();
  noecho(); // 입력이 화면에 나타나지 않음
  keypad(stdscr, TRUE);

  start_color();
  init_pair(1, COLOR_GREEN, COLOR_YELLOW);
  bkgd(COLOR_PAIR(1));
  attron(COLOR_PAIR(1));

  // atron(COLOR_PAIR(1));
  // attroff
  // COLOR_PAIR(1);
  int y, x, prevY, prevX;
  y = x = 7;

  while (1) {
    using namespace std::this_thread;
    using namespace std::chrono;

    int input = getch();
    switch (input) {
      case KEY_UP:
        y--;
        break;
      case KEY_DOWN:
        y++;
        break;
      case KEY_RIGHT:
        x++;
        break;
      case KEY_LEFT:
        x--;
        break;
    }
    if (x <= 0 || y <= 0 || y > MAPSIZE || x > MAPSIZE)
      break;
    map[y][x] = '@';
    mvprintw(y, x, "@");
    mvaddch(y+5, x+5, 63);
    refresh();
    prevY = y;
    prevX = x;
    // 1 nano seconds = 10^(-9) 100ms보다 더 줄이는게 좋을 것 같다.
    sleep_for(milliseconds(500));
    // clear();
  }

  refresh();
  getch();
  endwin();

  return 0;
}
