//
// Created by mfbut on 3/10/2019.
//


#include "Attack.h"


BattleShip::Attack::Attack(BattleShip::Player& attacker, int row, int col):Move(attacker), row(row), col(col){}

void BattleShip::Attack::enact(Model& model, View& view){
        AttackResult attack = moveMaker.fireAt(row, col);
        std::cout << moveMaker.getName() << "'s Firing Board\n";
        view.showResultOfAttack(moveMaker, attack);
        std::cout<<"\n" << moveMaker.getName() << "'s Placement Board\n";
        view.showPlacementBoard(moveMaker);
        if (attack.hit == true){
            std::cout << moveMaker.getName() << " hit "<<moveMaker.getOpponent().getName()<<"'s " << moveMaker.getOpponent().getBoard().at(row, col).getContents() << "!";
            if (attack.destroyed){
                std::cout<<"\n"<< moveMaker.getName() << " destroyed " << moveMaker.getOpponent().getName() << "'s " << moveMaker.getOpponent().getBoard().at(row, col).getContents() << "!";
                if (moveMaker.getOpponent().allShipsSunk()){
                    std::cout <<"\n"<< moveMaker.getName() << " won the game!";
                }
            }
            std::cout <<"\n\n";
        } else{
            std::cout  <<"Missed.\n\n";
        }
}


bool BattleShip::Attack::isValid() const{
    if (!moveMaker.getOpponent().getBoard().at(row, col).HasBeenFiredAt() && moveMaker.getOpponent().getBoard().inBounds(row, col)){
        return true;
    } else{
        return false;
    }
}

const int BattleShip::Attack::getRow() const{
    return row;
}
const int BattleShip::Attack::getCol() const{
    return col;
}