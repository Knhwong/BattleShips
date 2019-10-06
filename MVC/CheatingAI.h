//
// Created by mfbut on 3/11/2019.
//

#ifndef BATTLESHIP_CHEATINGAI_H
#define BATTLESHIP_CHEATINGAI_H
#include "AiPlayer.h"

namespace BattleShip {
class CheatingAI  : public AiPlayer{
 public:
  CheatingAI(const GameAttributes& gameAttributes, View& view);
  virtual std::unique_ptr<Move> getMove() override;

private:
    std::vector<std::pair<int, int>> FiringCoordinates;
    int itr = 0;
    bool init = false;
};
}

#endif //BATTLESHIP_CHEATINGAI_H
