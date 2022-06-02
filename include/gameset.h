#ifndef GAMESET_H
#define GAMESET_H
#include <ncurses.h>
#include "setmap.h"
#include "snake.h"
#define SCREEN_WSIZE 70
#define SCREEN_HSIZE 40


// game의 설정변수들 저장
/*
 * 상단 윈도우
 * 하단 box
 *
 */
extern int g_gameMap[MAP_HSIZE][MAP_WSIZE];
extern SetMap g_setMap;

class GameSet {
public:
  void intro();
  void playingGame();
  void gameStart();
  void endGame();
};

#endif