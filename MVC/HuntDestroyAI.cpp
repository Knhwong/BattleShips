//
// Created by mfbut on 3/11/2019.
//

#include <algorithm>
#include "HuntDestroyAI.h"
#include "Attack.h"
#include "Utility.h"

BattleShip::HuntDestroyAI::HuntDestroyAI(const BattleShip::GameAttributes &game, BattleShip::View &view):RandomAI(game, view) {}

std::unique_ptr<BattleShip::Move> BattleShip::HuntDestroyAI::getMove(){
    if (!hunt) {
        auto temp = chooseRandom(firingLocations, randomNumberGenerator);
        std::pair<int, int> position(*temp);
        firingLocations.erase(temp);

        int x = (position).first;
        int y = (position).second;
        if (getOpponent().getBoard().at(x, y).containsShip() && !getOpponent().getBoard().at(x, y).HasBeenFiredAt()){
            hunt = true;
            getSurroundingLocations(position);
        }
        return std::make_unique<Attack>(*this, (position).first, (position).second);
    }





    else{
        std::pair<int, int> temp = priorityFiringQueue.at(itr);
        std::pair<int, int>position(temp.first, temp.second);

        if (getOpponent().getBoard().at(position.first, position.second).containsShip()){
            getSurroundingLocations(position);
        }



        if (itr == static_cast<int>(priorityFiringQueue.size()-1)){
            priorityFiringQueue.clear();
            itr = 0;
            hunt = false;
            return std::make_unique<Attack>(*this, (position).first, (position).second);
        }
        itr++;
        return std::make_unique<Attack>(*this, (position).first, (position).second);
    }
}

void BattleShip::HuntDestroyAI::getSurroundingLocations(const std::pair<int, int>& center){

    int hold=0;

    std::pair<int , int> Left(center.first, center.second-1);
    if (Left.second > -1 && std::find(priorityFiringQueue.begin(), priorityFiringQueue.end(), Left) == priorityFiringQueue.end()){
        if(!getOpponent().getBoard().at(Left.first, Left.second).HasBeenFiredAt()){
            priorityFiringQueue.push_back(Left);
            auto x = std::find(firingLocations.begin(), firingLocations.end(), Left);
            firingLocations.erase(x);

            max++;
        }
    }else{
        hold++;
    }

    std::pair<int , int> Top(center.first-1, center.second);
    if (Top.first > -1 && std::find(priorityFiringQueue.begin(), priorityFiringQueue.end(), Top) == priorityFiringQueue.end()){
        if (!getOpponent().getBoard().at(Top.first, Top.second).HasBeenFiredAt()){
            priorityFiringQueue.push_back(Top);
            auto x = std::find(firingLocations.begin(), firingLocations.end(), Top);
            firingLocations.erase(x);

            max++;
        }
    }else{
        hold++;
    }

    std::pair<int , int> Right(center.first, center.second+1);
    if (Right.second < getBoard().getNumCols() && std::find(priorityFiringQueue.begin(), priorityFiringQueue.end(), Right) == priorityFiringQueue.end()){
        if (!getOpponent().getBoard().at(Right.first, Right.second).HasBeenFiredAt()) {
            priorityFiringQueue.push_back(Right);
            auto x = std::find(firingLocations.begin(), firingLocations.end(), Right);
            firingLocations.erase(x);

            max++;

        }
    }else{
        hold++;
    }

    std::pair<int , int> Bottom(center.first+1, center.second);
    if (Bottom.first < getBoard().getNumRows() && std::find(priorityFiringQueue.begin(), priorityFiringQueue.end(), Bottom) == priorityFiringQueue.end()){
        if (!getOpponent().getBoard().at(Bottom.first, Bottom.second).HasBeenFiredAt()) {
            priorityFiringQueue.push_back(Bottom);
            auto x = std::find(firingLocations.begin(), firingLocations.end(), Bottom);
            firingLocations.erase(x);

            max++;
        }
    } else{
        hold++;
    }

    if (priorityFiringQueue.empty()){
        hunt = false;
    }

}