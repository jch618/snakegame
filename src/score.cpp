#include "../include/score.h"
#include <string>
using namespace std;

Score::Score(int level, int size)
: currGate(0), currApple(0), currPoision(0), currSize(size), level(level)
{ }

bool Score::isMissionFinished() const
{
  return (completeSize() && completeApple() && completePoision()
          && completeGate());
}

void Score::draw() const
{
  string str;
  g_setMap.mvPrint(SetMap::win2, 1, 3, "Score Board");
  str = "Level: " + to_string(level);
  g_setMap.mvPrint(SetMap::win2, 2, 3, str.c_str());
  str = "B:  " + to_string(currSize) + " / " + to_string(sizeMax[level]);
  g_setMap.mvPrint(SetMap::win2, 3, 3, str.c_str());
  str = "+:  " + to_string(currApple);
  g_setMap.mvPrint(SetMap::win2, 4, 3, str.c_str());
  str = "-:  " + to_string(currPoision);
  g_setMap.mvPrint(SetMap::win2, 5, 3, str.c_str());
  str = "G:  " + to_string(currGate);
  g_setMap.mvPrint(SetMap::win2, 6, 3, str.c_str());

  str = "B:  " + to_string(sizeMax[level]) + '(' + (completeSize() ? 'o' : ' ') + ')';
  g_setMap.mvPrint(SetMap::win3, 1, 3, str.c_str());
  str = "+:  " + to_string(appleMax[level]) + '(' + (completeApple() ? 'o' : ' ') + ')';
  g_setMap.mvPrint(SetMap::win3, 2, 3, str.c_str());
  str = "-:  " + to_string(poisionMax[level]) + '(' + (completePoision() ? 'o' : ' ') + ')';
  g_setMap.mvPrint(SetMap::win3, 3, 3, str.c_str());
  str = "G:  " + to_string(gateMax[level]) + '(' + (completeGate() ? 'o' : ' ') + ')';
  g_setMap.mvPrint(SetMap::win3, 4, 3, str.c_str());


}
