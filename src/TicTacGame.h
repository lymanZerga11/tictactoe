#ifndef TICTACGAME_H
#define TICTACGAME_H

#include <vector>
#include <string>
#include <iostream>

class TicTacGame {
private:
  std::vector<std::vector<int>> matrix;
  std::string player_names[2];
  int current_turn, turns_left;

  bool is_valid                         (int i, int j);
  bool fill_cell                        (int i, int j, int player);
  bool check_win                        (int i, int j, int player);
  const std::string & player_name       (int i) const;
  const std::string & win_message       (int player) const;
  const std::string & request_message   (int player) const;

public:
  bool finished;
  TicTacGame                            () = delete;
  TicTacGame                            (const int);
  void init                             ();
  void play_next_turn                   ();
  void pretty_print                     (std::ostream &) const;
};

#endif
