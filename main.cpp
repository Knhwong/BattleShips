#include "Controller.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

int main(int argc, char** argv) {
    std::ifstream fp;
    fp.open(argv[1]);
    std::string line;

    BattleShip::GameAttributes GameAttributes;
    BattleShip::Controller Controller;
    std::map<char, int> holder;

    int count = 0;
        while (getline(fp, line)) {
            std::stringstream stream(line);
            int x;
            if (count == 0) {
                stream >> x;
                GameAttributes.setNumRows(x);
            } else if (count == 1) {
                stream >> x;
                GameAttributes.setNumCols(x);
            } else if (count == 2) {
                stream >> x;
                GameAttributes.setNumShips(x);
            } else {
                char y;
                stream >> y >> x;
                GameAttributes.setShipAttributes(y, x);
            }
            count++;
        }



    if (argc == 3){
        int seed = atoi(argv[2]);
        Controller.setupGame(GameAttributes, seed);
    } else if (argc == 2){
        Controller.setupGame(GameAttributes);
    }

    Controller.playGame();




  return 0;
}
