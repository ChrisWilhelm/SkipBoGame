// Chris Wilhelm cwilhel8
// Derek Dang ddang8
// Udochukwu Nwosu unwosu6

#ifndef _PILE_H
#define _PILE_H

#include <vector>
#include <string>
#include <iostream>
#include "Card.h"

class Pile {
 protected:
  std::vector<Card> pile;

 public:
  Pile() { }

  /**
   * This function gets the current size of the pile
   * returns an integer representative of the size of the pile
   */
  int size() const { return pile.size(); }

  /**
   * This function adds a card to the end of the pile
   * Note: the end of the pile acts as the top
   * @param Card C which the is the card to be added
   */
  virtual void addCard(const Card& c) { pile.push_back(c); }

  /** 
   * This function converts the current pile to a string
   * This is used for saving the game state
   * returns a string of the current pile
   */
  std::string toString() const;  // for saving state

  /**
   * This function reads in a pile from a deck file
   * and stores them into the drawpile. This function
   * is only used for a drawpile. Used for a new game
   * @param istream is, an istream to the files data
   */
  void readIn(std::istream & is);  // students to write this, companion to toString()

  /** Function to read in piles from saved games
   *  @param is file input stream to read from
   *  @param pileSize the size of the saved pile
   */
  void readIn(std::istream & is, int pileSize);

  /**
   * This function displays the current state of the game 
   */
  virtual void display() const = 0;  // for live game play, must override

  /** Function to remove a card from top of a pile
   * retuns a Card that was at the top(ie back) of the pile
   */
  Card& popCard();
};


#endif
