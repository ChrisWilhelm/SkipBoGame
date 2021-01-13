// Chris Wilhelm cwilhel8
// Derek Dang ddang8
// Udochukwu Nwosu unwosu6

#include <iostream>
#include <string>
#include <algorithm>
#include "DrawPile.h"

// for live game play - must not change!
void DrawPile::display() const {
  std::cout << "[XX]/" << size();
}

void DrawPile::addCardBottom(const Card& c) {
  pile.insert(pile.begin(), c);
}

std::string DrawPile::getRand() const {
  std::string str;
  if(shuf) {
    str = "true";;
  }
  else {
    str = "false";
  }
  return str;
}
void DrawPile::shuffle() {
  std::random_shuffle(pile.begin(), pile.end());
}

void DrawPile::addOldBuild(const Card& c) {
  //increment the number of old build piles when 12 more cards
  //have been added
  if(oldBuild.size() % 12  == 0) {
    numOldBuild++;
  }

  //add the first old build pile added must be the first 
  //completed build pile
  oldBuild.insert(oldBuild.end() - 12*numOldBuild, c);
}

void DrawPile::fill() {
  for (std::vector<Card>::const_iterator it = oldBuild.cbegin(); it != oldBuild.cend(); it++) {
    addCardBottom(*it);
  }
  numOldBuild = -1;
}

bool DrawPile::isEmpty() {
  if (size() == 0) {
    return true;
  }
  return false;
}

