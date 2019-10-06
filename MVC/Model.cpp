//
// Created by mfbut on 3/9/2019.
//

#include <fstream>
#include <algorithm>
#include "Model.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "Move.h"

BattleShip::Player& BattleShip::Model::getAttackingPlayer(){
    return *players[playerTurn].get();
}
const BattleShip::Player& BattleShip::Model::getAttackingPlayer() const{
    return *players[playerTurn].get();
}

BattleShip::Player& BattleShip::Model::getDefendingPlayer(){
    if (playerTurn == 1){
        return *players[0].get();
    } else{
        return *players[1].get();
    }

}
const BattleShip::Player& BattleShip::Model::getDefendingPlayer() const{
    if (playerTurn == 1){
        return *players[0].get();
    } else{
        return *players[1].get();
    }
}

bool BattleShip::Model::isGameOver() const{
    return (players[playerTurn].get()->allShipsSunk());

}
void BattleShip::Model::changeTurn(){
    if (playerTurn == 0){
        playerTurn = 1;
    } else{
        playerTurn = 0;
    }
}
void BattleShip::Model::loadGameConfiguration(const GameAttributes& game){
    gameAttributes = game;
}


void BattleShip::Model::endGame(){
    std::cout<<"Hallo";
}

std::unique_ptr<BattleShip::Move> BattleShip::Model::getNextMove(){
    return getAttackingPlayer().getMove();
}

BattleShip::Player& BattleShip::Model::getWinner(){
    if (playerTurn == 1){
        return *players[0].get();
    } else{
        return *players[1].get();
    }
}

void BattleShip::Model::SetOpponents(){
    std::cout << "Hallo";
}