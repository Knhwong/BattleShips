//
// Created by mfbut on 3/9/2019.
//

#include <algorithm>
#include <vector>
#include <cctype>
#include "StandardView.h"
#include "Utility.h"
#include "Player.h"
#include "Board.h"

BattleShip::StandardView::StandardView() {}

BattleShip::PlayerConfiguration BattleShip::StandardView::getPlayerConfiguration(){
    std::cout<< "What type of game do you want to play?\n1. Human vs Human\n2. Human vs AI\n3. AI vs AI\nYour choice: ";
    int num;
    std::cin >> num;

    if (num == 1){
        PlayerConfiguration PlayerConfig(2, 0);
        return PlayerConfig;
    } else if (num == 2){
        PlayerConfiguration PlayerConfig(1, 1);
        return PlayerConfig;
    } else{
        PlayerConfiguration PlayerConfig(0, 2);
        return PlayerConfig;
    }


}
std::string BattleShip::StandardView::getPlayerName(int i){
    std::string name;
    std::cout<< "Player " << i <<" please enter your name: ";
    std::cin >> name;
    return name;

}
ShipPlacement BattleShip::StandardView::getShipPlacement(const Player& player, char shipChar, int shipLen){
    ShipPlacement placement;
    return placement;
}



void BattleShip::StandardView::updateShipPlacementView(const Player& player){
    showPlacementBoard(player);
}
std::pair<int, int> BattleShip::StandardView::getFiringCoordinate(const BattleShip::Player& attacker){
    bool okay = false;
    std::pair<int, int> coord;
    std::cout << attacker.getName() << "'s Firing Board\n";
    showPlayersBoard(attacker.getOpponent());
    std::cout <<"\n\n"<< attacker.getName() << "'s Placement Board\n";
    showPlacementBoard(attacker);
    std::cout << attacker.getName() << ", where would you like to fire?\n";

    while(!okay) {
        std::cout << "Enter your attack coordinate in the form row col: ";
        std::cin >> coord.first >> coord.second;
        okay = true;
        if (coord.first > (attacker.getBoard().getNumRows()-1) || coord.first < 0){
            okay = false;
        }
        if (coord.second > (attacker.getBoard().getNumCols()-1)  || coord.second < 0){
            okay = false;
        }
    }


    return coord;

}
void BattleShip::StandardView::showWinner(const Player& winner){
    printBoardAsVisible(winner.getBoard());
}


void BattleShip::StandardView::showResultOfAttack(const BattleShip::Player& attacker, const BattleShip::AttackResult& attackResult){
    auto board =attacker.getOpponent().getBoard().getHiddenVersion();
    for (auto y = board.begin(); y != board.end(); y++){
        std::cout << *y;
    }
}
void BattleShip::StandardView::showPlayersBoard(const Player& player){
    printBoardAsObscured(player.getBoard());
}
void BattleShip::StandardView::showPlacementBoard(const Player& player){
    printBoardAsVisible(player.getBoard());
}

int BattleShip::StandardView::getAiChoice(){
    std::cout << "What AI do you want?\n1. Cheating AI\n2. Random AI\n3. Hunt Destroy AI\nYour choice: ";
    int out;
    std::cin >> out;
    return out;
}


void BattleShip::StandardView::printBoard(const std::vector<std::string> &board) {
    for (auto& y:board){
        std::cout << y;
    }
}
void BattleShip::StandardView::printBoardAsObscured(const BattleShip::Board &board) {
    auto print = board.getHiddenVersion();
    printBoard(print);
}
void BattleShip::StandardView::printBoardAsVisible(const BattleShip::Board &board) {
    auto print = board.getVisibleVersion();
    printBoard(print);
}
