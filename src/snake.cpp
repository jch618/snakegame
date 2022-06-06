#include "../include/snake.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Snake::move()
{
  Point prevPos = head; //
  // head 이동
  if (direction == DIRECTION_LEFT) {
    head.x--;
  }
  else if (direction == DIRECTION_RIGHT) {
    head.x++;
  }
  else if (direction == DIRECTION_UP) {
    head.y--;
  }
  else {
    head.y++;
  }

  // 충돌 처리
  if (head.y < 0 || head.x < 0 || head.y >= MAP_HSIZE || head.x >= MAP_WSIZE) {
    die = true;
    return;
  }

  // body 이동
  for (auto& p : body) {
    swap(prevPos, p);
  }
  conflictCheck();

  draw(prevPos);
  // conflictCheck();
}

void Snake::getArrow(int key)
{
  switch (key) {
    case KEY_LEFT:
      direction = DIRECTION_LEFT;
      break;
    case KEY_RIGHT:
      direction = DIRECTION_RIGHT;
      break;
    case KEY_UP:
      direction = DIRECTION_UP;
      break;
    case KEY_DOWN:
      direction = DIRECTION_DOWN;
      break;
    default:
      break;
  }
}

void Snake::conflictCheck()
{
  int& headPos = g_gameMap[head.y][head.x];
  if (headPos == GAMEOBJECT_BLOCK) {
    // mvwprintw(SetMap::win2, 0, 0, "conflict with block");
    die = true;
  }
  else if (headPos == GAMEOBJECT_SNAKE_BODY) {
    // mvwprintw(SetMap::win2, 0, 0, "conflict with body");
    die = true;
  }
  else if (headPos == GAMEOBJECT_APPLE) {
    // mvwprintw(SetMap::win2, 0, 0, "conflict with apple");
    increaseSize();
  }
  else if (headPos == GAMEOBJECT_POISION) {
    // mvwprintw(SetMap::win2, 0, 0, "conflict with apple");
    decreaseSize();
  }
  else if (headPos == GAMEOBJECT_PORTAL) {

  }
}

void Snake::increaseSize()
{
  int y = body[body.size() - 2].y - body[body.size() - 1].y;
  int x = body[body.size() - 2].x - body[body.size() - 1].x;

  body.emplace_back(y, x);
  size++;
}

void Snake::decreaseSize()
{
  body.pop_back();
  size--;
}

void Snake::draw(Point prevPos) const
{
  g_setMap.setOnMap(SetMap::win1, head, GAMEOBJECT_SNAKE_HEAD);
  for (const auto& p : body) {
    g_setMap.setOnMap(SetMap::win1, p, GAMEOBJECT_SNAKE_BODY);
  }
  // temporary
  wattron(SetMap::win1, COLOR_PAIR(1));
  g_setMap.setOnMap(SetMap::win1, prevPos, GAMEOBJECT_EMPTY);
}
