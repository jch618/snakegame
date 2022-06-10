#include "../include/gameset.h"
#include <iostream>
#include <fstream>
using namespace std;

void GameSet::gameStart()
{
  srand(time(nullptr));

  setlocale(LC_ALL, "");
  initscr();
  resize_term(SCREEN_HSIZE, SCREEN_WSIZE);
  cbreak();
  noecho(); // 입력이 화면에 나타나지 않음
  keypad(stdscr, TRUE);
  //
  //
  curs_set(0);
  start_color();
  init_pair(1, COLOR_GREEN, COLOR_YELLOW);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  refresh();
  // bkgd(COLOR_PAIR(1));
  wattron(SetMap::win1, COLOR_PAIR(1));

  SetMap::win1 = newwin(MAP_HSIZE, MAP_WSIZE, 0, 0);
  SetMap::win2 = newwin(MAP_HSIZE, SCREEN_WSIZE - MAP_WSIZE, 0, MAP_WSIZE);
  wbkgd(SetMap::win1, COLOR_PAIR(1));
  wbkgd(SetMap::win2, COLOR_PAIR(2));
  wattron(SetMap::win1, COLOR_PAIR(2));

  refresh();
  wrefresh(SetMap::win1);
  wrefresh(SetMap::win2);

  g_setMap.printAll(SetMap::win1);
  //
  // g_setMap.printAll(SetMap::win2);
  // getch();
  playingGame();
}

void loadStage(int level, BlockManager& blockManager)
{
  string fileName("./txt/stage");
  fileName += to_string(level);
  fileName += ".txt";

  ifstream stageFile(fileName);
  //
  if (!stageFile.is_open())
    getch();

  char c;
  // '\n' 문자도 처리해주어야 한다.
  for (int i = 0; i < MAP_HSIZE+1; i++) {
    for (int j = 0; j < MAP_WSIZE+1; j++) {
      stageFile.get(c);
      switch (c) {
        case '\n':
          break;
        case '0':
          g_gameMap[i][j] = GAMEOBJECT_EMPTY;
          break;
        case '1':
          g_gameMap[i][j] = GAMEOBJECT_BLOCK;
          blockManager.addBlock(GAMEOBJECT_BLOCK, i, j);
          break;
        case '2':
          g_gameMap[i][j] = GAMEOBJECT_IMMUNE_BLOCK;
          blockManager.addBlock(GAMEOBJECT_IMMUNE_BLOCK, i, j);
          break;
      }
    }
  }
  stageFile.close();
}

void GameSet::intro()
{

}

void GameSet::playingGame()
{
  g_itemManager = ItemManager();
  g_blockManager = BlockManager();
  loadStage(gameLevel, g_blockManager);

  Snake snake;
  getch();
  nodelay(stdscr, true);
  g_setMap = SetMap();
  g_itemManager.setTime();
  g_blockManager.setTime();

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
    // g_setMap.clearMap();
    werase(SetMap::win1);
    // g_setMap.drawBorder();

    /* snake start */
    snake.getArrow(key);
    snake.move();
    // snake.draw(); // in move
    /* snake end */

    wattron(SetMap::win1, COLOR_PAIR(2));

    /* item manager start */
    g_itemManager.generate();
    /* item manager end */

    /* block_manager start */
    g_blockManager.generate();
    /* block_manager end */

    // g_setMap.printAll(SetMap::win2);
    g_setMap.refreshScreen(SetMap::win1);
  }
  nodelay(stdscr, false);
  getch();
  endGame();
}

void GameSet::endGame()
{
  clear();
  nodelay(stdscr, false);
  mvwprintw(SetMap::win1, MAP_HSIZE/2, MAP_WSIZE/2, "Kookmin university.");
  wrefresh(SetMap::win1);
  getch();

  delwin(SetMap::win1);
  endwin();
}
