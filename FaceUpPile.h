// Chris Wilhelm cwilhel8
// Derek Dang ddang8
// Udochukwu Nwosu unwosu6

#ifndef _FACEUPPILE_H
#define _FACEUPPILE_H

#include <vector>
#include <iostream>
#include "Card.h"
#include "Pile.h"

class FaceUpPile : public Pile {

private:
  int max_size = 1;//used for hand, build, stock, and discard(the pile to end turn)
  //ex. hand has a max size of 1 as there can only be one card in each "pile" for the hand, but 5 total piles
  //stock has a max size of the users choice
  //build has a max size of 12 as after the number 12 is played, the pile is removed and put into a discard pile
  //discard pile is a maxsize of the deck size, as 'theoretically' one could place all cards in deck into their discard pile
  bool discard = false; //ie. order does not matter
  
protected:
  /**
   * sets the maximum size for a given pile
   * @param int i for the value of max_size
   */
  void setMaxSize(int i) {max_size = i;}

  /**
   * sets the bool on if it is a discard pile or not
   * @param bool c for the value of discard
   */
  void setDiscard(bool c) { discard = c;}
  
public:
  /**
   * This function is intended to display the current state of the game to the user.
   * For a FaceUpPile, it only displays the top card(ie last one of the vector), as 
   * that is all that is intended to be seen.
   */
  virtual void display() const;

  /**
   * Adds cards to the current pile. Add them to the end of the vector which acts as
   * the top of the pile
   * @param C which is a card of constant value
   */
  virtual void addCard(const Card &C);
  
  /**
   * This function is used for adding cards upon dealing so that the proper order is
   * maintained.
   * @param Card C which is a constant card by reference
   */
  void deal(const Card &C) { pile.push_back(C);}

  /**
   * The purpose is to get the max size of this given pile.
   * Primarily used for hand and build
   * return max_size, and interger of the maximum size
   */
  int getMaxSize() {return max_size;}

  /**
   * This function checks if the given pile is empty
   * returns true if it is empty
   */
  bool isEmpty();
  
  /**
   * This function is intended to check if the first card(ie top card) is able
   * to be played onto the new pile represented by the FaceUpPile P. If the
   * placement is valid, then the Card is added to the first position in the pile.
   * If the placement is invalid, it is checked whether the pile is a discard pile.
   * If it is a discard pile, the card is added and returns 0, if not, the function 
   * returns 1. If card is to be added, calls addCard function.
   * @param ADD THIS
   * return 0 for a proper play and 1 for improper
   */
  int playCard(Card &C);//NOTE: this cannot be used with Stock or Hand
  //this is bc Stock will never grow, ie. is at max size, and hand has max_size of 1,
  //and if it is empty, will add an additional card from the drawPile at the start of the turn

};

  
#endif
