//
// Created by mfbut on 3/10/2019.
//

#include "Board.h"
BattleShip::Board::Board(int numRows, int numCols, char blankChar):Rows(numRows),Cols(numCols),blankChar(blankChar){
    std::vector<Cell> Cells;
    for (int y = 0; y<Rows; y++){
        for (int x = 0; x<Cols; x++){
            Cells.emplace_back(Cell(blankChar, '*', 'X', 'O'));
        }
        boardState.emplace_back(std::vector<Cell>(Cells));
        Cells.clear();
    }
}


BattleShip::Board::Board(int numRows, int numCols):Rows(numRows), Cols(numCols), blankChar('*'){
    boardState.reserve(Rows);
    for (int y =0; y<Rows; y++){
        boardState[y].reserve(Cols);
        for (int x = 0; x<Cols; x++){
            boardState[y][x].setContents(blankChar);
        }
    }
}
bool BattleShip::Board::canPlaceShipAt(const ShipPlacement& shipPlacement) const{
    if (shipPlacement.rowStart > Rows-1 || shipPlacement.rowStart < 0){
        return false;
    }

    if (shipPlacement.rowEnd > Rows-1 || shipPlacement.rowEnd < 0){
        return false;
    }

    if (shipPlacement.colStart > Cols-1 || shipPlacement.colStart < 0){
        return false;
    }

    if (shipPlacement.colStart > Cols-1 || shipPlacement.colStart < 0){
        return false;
    }


    for (int y = shipPlacement.rowStart; y <= shipPlacement.rowEnd; y++){
        for (int x = shipPlacement.colStart; x <= shipPlacement.colEnd;x++ ){
            if (boardState[y][x].containsShip()){
                return false;
            }
        }
    }

    return true;
}

int BattleShip::Board::getNumRows() const{
    return Rows;
}
int BattleShip::Board::getNumCols() const{
    return Cols;
}

std::vector<std::string> BattleShip::Board::getHiddenVersion() const {
    std::vector<std::string> VisibleVersion;
    VisibleVersion.reserve(Rows+2);
    VisibleVersion.emplace_back(std::string());
    VisibleVersion[0].push_back(' ');
    VisibleVersion[0].push_back(' ');

    for (int p = 0; p < Cols; p++){
        VisibleVersion[0].push_back(p + '0');
        VisibleVersion[0].push_back(' ');
    }
    VisibleVersion[0].push_back('\n');

    int h = Rows;
    h++;
    for (int y = 1 ; y < h; y++){
        VisibleVersion.emplace_back(std::string());
        int hold = y;
        hold--;
        VisibleVersion[y].push_back(hold +'0');
        VisibleVersion[y].push_back(' ');
        for (int x = 0; x <Cols; x++){
            VisibleVersion[y].push_back(boardState[hold][x].getContentsIfHidden());
            VisibleVersion[y].push_back(' ');
        }
        VisibleVersion[y].push_back('\n');
    }

    return VisibleVersion;
}




std::vector<std::string> BattleShip::Board::getVisibleVersion() const{
    std::vector<std::string> VisibleVersion;
    VisibleVersion.reserve(Rows+2);
    VisibleVersion.emplace_back(std::string());
    VisibleVersion[0].push_back(' ');
    VisibleVersion[0].push_back(' ');

    for (int p = 0; p < Cols; p++){
        VisibleVersion[0].push_back(p + '0');
        VisibleVersion[0].push_back(' ');
    }
    VisibleVersion[0].push_back('\n');

    int h = Rows;
    h++;
    for (int y = 1 ; y < h; y++){
        VisibleVersion.emplace_back(std::string());
        int hold = y;
        hold--;
        VisibleVersion[y].push_back(hold +'0');
        VisibleVersion[y].push_back(' ');
        for (int x = 0; x <Cols; x++){
            VisibleVersion[y].push_back(boardState[hold][x].getContentsIfVisible());
            VisibleVersion[y].push_back(' ');
        }
        VisibleVersion[y].push_back('\n');
    }



    return VisibleVersion;
}

bool BattleShip::Board::AddShip(char shipChar, const ShipPlacement& shipPlacement){
    bool ok = canPlaceShipAt(shipPlacement);
    if (ok == false){
        return false;
    }else{
        for (int y = shipPlacement.rowStart; y <= shipPlacement.rowEnd; y++){
            for (int x = shipPlacement.colStart; x <= shipPlacement.colEnd; x++){
                boardState[y][x].setContents(shipChar);
                boardState[y][x].ship();
            }
        }
        return true;
    }
}
bool BattleShip::Board::inBounds(int row, int col) const{
    if (row > 0 && row < Rows && col > 0 && col < Cols){
        return true;
    } else {
        return false;
    }
}

BattleShip::Cell& BattleShip::Board::at(int i, int j){
    Cell& out = boardState[i][j];
    return out;
}
const BattleShip::Cell& BattleShip::Board::at(int i, int j) const{
    const Cell& out = boardState[i][j];
    return out;
}

bool BattleShip::Board::inBounds(const ShipPlacement& shipPlacement) const{
    return true;
}

bool BattleShip::Board::between(int value, int low, int high) const{
    return false;
}
bool BattleShip::Board::spacesAreEmpty(const ShipPlacement& shipPlacement) const{
    return false;
}
