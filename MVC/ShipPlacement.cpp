//
// Created by mfbut on 3/10/2019.
//

#include <algorithm>
#include <iostream>
#include "ShipPlacement.h"

ShipPlacement::ShipPlacement():rowStart(0),colStart(0),rowEnd(0),colEnd(0){}

ShipPlacement::ShipPlacement(int rowStart, int colStart, int rowEnd, int colEnd):rowStart(rowStart),colStart(colStart),rowEnd(rowEnd),colEnd(colEnd){}

void ShipPlacement::normalize() {
    std::cout << "Hello";
}