#include "../include/snake.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Snake::move()
{
  lastPos = head; //
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
    swap(lastPos, p);
  }
  checkCollision();
  checkSnakeState();
  draw();
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

void Snake::checkCollision()
{
  int& headPos = g_gameMap[head.y][head.x];
  switch (headPos) {
    case GAMEOBJECT_BLOCK:
    case GAMEOBJECT_IMMUNE_BLOCK:
    case GAMEOBJECT_SNAKE_BODY:
      die = true;
      break;

    case GAMEOBJECT_APPLE:
      increaseSize();
      break;

    case GAMEOBJECT_POISION:
      decreaseSize();
      break;

    case GAMEOBJECT_PORTAL:
      onCollisionWithGate();
      break;
  }
}

void Snake::onCollisionWithGate()
{

}

void Snake::checkSnakeState()
{
  if (size < 3) {
    die = true;
  }
}

void Snake::increaseSize()
{
  // int y = body.back().y + body[body.size() - 2].y - body[body.size() - 1].y;
  // int x = body.back().x + body[body.size() - 2].x - body[body.size() - 1].x;

  body.emplace_back(lastPos.y, lastPos.x);
  size++;
}

void Snake::decreaseSize()
{
  drawEmpty(body.back());
  body.pop_back();
  size--;
}

void Snake::draw() const
{
  g_setMap.setOnMap(SetMap::win1, head, GAMEOBJECT_SNAKE_HEAD);
  for (const auto& p : body) {
    g_setMap.setOnMap(SetMap::win1, p, GAMEOBJECT_SNAKE_BODY);
  }
  // temporary
  wattron(SetMap::win1, COLOR_PAIR(1));
  drawEmpty(lastPos);
}
