//
// Created by mfbut on 3/10/2019.
//

#include <stdexcept>
#include "Cell.h"


BattleShip::Cell::Cell(char contents, const char hiddenMarker, const char hitMarker, const char missMarker)
:contents(contents), hiddenMarker(hiddenMarker), hitMarker(hitMarker), missMarker(missMarker){}

BattleShip::Cell::Cell(char contents)
:contents(contents), hiddenMarker('*'), hitMarker('X'), missMarker('O'){}

char BattleShip::Cell::getContents() const{
    return contents;
}
void BattleShip::Cell::setContents(char value){
    contents = value;
}
char BattleShip::Cell::getContentsIfHidden() const{
    if (HasBeenFiredAt() == true && containsShip() == true){
        return 'X';
    } else if (HasBeenFiredAt() == true && containsShip() == false){
        return 'O';
    } else{
        return '*';
    }
}


char BattleShip::Cell::getContentsIfVisible() const{
    if (HasBeenFiredAt() == true && containsShip() == true){
        return 'X';
    } else if (HasBeenFiredAt() == true && containsShip() == false){
        return 'O';
    } else if (containsShip() == true && HasBeenFiredAt() == false){
        return contents;
    } else {
        return '*';
    }
}
bool BattleShip::Cell::HasBeenFiredAt() const{
    return firedAt;
}
void BattleShip::Cell::setHasBeenFiredAt(bool hasBeenFiredAt){
    firedAt = hasBeenFiredAt;
}
bool BattleShip::Cell::containsShip()const{
    return Ship;
}
void BattleShip::Cell::ship(){
    Ship = true;
}
