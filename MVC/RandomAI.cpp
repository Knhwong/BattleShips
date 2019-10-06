//
// Created by mfbut on 3/11/2019.
//

#include "RandomAI.h"
#include "Attack.h"
#include "Utility.h"



BattleShip::RandomAI::RandomAI(const GameAttributes& gameAttributes, View& view): AiPlayer(gameAttributes, view){
    int row = gameAttributes.getNumRows();
    int col = gameAttributes.getNumCols();
    for (int y = 0 ; y < row; y++){
        for (int x = 0; x < col; x++){
            firingLocations.emplace_back(std::pair<int, int>(y, x));
        }
    }

}

std::unique_ptr<BattleShip::Move> BattleShip::RandomAI::getMove() {
    auto position = chooseRandom(firingLocations, randomNumberGenerator);
    std::pair<int, int> temp(*position);
    firingLocations.erase(position);


    return std::make_unique<Attack>(*this, (temp).first, (temp).second);
}