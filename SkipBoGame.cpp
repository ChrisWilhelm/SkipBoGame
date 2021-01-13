// Chris Wilhelm cwilhel8
// Derek Dang ddang8
// Udochukwu Nwosu unwosu6

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
//#include <ctime>
#include <cstdlib>
#include "SkipBoGame.h"


/* for live game play - must not change format!

   drawPile  build_a  build_b  build_c  build_d
   playerName  stock_0  
discards: discard_1 discard_2 discard_3 discard_4
hand: card_5 card_6 card_7 card_8 card_9
*/
void SkipBoGame::display() const {
  std::cout << "Draw: ";
  draw.display();
  std::cout << "  Build Piles: ";
  for (int j = 0; j < 4; j++) {
    build[j].display();
    std::cout << " ";
  }
  std::cout << std::endl;
  peep[curPlayer].display();
}

SkipBoGame::SkipBoGame(bool shuffle, std::istream & is) {
  //creates players and adds them to peep
  //creates maximum possible number of players, but only uses the ones needed
  Player player0("Player0"), player1("Player1"), player2("Player2"), player3("Player3"), player4("Player4"), player5("Player5");
  peep.push_back(player0);
  peep.push_back(player1);
  peep.push_back(player2);
  peep.push_back(player3);
  peep.push_back(player4);
  peep.push_back(player5);
  std::string shuf;
  is >> shuf >> numPlayers >> curPlayer;
  this->shuffle = shuffle; //overwrites shuffle based on commandline
  draw.setShuffle(shuffle); 
  std::string playerName;
  std::string pileName;
  int pileSize;
  //loops through each player initializing their hand, stock, and discards
  for (int i = 0; i < numPlayers; i++) {
    is >> playerName >> pileName >> pileSize;
    peep.at(curPlayer).stock.readIn(is, pileSize);
    is >> pileName >> pileSize;
    peep.at(curPlayer).hand.readIn(is, pileSize);
    FaceUpPile discard1;
    FaceUpPile discard2;
    FaceUpPile discard3;
    FaceUpPile discard4;
    peep[curPlayer].discard.push_back(discard1);
    peep[curPlayer].discard.push_back(discard2);
    peep[curPlayer].discard.push_back(discard3);
    peep[curPlayer].discard.push_back(discard4);
    for(int j = 0; j < 4; j++) {
      is >> pileName >> pileSize;
      peep.at(curPlayer).discard[j].readIn(is, pileSize);
    }
    curPlayer++;
    if(curPlayer == numPlayers) { //iterates over players to ensure we dont go out of bounds
      curPlayer = 0;
    }
  }
  //reads in draw pile
  is >> pileName >> pileSize;
  draw.readIn(is, pileSize);
  if(this->shuffle) {
    draw.shuffle();
  }
  //creates and reads in 4 build piles
  BuildPile build1;
  BuildPile build2;
  BuildPile build3;
  BuildPile build4;
  build.push_back(build1);
  build.push_back(build2);
  build.push_back(build3);
  build.push_back(build4);
  for(int i = 0; i < 4; i++) {
    is >> pileName >> pileSize;
    build[i].readIn(is, pileSize);
  }
  stockSize = -1; //sets stocksize to -1 since we can't garuntee to know the stock size
}

SkipBoGame::SkipBoGame(bool shuffle, int numPlayers, int stockSize, std::istream &s) : shuffle(shuffle), numPlayers(numPlayers), stockSize(stockSize) {
  //initialize a player vector
  Player player0("Player0"), player1("Player1"), player2("Player2"), player3("Player3"), player4("Player4"), player5("Player5");
  peep.push_back(player0);
  peep.push_back(player1);
  peep.push_back(player2);
  peep.push_back(player3);
  peep.push_back(player4);
  peep.push_back(player5);

  draw.readIn(s);
  //if the game is played in a true shuffle state,
  //shuffle the deck and choose a random player to be first
  draw.setShuffle(shuffle);
  if (shuffle) {
    // srand(time(0)); no seeding for this project
    curPlayer = rand()%numPlayers;
    draw.shuffle();
  } else {
    curPlayer = 0;
  }
  for(int i = 0; i < numPlayers; i++) {
    FaceUpPile discard1;
    FaceUpPile discard2;
    FaceUpPile discard3;
    FaceUpPile discard4;
    peep[i].discard.push_back(discard1);
    peep[i].discard.push_back(discard2);
    peep[i].discard.push_back(discard3);
    peep[i].discard.push_back(discard4);
  }

  BuildPile build1;
  BuildPile build2;
  BuildPile build3;
  BuildPile build4;
  build.push_back(build1);
  build.push_back(build2);
  build.push_back(build3);
  build.push_back(build4); 
}

void SkipBoGame::Deal() { //deals stock pile round robin to each player
  //done before game begins
  for(int i = 0; i < stockSize; i++) {
    for(int j = 0; j < numPlayers; j++) {
      peep.at(curPlayer).stock.deal(draw.popCard());
      if(curPlayer + 1 == numPlayers) {
        curPlayer = 0;
      }
      else {
        curPlayer++;
      }
    }
  }
}

