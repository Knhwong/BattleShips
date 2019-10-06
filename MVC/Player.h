//
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H
#include <functional>
#include <string>
#include <memory>
#include <map>
#include "Board.h"
#include "GameAttributes.h"

namespace BattleShip {
class View; //forward declaration
class Move;
class Model;
class Board;
class GameAttributes;
 class    AttackResult;
class Player {
 public:
  Player(const GameAttributes& gameAttributes, View& view);

  const std::string& getName() const;
  void setName(const std::string& nam);
  const Board& getBoard() const;
  Board& getBoard();
  const int getId() const;
  //for hashing
  bool operator==(const Player& rhs) const;
  bool operator!=(const Player& rhs) const;
  virtual std::unique_ptr<BattleShip::Move> getMove() = 0;
  virtual void placeShips() = 0;
  virtual void initializeName() = 0;
  virtual bool allShipsSunk() const;
  virtual BattleShip::AttackResult fireAt(int row, int col);
  Player& getOpponent();
  const Player& getOpponent() const;
  void setOpponent(Player& oppon);

  static int num_instances;


protected:
  virtual bool hit(char shipChar);
  const int id;
  std::string name;
  std::map<char, int> shipHealths;
  View& view;
  Board board;
  Player* opponent;
  GameAttributes gameAttributes;
};

}

namespace std{
template <>
class hash<BattleShip::Player&>{
  std::size_t operator()(const BattleShip::Player& player) const{
    return player.getId();
  }
};
}


#endif //BATTLESHIP_PLAYER_H
