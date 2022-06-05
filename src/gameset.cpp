#include "../include/gameset.h"
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
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  // border('*','*','*','*','*','*','*','*');
  refresh();
  // bkgd(COLOR_PAIR(1));
  // attron(COLOR_PAIR(1));

  SetMap::win1 = newwin(MAP_HSIZE, MAP_WSIZE, 0, 0);
  SetMap::win2 = newwin(MAP_HSIZE, SCREEN_WSIZE - MAP_WSIZE, 0, MAP_WSIZE);
  wbkgd(SetMap::win1, COLOR_PAIR(1));
  wbkgd(SetMap::win2, COLOR_PAIR(2));
  // box(SetMap::win1, 0, 0);
  // wattron(SetMap::win1, COLOR_PAIR(1));
  // wborder(SetMap::win1, '*', '*', '*', '*', '*', '*', '*', '*');
  // wattroff(SetMap::win1, COLOR_PAIR(1));
  // wattron(SetMap::win1, COLOR_PAIR(2));
  // wborder(SetMap::win2, '*', '*', '*', '*', '*', '*', '*', '*');
  refresh();
  wrefresh(SetMap::win1);
  wrefresh(SetMap::win2);
  getch();
  //mvwprintw(SetMap::win1, y, x, " ")
  playingGame();
}

void GameSet::intro()
{

}

void GameSet::playingGame()
{
  Snake snake;
  // g_setMap = SetMap();
  while (1) {
    if (snake.isDie()) {
      break;
    }
    int key = getch();
    // g_setMap.refreshScreen(SetMap::win1);
    // g_setMap.delay();
    if (key == 'q') break;
    if (key == '1') {
      snake.increaseSize();
      flushinp();
    }
    g_setMap.clearMap();
    werase(SetMap::win1);
    wattron(SetMap::win1, COLOR_PAIR(1));
    wborder(SetMap::win1, '*', '*', '*', '*', '*', '*', '*', '*');
    wattroff(SetMap::win1, COLOR_PAIR(1));
    wattron(SetMap::win1, COLOR_PAIR(2));
    wattron(SetMap::win2, COLOR_PAIR(2));
    wborder(SetMap::win2, '|', '|', '-', '-', '*', '*', '*', '*');
    snake.getArrow(key);
    /* snake */
    snake.move();
    
    // snake.draw(); // in move
    /* snake end */
    g_setMap.refreshScreen(SetMap::win1);
    // g_setMap.printAll(SetMap::win1);
    // flushinp();
  }
  endGame();
}

void GameSet::endGame()
{
  clear();
  nodelay(stdscr, false);

  delwin(SetMap::win1);

  cout << "Kookmin university.\n";
  getch();
  endwin();
}
