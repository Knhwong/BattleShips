//
// Created by mfbut on 3/9/2019.
//
#include <utility>
#include "Utility.h"
#include "GameAttributes.h"


BattleShip::GameAttributes::GameAttributes() = default;
BattleShip::GameAttributes::GameAttributes(int Rows, int Cols):numRows(Rows), numCols(Cols){}
BattleShip::GameAttributes::GameAttributes(std::istream& in){
    in >> numRows >> numCols;
}

int BattleShip::GameAttributes::getNumRows() const{
    return numRows;
}
void BattleShip::GameAttributes::setNumRows(int Rows){
    numRows=Rows;
}
int BattleShip::GameAttributes::getNumCols() const{
    return numCols;
}
void BattleShip::GameAttributes::setNumCols(int Cols){
    numCols = Cols;
}

int BattleShip::GameAttributes::getNumShips() const{
    return numShips;
}

void BattleShip::GameAttributes::setNumShips(int Ships){
    numShips = Ships;
}

void BattleShip::GameAttributes::setShipAttributes(char ship, int size){
    shipAttributes[ship] = size;
}

int BattleShip::GameAttributes::getShipSize(const char ShipChar) const{
    return shipAttributes.at(ShipChar);

}
const std::map<char, int>& BattleShip::GameAttributes::getShipAttributes() const{
    return shipAttributes;
}

