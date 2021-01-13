// Chris Wilhelm cwilhel8
// Derek Dang ddang8
// Udochukwu Nwosu unwosu6

#include <vector>
#include <string>
#include <iostream>
#include "Card.h"
#include "Pile.h"

// for saving game state - must not change!
std::string Pile::toString() const {
  std::string result;
  result.append(std::to_string(size()));
  result.append("\n");
  // add all the pile elements to the string, at most 20 per line
  for (int i=0; i < size(); ++i) {
    if (i % 20 == 0 && i != 0)
      result.append("\n");
    else if (i != 0)
      result.append(" ");
    result.append(pile[i].toString());
  }
  result.append("\n");
  return result;
}

Card& Pile::popCard() {
  Card& c = pile.back();
  pile.pop_back();
  return c;
}

void Pile::readIn(std::istream &is) {
  int val;
  while(is >> val) {
    Card C = Card(val);
    addCard(C);
  }
}

void Pile::readIn(std::istream& is, int pileSize) {
  /*std::string pileName;
  int pileSize;
  is >> pileName >> pileSize;*/
  for(int i = 0; i < pileSize; i++) {
    int val;
    is >> val;
    Card C = Card(val);
    addCard(C);
  }
}
