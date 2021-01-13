// Chris Wilhelm cwilhel8
// Derek Dang ddang8
// Udochukwu Nwosu unwosu6

#ifndef _HAND_H
#define _HAND_H
#include "FaceUpPile.h"
#include "Card.h"
#include <vector>

class Hand : public FaceUpPile {
  private:
  int max_size = 5;

public:
  /**
   * This function is intended to display the hand for live state
   * of the game. It displays all cards unlike the one in FaceUpPile
   * and has a constant max size of 5
   */
  virtual void display() const;

  /**
   * Adds a card in the same fashion as other addCard functions
   * @param const Card C, this is the card to be added to the end
   */
  virtual void addCard(const Card C);

  /**
   * Readds a card if it was removed but unable to be played
   * @param const Card C, the card to be readded
   * @param int i, the position to readd
   */
  void replaceCard(const Card C, int i);

  /**
   * Gets a card at the given position indicated
   * @param int position, the position of the card
   * return the card previously in the position
   */
  Card getCard(int position);

  /**
   * removes a card from the said position
   * this is only done once a move has been confirmed
   * @param int position, the position of the card played
   */
  void remove(int position);
  
};

#endif
