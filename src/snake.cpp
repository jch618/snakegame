#include "../include/snake.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

Snake::Snake(int y, int x, int level): size(3), score(level, 3) {
  while (g_gameMap[y][x] != 0) {
    y = rand() % MAP_HSIZE;
    x = rand() % MAP_WSIZE;
  }
  head.y = y;
  head.x = x;
  body.emplace_back(head.y, head.x + 1);
  body.emplace_back(head.y, head.x + 2);
}

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
  /* score */
  score.setSize(size);
  /* end */
  checkSnakeState();
  draw();
  /* score */
  score.draw();
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
      /* score */
      score.incApple();
      /* end */
      break;

    case GAMEOBJECT_POISION:
      decreaseSize();
      /* score */
      score.incPoision();
      /* end */
      break;

    case GAMEOBJECT_PORTAL:
      onCollisionWithGate();
      /* score */
      score.incGate();
      /* end */
      break;
  }
}

void Snake::onCollisionWithGate()
{
  auto positions = g_blockManager.getGatePos();
  if (positions[0] == head) {
    head = positions[1];
  }
  else {
    head = positions[0];
  }
  int dy[4] = { -1, 0, 1, 0 }; // up right down left
  int dx[4] = { 0, 1, 0, -1 };
  int idx[4] = { 0, 1, 3, 2 };
  int nextY, nextX, d = (int)direction;
  for (const auto& i : idx) {
    nextY = head.y + dy[(d + i) % 4];
    nextX = head.x + dx[(d + i) % 4];
    if (nextY < 0 || nextX < 0 || nextY >= MAP_HSIZE || nextX >= MAP_HSIZE) {
      continue;
    }
    if (g_gameMap[nextY][nextX] == 0) {
      direction = (Direction)((d + i) % 4);
      //
      mvwaddch(SetMap::win2, 0, 0, (int)direction + '0');
      wrefresh(SetMap::win2);
      //
      break;
    }
  }
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
