//
// Created by mfbut on 3/11/2019.
//
#include <stdexcept>
#include "CheatingAI.h"
#include "Attack.h"


BattleShip::CheatingAI::CheatingAI(const GameAttributes& gameAttributes, View& view):AiPlayer(gameAttributes, view){}



std::unique_ptr<BattleShip::Move> BattleShip::CheatingAI::getMove() {
    if (init == false){
        for (int y = 0; y < gameAttributes.getNumRows(); y++){
            for (int x = 0; x < gameAttributes.getNumCols(); x++)

                if (getOpponent().getBoard().at(y,x).containsShip()){
                    FiringCoordinates.emplace_back(std::pair<int, int>(y, x));
                }

        }
        init = true;
    }

    int row = FiringCoordinates[itr].first;
    int col = FiringCoordinates[itr].second;
    itr++;
    return std::make_unique<Attack>(*this, row, col);
}