/* for saving state - must not change format!

   shuffle numplayers currplayer
   PlayerCurp [display]
   PlayerCurp+1 [display]
   [etc for all players]
   Draw [display]
   Build_a [display]
   Build_b [display]
   Build_c [display]
   Build_d [display]
   */
std::string SkipBoGame::toString() const {
  std::stringstream result;
  int idx;
  result << draw.getRand() << " " << numPlayers << " " << curPlayer << "\n";
  for (int i = 0; i < numPlayers; ++i) {
    idx = (curPlayer+i) % numPlayers;
    result << peep[idx].toString();
  }
  result << "Draw " << draw.toString(); 
  for (int j = 0; j < 4; j++) {
    result << "Build_" << char('a'+j) << " ";
    result << build[j].toString();  
  }
  return result.str();
}

void SkipBoGame::PlayGame() {
  //while there is no winner, allow user to play
  while(!peep.at(curPlayer).stock.isEmpty()) {
    
    if (draw.isEmpty()) {
      draw.fill();
    }

    std::string userin; 
    bool psq = false;
    
    char state = 0;
    std::cout  << " >> " << peep.at(curPlayer).getName() << " turn next" << std::endl;
    std::cout <<"(p)lay, (s)ave, or (q)uit ? ";
    
    //get user input to either play, save, or quit
    while (!psq) { //loop for while the play save or quit is not valid
      std::string command;
      std::cin >> command;
      char ch = command.at(0);
	if (ch != 'p' && ch != 's' && ch != 'q') {
	  psq = false;
	  std::cout << "illegal command, try again" << std::endl << std::endl;
	  std::cout  << " >> " << peep.at(curPlayer).getName() << " turn next" << std::endl;
	  std::cout <<"(p)lay, (s)ave, or (q)uit ? ";

	} else {
	  state = ch;
	  psq = true;
	  break;
	}
    }

    switch (state) {
      case 'p':
        {
          bool turn = true;
          //Game Rule: Players draw to five at every start of turn
          peep.at(curPlayer).fillHand(draw); 
	  display();
          while(turn) { //loop for while it is still the curplayers turn
	    std::cout << "(m)ove [start] [end] or (d)raw ? ";
	    std::string m;
	    char x;
	    std::string y;
	    int xval;
            std::cin >> m;
              switch (m.at(0)) {
	      case 'm': //case for move
		    std::cin >> x >> y;
		    xval = x - '0';
		    turn = peep.at(curPlayer).MakeMove(xval, y.at(0), build);
		    //if the build pile is full, empty it
		    for (int i = 0; i < 4; i++) { //loop checks if builds are full
		      if (build.at(i).isFull()) {
		       while (!build.at(i).isEmpty()) {
		         draw.addOldBuild(build.at(i).popCard()); //if they are, added to the oldBuild Pile in draw
		       }
		       std::cout << "build pile " << y << " full, set aside" << std::endl;
		      }
		    }
                    std::cout << std::endl;
                  break;
	      case  'd': //case for draw
                  if(!peep.at(curPlayer).hand.isEmpty()) {
                    std::cout << "illegal command, try again" << std::endl; 
		    std::cout << std::endl;
                  }
                  else {
                    peep.at(curPlayer).fillHand(draw);
		    std::cout << std::endl;
                  }
                  break;
                default:
                  std::cout << "illegal command, try again" << std::endl << std::endl;;
              }

              if(peep.at(curPlayer).stock.isEmpty()) { //checks if the stock is empty after each turn
                std::cout << "GAME OVER - " <<  peep.at(curPlayer).getName() << " wins!" << std::endl;
                return;
              }
	      display(); //displays state
	      if(turn == false) { //checks if the turn is over
		break;
	      }
          }
          break;
        }
    case 's':
        {
          //prompt for user input
          std::cout << "save filename: ";
          //get save file name here
	  draw.fill(); //adds old builds if any
	  if(shuffle) { //shuffles draw if it is a shuffled game
	    draw.shuffle();
	  }
          save();
          return;
	  break;
        }
    case 'q': 
        {
          std::cout << "thanks for playing" << std::endl;
          return; 
        }
      default:
        {
          std::cout<<"illegal command, try again";
          curPlayer = curPlayer - 1;
        }
    } 
    if(curPlayer + 1 == numPlayers) { //invraments num plays without going over max
      curPlayer = 0;
    }
    else {
      curPlayer++;
    }
    std::cout<< std::endl;
  }
}

void SkipBoGame::save() {
  std::string savefile; 
  std::cin >> savefile; //reads in file name
  std::ofstream outputfile;
  outputfile.open(savefile); //opens file
  outputfile << toString(); //adds string to file
  outputfile.flush();
  outputfile.close();
}



