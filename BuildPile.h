// Chris Wilhelm cwilhel8
// Derek Dang ddang8
// Udochukwu Nwosu unwosu6

#ifndef _BUILDPILE_H
#define _BUILDPILE_H

#include <vector>
#include <iostream>
#include "Card.h"
#include "Pile.h"
#include "FaceUpPile.h"

class BuildPile : public FaceUpPile {

 private:
  int max_size = 12;
  bool discard = false;

 public:

  /**
   * Checks if the build pile is full. If it has 12 cards, it
   * is full.
   * returns true if it is full.
   */
  bool isFull() { return (max_size == (int)pile.size()); }
  
    /**
     * Checks if the card is able to be played onto the current pile.
     * used to ensure the order and case of skipbo card
     * @param play which is the card wanting to be added
     * returns true if the play works
     */ 
  bool isValid(Card play);
};

#endif
