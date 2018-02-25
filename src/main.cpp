#include "TicTacGame.h"

#include <iostream>
#include <string>

int main () {

  int N = 3;
  std::cout << "Enter number of squares: " << std::endl;
  std::string number_string;
  std::getline (std::cin, number_string);
  N = std::stoi (number_string);

  TicTacGame game (N);

  game.init();
  while (!game.finished) {
    game.pretty_print (std::cout);
    game.play_next_turn();
  }

  return 0;
}
