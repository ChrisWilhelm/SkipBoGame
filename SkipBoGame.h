// Chris Wilhelm cwilhel8
// Derek Dang ddang8
// Udochukwu Nwosu unwosu6

#ifndef _SKIPBOGAME_H
#define _SKIPBOGAME_H
#include <iostream>
#include <vector>
#include "Player.h"
#include "DrawPile.h"
#include "FaceUpPile.h"
#include "BuildPile.h"
#include "Pile.h"
#include "Card.h"
class SkipBoGame {
private:
bool shuffle; //shuffle state of draw pile
int numPlayers; //number of players in game (2-6 allowed)
int curPlayer; //number current player. will be 0 if new game in false shuffle mode
int stockSize; //size of the stock pile
std::vector<Player> peep; //vector of players(0-5)
DrawPile draw; //draw pile
std::vector<BuildPile> build; //vector of build piles (a-d)

public:

/** Constructor for new game
 *  @param is file input stream from deck file.
 */
SkipBoGame(bool shuffle, std::istream& is);

/** Constructor for saved game.
 *  @param shuffle shuffle state of draw pile
 *  @param numPlayers the number of players
 *  @param stockSize the size of the stock pile
 *  @param s the file input stream for a saved game
 */
SkipBoGame(bool shuffle, int numPlayers, int stockSize, std::istream& s);

/**
 * This function is used to display the current game state
 */
void display() const;

/**
 * This function converts the current state of the game to a string
 * this is used for saving the game. 
 * returns a string to be added to the save file.
 */
std::string toString() const;

/** Function to deal stock cards round robin to each player
 */
void Deal();

/** Function to enter gameplay mode
 */
void PlayGame();

/** Function to save game when player requests save.
 */
void save();
};
#endif
