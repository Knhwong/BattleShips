//
// Created by mfbut on 3/10/2019.
//

#ifndef BATTLESHIP_CELL_H
#define BATTLESHIP_CELL_H

namespace BattleShip {
class Cell {
 public:
  Cell(char contents, const char hiddenMarker, const char hitMarker, const char missMarker);
  Cell(char contents);
  void setContents(char value);
  char getContentsIfHidden() const;
  char getContents() const;
  char getContentsIfVisible() const;
  bool HasBeenFiredAt() const;
  void setHasBeenFiredAt(bool hasBeenFiredAt);
  bool containsShip()const;
  void ship();
 protected:
  char contents = '*';
  bool Ship = false;
  bool firedAt = false;
  const char hiddenMarker = '*';
  const char hitMarker = 'X';
  const char missMarker = 'O';

};
}

#endif //BATTLESHIP_CELL_H
