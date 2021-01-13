// Chris Wilhelm cwilhel8
// Derek Dang ddang8
// Udochukwu Nwosu unwosu6

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "FaceUpPile.h"
#include "DrawPile.h"
#include "Player.h"

Player::Player(std::string c) {
  name = c;
}
// for live game play - must not change!
void Player::display() const {
  std::cout << "Current ";
  std::cout << name << ":  Stock{0}: " ;
  stock.display();
  std::cout << std::endl;
  std::cout << "   Discards{1-4}: ";
  for (int i = 0; i < 4; ++i) {
    discard[i].display();
    std::cout << "  ";
  }
  std::cout << std::endl;
  std::cout << "   Hand{5-9}: ";
  hand.display();
  std::cout << std::endl;
}

/* saving state format - must not change!
PlayerName
Stock size
01 02 03  ...
...
Hand size
01 02 03 04 05
Discard1 size
01 02 03 04 ...
...
Discard2 size
...
Discard3 size
...
Discard4 size
...
*/
std::string Player::toString() const {
  std::stringstream result;
  result << name << "\n";
  result << "Stock " << stock.toString();
  result << "Hand " << hand.toString();
  for (int i = 0; i < 4; ++i) {
    result << "Discard" << i << " " << discard[i].toString();
  }
  return result.str();
}

bool Player::playBuild(Card play, char y, std::vector<BuildPile> &BuildPile) {
  int position = (int)y - 97; //converts to integer for index in vector
  if(BuildPile.at(position).isValid(play)){  //ensures it is a valid play
    BuildPile.at(position).addCard(play); //adds card if it is valid
    return true;
  }
  return false; //if not a valid play
}

void Player::playDiscard(Card play, char y) {
  int position = (int)y - 48; //converts to index 
  discard[position - 1].addCard(play); //adds to discard, no need to check for discard
}
bool Player::MakeMove(int x, char y, std::vector<BuildPile> &BuildPile) {
  Card play;
  //if playing from stock
  if(x == 0) {
    //if adding to a build pile
    if(y >= 'a' && y <= 'd') {
      play = stock.popCard();
      if(!playBuild(play, y, BuildPile)) {
        std::cerr << "illegal command, try again" << std::endl;
        stock.addCard(play);
      }
      if(stock.isEmpty()) { //checks if turn is over or not
	return false;
      }
    }
  }
  //if playing from discard pile
  else if ( x > 0 && x <= 4) {
    if(y >= 'a' && y <= 'd') {
      play = discard[x-1].popCard();
      if(!playBuild(play, y, BuildPile)) {
        std::cerr << "illegal command, try again" << std::endl;
        discard[x-1].addCard(play);
      }
    }
    else {
      std::cerr << "illegal command, try again" << std::endl;
    }
  }
  //if playing from hand
  else if (x <= 9 && x >= 5) {
    if(hand.size() < x - 4) {
      std::cerr << "illegal command, try again" << std::endl;
      return true;
    }
    play = hand.getCard(x - 5);
    if(y >= 'a' && y <= 'd') {
      if(!playBuild(play, y, BuildPile)) {
        std::cerr << "illegal command, try again" << std::endl;
      }
      else {
	hand.remove(x - 5); //removes card if the play was valid
      }
    }
    else if(y <= '4' && y >= '1') {
      playDiscard(play, y);
      hand.remove(x-5);
      return false;
    }
    else {
      std::cerr << "illegal command, try again" << std::endl;
    }
  }
  else {
    std::cout << "illegal command, try again" << std::endl;
  }
  return true;
}

void Player::fillHand(DrawPile &D) {
  for(int i = hand.size(); i  < 5; i++) {
    //add a card to the hand if the deck is not empty
    if(!D.isEmpty()) {
      hand.addCard(D.popCard());
    }
    //if the deck is empty fill it
    else {
      D.fill();
      //if the deck is truly filled, go back an iteration
      //to add a card to the hand
      if (!D.isEmpty()) {
        i = i - 1;
      }
    }
  }
}
