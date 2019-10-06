//
// Created by mfbut on 3/9/2019.
//

#include <utility>
#include <iostream>
#include "HumanPlayer.h"
#include "ShipPlacement.h"
#include "Attack.h"


BattleShip::HumanPlayer::HumanPlayer(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view):Player(gameAttributes, view) {}

std::unique_ptr<BattleShip::Move> BattleShip::HumanPlayer::getMove(){
    std::pair<int, int> coord = view.getFiringCoordinate(*this);
    return std::make_unique<Attack>(*this, coord.first, coord.second);
}

void BattleShip::HumanPlayer::initializeName(){
    name = view.getPlayerName(num_instances);
}

/*void BattleShip::HumanPlayer::placeShips() {
    auto map = gameAttributes.getShipAttributes();
    char orientation = 'p';
    for (auto itr = map.begin(); itr != map.end(); itr++){

        while (orientation != 'v' || orientation != 'h' || orientation != 'V' || orientation != 'H' ){


        std::cout<< "Your ship is" << itr->first << "Type V for Vertical, H for Horizontal\n";
        std::cin>>orientation;

        if (orientation == 'V' || orientation == 'v') {
            std::cout << "Type the Y,X coordinates with spaces, to place your ship\n";
            std::string hold;
            getline(std::cin, hold);

            int row = hold[0];
            int col = hold[2];

            int rowend = row + itr->second - 1;

            ShipPlacement shipPlacement(row, col, rowend, col);
            bool ok =board.AddShip(itr->first,shipPlacement);
            view.updateShipPlacementView(*this);


            if (ok == true){
                shipHealths[itr->first] = itr->second;
            }

        } else if (orientation == 'H' || orientation == 'h'){

            std::cout << "\nType the Y,X coordinates with spaces, to place your ship\n";
            std::string hold;
            getline(std::cin, hold);

            int row = hold[0];
            int col = hold[2];

            int colend = col + itr->second - 1;

            ShipPlacement shipPlacement(row, col, row, colend);
            bool ok =board.AddShip(itr->first,shipPlacement);

            if (ok == false){
                shipHealths[itr->first] = itr->second;
                }
            }
        }
    }
    view.showPlacementBoard(*this);
}
*/


void BattleShip::HumanPlayer::placeShips() {
    char orientation = 'p';
    ShipPlacement placement;
    view.showPlacementBoard(*this);
    bool okay = false;
    for (const auto& ship:shipHealths){
        do{
            okay = false;
            std::cout<< name <<", do you want to place " << ship.first << " horizontally or vertically?\nEnter h for horizontal or v for vertical\n";
            std::cout<<"Your choice: ";
            std::cin>>orientation;

            if (orientation == 'V' || orientation == 'v') {
                std::cout << name << ", enter the row and column you want to place "<<ship.first<<", which is " << ship.second << " long, at with a space in between row and col: ";
                int row;
                int col;
                std::cin >> row >> col;

                int rowend = row + ship.second - 1;

                ShipPlacement shipPlacement(row, col, rowend, col);
                bool ok =board.AddShip(ship.first,shipPlacement);


                if (ok == true){
                    shipHealths[ship.first] = ship.second;
                    okay = true;
                }

            } else if (orientation == 'H' || orientation == 'h'){
                std::cout << name << ", enter the row and column you want to place "<<ship.first<<", which is " << ship.second << " long, at with a space in between row and col: ";
                int row;
                int col;
                std::cin >> row >> col;

                int colend = col + ship.second - 1;

                ShipPlacement shipPlacement(row, col, row, colend);
                bool ok =board.AddShip(ship.first,shipPlacement);

                if (ok == true){
                    shipHealths[ship.first] = ship.second;
                    okay = true;
                }
            }


        }while (!okay);
        view.showPlacementBoard(*this);
    }
}