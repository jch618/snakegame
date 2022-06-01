#include "snake.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Snake::move()
{
  Point prevPos = head;
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

void Snake::draw() const
{
  g_setMap.setOnMap(SetMap::win1, head, GAMEOBJECT_SNAKE_HEAD);
  for (const auto& p : body) {
    g_setMap.setOnMap(SetMap::win1, p, GAMEOBJECT_SNAKE_BODY);
  }
}
