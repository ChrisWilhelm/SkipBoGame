// Chris Wilhelm cwilhel8
// Derek Dang ddang8
// Udochukwu Nwosu unwosu6

#include <iostream>
#include <vector>
#include "FaceUpPile.h"
#include "Pile.h"
#include "Card.h"


void FaceUpPile::addCard(const Card& C) {
  pile.push_back(C);
}

// for live game play - must not change!
void FaceUpPile::display() const {
  if (size()) {
    pile[pile.size()-1].display();
  }
  else std::cout << "--";
  std::cout << "/" << size();
}

bool FaceUpPile::isEmpty() {
  if(this->size() == 0) {
    return true;
  }
  else {
    return false;
  }
}

int FaceUpPile::playCard(Card& C) { //used for build piles
  int val = C.getValue();
  if(pile.back().getValue() == val - 1 || val == 0) { //checks if the card to be played is zero 
    addCard(C);
    return 0;
  }
  else if (discard == true) { //if it is a discard pile, the card is just added
    addCard(C);
    return 0;
  }
  else { //otherwise it is invalid
    return 1;
  }
}




