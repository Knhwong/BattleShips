    //
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_GAMEATTRIBUTES_H
#define BATTLESHIP_GAMEATTRIBUTES_H
#include <istream>
#include <map>
namespace BattleShip {
class GameAttributes {
 public:
  GameAttributes();
  GameAttributes(int Rows, int Cols);
  GameAttributes(std::istream& in);

  int getNumRows() const;
  void setNumRows(int Rows);
  int getNumCols() const;
  void setNumCols(int Cols);

  int getNumShips() const;

  void setNumShips(int Ships);

  void setShipAttributes(char ship, int size);

  int getShipSize(const char ShipChar) const;

  const std::map<char, int>& getShipAttributes() const;

 private:
  int numRows, numCols, numShips;
  std::map<char, int> shipAttributes;
};

std::istream& operator>>(std::istream& in, GameAttributes& gameAttributes);

}
#endif //BATTLESHIP_GAMEATTRIBUTES_H


