//Chris Wilhelm cwilhel8
#include <string>
#include <iostream>
#include <fstream>
#include "SkipBoGame.h"
int main(int argc, char *argv[]) {
  if(argc != 5 && argc != 3) {
    std::cerr << "invalid program usage: invalid number of arguments" << std::endl;
    return 1;
  }
  //need to add case for resuming a game
  //if statement for number of args
  std::string shuf = argv[1];
  bool shuffle;
  if(shuf == "true") {
    shuffle = true;
  } else if(shuf == "false") {
    shuffle = false;
  } else {
    //add invalind argument error
    return 1;
  }
  if(argc == 5) {
    std::string num = argv[2];
    int num_Players = stoi(num);
    std::string size = argv[3];
    int stockSize = stoi(size);
    if(num_Players > 6 || num_Players < 2) {
      std::cerr << "invalid program usage: invalid num of players must be 2-6" << std::endl;
      return 1;
    }
    std::cout << "num players is " << num_Players << std::endl;
    
    if(stockSize < 1) {
      std::cerr << "invalid program usage: bad stock size" << std::endl;
      return 1;//check this
    }
    if(stockSize > 30) {
      std::cerr << "invalid program usage: bad stock size" << std::endl;
      return 1;//check this
    }
    if(stockSize > 20 && num_Players == 6) {
      std::cerr << "invalid program usage: bad stock size" << std::endl;
      return 1;//check this
    }
    std::cout << "stock size is " << stockSize << std::endl << std::endl;
    //need to add file opening
    std::ifstream s(argv[4]);
    if (!s.is_open()) {
      std::cerr << "invalid program usage: can't open deck file" << std::endl;
    } //need to add ifstream
    SkipBoGame game = SkipBoGame(shuffle, num_Players, stockSize, s);
    game.Deal();
    game.PlayGame();
  }
  if(argc == 3) {
    std::ifstream s(argv[2]);
    if (!s.is_open()) {
      std::cerr << "invalid program usage: can't open input game file" << std::endl;
      return 1; //check this
    }
    SkipBoGame game = SkipBoGame(shuffle, s);
    game.PlayGame();
  }
  return 0;
}
