// Chris Wilhelm cwilhel8
// Derek Dang ddang8
// Udochukwu Nwosu unwosu6

#ifndef _PLAYER_H
#define _PLAYER_H
#include <iostream>
#include <vector>
#include <string>
#include "FaceUpPile.h"
#include "BuildPile.h"
#include "DrawPile.h"
#include "Hand.h"
class Player {

 private:
  friend class SkipBoGame;
  std::string name; //the player's name
  Hand hand; //the player's hand (1 vector of cards)
  FaceUpPile stock; //the player's stock (1 pile)
  std::vector<FaceUpPile> discard; //the player's discard piles (4 piles)

 public:
  /** Constructor for the player.
   *  @param c the name of the player
   */
  Player(std::string c);

  /** Function to get the name of a player.
   *  @return name of player
   */
  std::string getName(){ return name;}

  /** Displays the current game state
   */
  void display() const;

  /** Function to play from a player's card to a build pile
   *  @param Card play, the card to be added
   *  @param char y, the position to add the card
   *  @param vector<BuildPile> BuildPile, a reference to the buildpile vector
   *  @return true if play was made and false if play is invalid
   */
  bool playBuild(Card play, char y, std::vector<BuildPile> &BuildPile);
  
  /** Function to play from a player's hand to a discard pile
   * @param Card Play, the card to be played to discard
   * @param char y, the positin in the discard to play
   */
  void playDiscard(Card play, char y);

  /** Function to make a move for a player
   *  @param x where card is from (hand or stock)
   *  @param y where card is going (discard or build)
   *  @param BuildPile the vector of build piles (a-d)
   *  @return false if the move is to discard or stock is empty, true otherwise.
   */
  bool MakeMove(int x, char y, std::vector<BuildPile> &BuildPile);
  
  /** Function to fill a player's hand when neeeded.
   *  @param Drawpile D, a reference to the drawpile
   */
  void fillHand(DrawPile &D);

  /** 
   * converts the Players data to a string
   * used for saving the game
   * returns a string of the data for saving
   */
  std::string toString() const;
  
};

#endif
