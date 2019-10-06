//
// Created by mfbut on 3/9/2019.
//

#include "Player.h"
#include "Move.h"
#include "GameAttributes.h"
#include "View.h"
#include "Board.h"
#include "AttackResult.h"

int BattleShip::Player::num_instances = 0;

BattleShip::Player::Player(const BattleShip::GameAttributes &x, BattleShip::View &y):id(num_instances),view(y), board(x.getNumRows(), x.getNumCols(), '*'), gameAttributes(x){
    num_instances++;
    shipHealths = gameAttributes.getShipAttributes();
}

const std::string& BattleShip::Player::getName() const{
    return name;
}
void BattleShip::Player::setName(const std::string& nam){
    name = nam;
}
const BattleShip::Board& BattleShip::Player::getBoard() const{
    return board;
}
BattleShip::Board& BattleShip::Player::getBoard(){
    return board;
}
const int BattleShip::Player::getId() const{
    return id;
}

//for hashing
bool BattleShip::Player::operator==(const Player& rhs) const{
    if (name == rhs.name && shipHealths == rhs.shipHealths){
        return true;
    } else {
        return false;
    }
}
bool BattleShip::Player::operator!=(const Player& rhs) const{
    if (name == rhs.name && shipHealths == rhs.shipHealths){
        return false;
    } else {
        return true;
    }
}

bool BattleShip::Player::allShipsSunk() const{
    for (auto itr: shipHealths){
        if (itr.second != 0){
            return false;
        }
    }
    return true;
}

BattleShip::AttackResult BattleShip::Player::fireAt(int row, int col){
    char contents = getOpponent().getBoard().at(row, col).getContents();
    auto max = gameAttributes.getShipAttributes();

    if (getOpponent().getBoard().at(row, col).containsShip() && !getOpponent().getBoard().at(row, col).HasBeenFiredAt()){
        getOpponent().shipHealths[contents]--;
        getOpponent().getBoard().at(row, col).setHasBeenFiredAt(true);

        if (getOpponent().shipHealths[contents] == 0 ){
            AttackResult AttackResult(true, true, contents);
            return AttackResult;
        } else{
            AttackResult AttackResult(true, false, contents);
            return AttackResult;
        }

    } else{
        getOpponent().getBoard().at(row, col).setHasBeenFiredAt(true);
        AttackResult AttackResult(false, false, contents);
        return AttackResult;
    }
}

BattleShip::Player& BattleShip::Player::getOpponent(){
    return *opponent;
}
const BattleShip::Player& BattleShip::Player::getOpponent() const{
    return *opponent;
}
void BattleShip::Player::setOpponent(Player& oppon){
    opponent = &oppon;
}

bool BattleShip::Player::hit(char shipChar){
    return (shipHealths[shipChar] < gameAttributes.getShipAttributes().at(shipChar));
}