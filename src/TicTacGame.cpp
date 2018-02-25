#include "TicTacGame.h"
#include "constants.h"

#include <iomanip>

bool TicTacGame::is_valid (int i, int j) {
  return i >= 0 && j >=0 && i < matrix.size() && j < matrix.size();
}
void TicTacGame::init () {
  std::cout << "Enter name for Player 1:" << std::endl;
  std::getline (std::cin, player_names[0]);
  std::cout << "Enter name for Player 2:" << std::endl;
  std::getline (std::cin, player_names[1]);
}

bool TicTacGame::fill_cell (int i, int j, int player) {
  if (is_valid(i, j) && matrix[i][j] != PLAYER_MATRIX_CODE[0] && matrix[i][j] != PLAYER_MATRIX_CODE[1])
    matrix[i][j] = PLAYER_MATRIX_CODE[player];
  else
    return false;
  return true;
}

bool TicTacGame::check_win (int x, int y, int player) {
  bool win = true;
  for (auto &POSITION_GENERATOR : POSITION_GENERATORS) {
    for (int i=0; i<POSITION_GENERATOR.size(); i++) {
      win = true;
      for (int j=0; j<TIC_SIZE; j++) {
        int x_pos = POSITION_GENERATOR[i][j][0] + x;
        int y_pos = POSITION_GENERATOR[i][j][1] + y;
        if (!is_valid (x_pos, y_pos) || matrix[x_pos][y_pos] != PLAYER_MATRIX_CODE[player]) win = false;
      }
      if (win) return true;
    }
  }
  return false;
}

TicTacGame::TicTacGame (const int N) : current_turn(0), finished(false), turns_left(N*N-1) {
  for (int i=0; i<N; i++) {
    matrix.push_back (std::vector<int> (N, 0));
    for (int j=0; j<N; j++) {
      matrix[i][j] = (i * N) + j + 1;
    }
  }
}

const std::string & TicTacGame::player_name (int player) const {
  return player_names[player];
}

const std::string & TicTacGame::win_message (int player) const {
  std::string str = "Congratulations " + player_names[player] + "! You have won.\n";
  return std::move(str);
}

const std::string & TicTacGame::request_message (int player) const {
  std::string str = player_names[player] + ", choose a box to place an '" + PLAYER_SYMBOL [player] + "' into: \n";
  return std::move(str);
}

void TicTacGame::pretty_print (std::ostream & os) const {
  int i=0,j=0;
  for (i=0; i<matrix.size(); i++) {
    for (j=0; j<matrix.size()-1; j++) {
      if (matrix[i][j] >= 0)
        os << " " << std::left << std::setfill(' ') << std::setw(3) << matrix[i][j] << " " << "|";
      else os << " " << std::left << std::setfill(' ') << std::setw(3) << PLAYER_CODE_TO_SYMBOL [matrix[i][j]] << " " << "|";
    }
    if (matrix[i][j] >= 0)
      os << " " << std::left << std::setfill(' ') << std::setw(3) << matrix[i][j] << " " << std::endl;
    else os << " " << std::left << std::setfill(' ') << std::setw(3) << PLAYER_CODE_TO_SYMBOL [matrix[i][j]] << " " << std::endl;
    os << "---------------------------" << std::endl;
  }
}

void TicTacGame::play_next_turn () {
  int position = -1;

  std::cout << request_message (current_turn);
  std::string number_string;
  std::getline (std::cin, number_string);
  position = std::stoi (number_string);

  int i = (position - 1) / matrix.size();
  int j = (position - 1) % matrix.size();

  if (!fill_cell (i, j, current_turn)) {
    current_turn = 1 - current_turn;
    std::cerr << "Invalid position" << std::endl;
    ++turns_left;
  }

  if (check_win (i, j, current_turn)) {
    pretty_print (std::cout);
    std::cout << win_message (current_turn);
    finished = true;
  }
  std::cout << turns_left <<std::endl;
  if (turns_left <= 0) {
    pretty_print (std::cout);
    std::cout << "Game Over! It's a tie" << std::endl;
    finished = true;
  }

  --turns_left;
  current_turn = 1 - current_turn;
}
