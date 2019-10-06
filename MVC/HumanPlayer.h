    //
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_HUMANPLAYER_H
#define BATTLESHIP_HUMANPLAYER_H
#include "Player.h"
#include "View.h"
#include "GameAttributes.h"
#include <iostream>
namespace BattleShip {
class Move;
class View;

class HumanPlayer : public Player{
 public:
  HumanPlayer(const BattleShip::GameAttributes& gameAttributes, View& view);
  virtual std::unique_ptr<BattleShip::Move> getMove() override;
  virtual void placeShips() override;
  virtual void initializeName() override;
 protected:
};
}

#endif //BATTLESHIP_HUMANPLAYER_H
