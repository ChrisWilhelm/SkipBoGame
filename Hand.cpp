// Chris Wilhelm cwilhel8
// Derek Dang ddang8
// Udochukwu Nwosu unwosu6

#include <iostream>
#include "Hand.h"
#include "FaceUpPile.h"
#include "Card.h"
#include <vector>

// for live game play - must not change!
void Hand::display() const {
  int i;
  for (i = 0; i < size(); i++) {
    pile[i].display();
    std::cout << "  ";
  }
  for ( ; i < 5; i++)
    std::cout << "--  ";
}

void Hand::addCard(const Card C) {
  pile.push_back(C);
}

Card Hand::getCard(int position) {
  Card& play = pile[position];
  return play;
}

void Hand::remove(int position) {
  pile.erase(pile.begin() + position);
}

void Hand::replaceCard(const Card C, int i) {
  pile.insert(pile.begin() + i, C);
}

