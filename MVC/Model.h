//
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_MODEL_H
#define BATTLESHIP_MODEL_H


#include <vector>
#include <memory>
#include "View.h"
#include "GameAttributes.h"
namespace BattleShip {
class Move;
class Player;
class View;
class Model {

 public:

  Player& getAttackingPlayer();
  const Player& getAttackingPlayer() const;

  Player& getDefendingPlayer();
  const Player& getDefendingPlayer() const;

  bool isGameOver() const;
  void changeTurn();
  void loadGameConfiguration(const GameAttributes& game);

  template <typename PlayerType>
  void addPlayer(View& view);
  void endGame();
  std::unique_ptr<Move> getNextMove();
  Player& getWinner();



  void SetOpponents();
 protected:
  GameAttributes gameAttributes;
  std::vector<std::unique_ptr<Player>> players;
  int playerTurn;
  bool forcedGameOver;
};

}

#include "Player.h"
#include "HumanPlayer.h"

template<typename PlayerType>
void BattleShip::Model::addPlayer(View& view) {
  std::unique_ptr<PlayerType> player = std::make_unique<PlayerType>(gameAttributes, view);
  player->initializeName(/*view.getPlayerName(player->num_instances)*/);
  player->placeShips();
  players.push_back(std::move(player));
}
#endif //BATTLESHIP_MODEL_H
