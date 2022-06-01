#include "gameset.h"
#include <iostream>
using namespace std;

void GameSet::gameStart()
{
  setlocale(LC_ALL, "");
  initscr();
  resize_term(SCREEN_HSIZE, SCREEN_WSIZE);
  cbreak();
  noecho(); // 입력이 화면에 나타나지 않음
  keypad(stdscr, TRUE);
  //
  nodelay(stdscr, true);
  //
  curs_set(0);
  start_color();
  init_pair(1, COLOR_GREEN, COLOR_YELLOW);
  border('*','*','*','*','*','*','*','*');
  refresh();
  // bkgd(COLOR_PAIR(1));
  // attron(COLOR_PAIR(1));

  SetMap::win1 = newwin(MAP_HSIZE, MAP_WSIZE, 0, 0);

  wbkgd(SetMap::win1, COLOR_PAIR(1));
  wrefresh(SetMap::win1);
  getch();
  //mvwprintw(SetMap::win1, y, x, " ")
  playingGame();
}

void GameSet::playingGame()
{
  Snake snake;
  // g_setMap = SetMap();
  while (1) {
    // flushinp();
    if (snake.isDie()) {
      break;
    }
    int key = getch();
    // g_setMap.refreshScreen(SetMap::win1);
    // g_setMap.delay();
    if (key == 'q') break;
    g_setMap.clearMap();
    werase(SetMap::win1);
    snake.getArrow(key);
    snake.move();
    snake.draw();
    g_setMap.refreshScreen(SetMap::win1);
    // g_setMap.printAll(SetMap::win1);
  }
  endGame();
}

void GameSet::endGame()
{
  clear();

  delwin(SetMap::win1);

  cout << "Kookmin university.\n";
  getch();
  endwin();
}
