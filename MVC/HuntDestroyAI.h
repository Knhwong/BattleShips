//
// Created by mfbut on 3/11/2019.
//

#ifndef BATTLESHIP_HUNTDESTROYAI_H
#define BATTLESHIP_HUNTDESTROYAI_H
#include <vector>
#include <algorithm>
#include "RandomAI.h"
namespace BattleShip {
class HuntDestroyAI : public RandomAI{
 public:
  HuntDestroyAI(const GameAttributes& game, View& view);
  virtual std::unique_ptr<Move> getMove() override;
 protected:
  void getSurroundingLocations(const std::pair<int, int>& center);
  std::vector<std::pair<int,int>> priorityFiringQueue;

  bool hunt = false;
  int itr = 0;
  int max = 0;

};
}

#endif //BATTLESHIP_HUNTDESTROYAI_H
