#ifndef GAMESET_H
#define GAMESET_H
#include <ncurses.h>
#include "setmap.h"
#include "snake.h"
#include "item_manager.h"
#include "block_manager.h"
#define SCREEN_HSIZE 40
#define SCREEN_WSIZE 60


// game의 설정변수들 저장
/*
 * 상단 윈도우
 * 하단 box
 *
 */
extern int g_gameMap[MAP_HSIZE][MAP_WSIZE];
extern SetMap g_setMap;
extern ItemManager g_itemManager;
extern BlockManager g_blockManager;
class GameSet {
  int gameLevel;
public:
  GameSet(int level=1): gameLevel(level) {}
  void intro();
  void playingGame();
  void gameStart();
  void clearGame();
  void endGame();
  int getGameLevel() const { return gameLevel; }
};

#endif
