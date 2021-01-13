// Chris Wilhelm cwilhel8
// Derek Dang ddang8
// Udochukwu Nwosu unwosu6

#ifndef _CARD_H
#define _CARD_H


class Card {
 public:

 /**
  * The default constructor for card
  */ 
 Card(): value(0) { }
  /**
   * the constructor for Card, if the value is out
   * of range, is set to zero
   */
 Card(int v) { value = v >= 0 && v <= 12 ? v : 0; }

  /** 
   * This function gets the value of a Card
   * returns an integer value, the number on the card
   */
 int getValue() const { return value; }
  /**
   * converts the current card to a string
   * used for saving a game
   * returns a string of the cards value
   */
 std::string toString() const;  // for printing/file saving
  /**
   * displays the current value of the card
   * used for live gameplay
   */
 void display() const;   // live game play

 private:
  int value;  // 0 for skip-bo card
};

#endif
