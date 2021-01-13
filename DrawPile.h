// Chris Wilhelm cwilhel8
// Derek Dang ddang8
// Udochukwu Nwosu uwosu6

#ifndef _DRAWPILE_H
#define _DRAWPILE_H

#include <vector>
#include <iostream>
#include <string>
#include "Card.h"
#include "Pile.h"

class DrawPile : public Pile {

private:
  //vector of cards from completed build pile
  std::vector<Card> oldBuild;
  int numOldBuild = -1;
  //shuffle state of the draw pile
  bool shuf;
  
public:
  /** This is a constructor to create a draw pile.
   */
  DrawPile() {}

  /** Function to display draw pile during game play.
   */
  virtual void display() const;

  /* 
   * Adds cards to the bottom of the pile
   * @param c card to be added
   */
  void addCardBottom(const Card& c);
  
  /** Function to store the shuffle state of the draw pile.
   *  @param a the shuffle state of the draw pile
   */
  void setShuffle(bool a) { shuf = a; }

  /** Function to get the state of the draw pile
   *  @return "true" if the draw pile is shuffled and 
   *  "false" if the draw pile is not shuffled
   */
  std::string getRand() const;

  /** Function to shuffle draw pile.
   */
  void shuffle();

  /** Function to store cards from completed build piles
   *  @param c card from build pile
   */
  void addOldBuild(const Card& c);

  /** Function to fill draw pile once empty by adding
   *  the old build piles to the bottom of the deck.
   */
  void fill();
  
  /** Function to check if draw pile is empty.
   * @return true if empty, false otherwise.
   */
  bool isEmpty();
  
};

#endif
