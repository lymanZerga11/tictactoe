#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <vector>
#include <unordered_map>

int TIC_SIZE = 3;

std::vector<std::vector<std::vector<int>>> LEFT_DIAGONAL_GENERATOR {
  {{-2, -2}, {-1, -1}, {0, 0}},
  {{-1, -1}, {0, 0}, {+1, +1}},
  {{0, 0}, {+1, +1}, {+2, +2}},
};

std::vector<std::vector<std::vector<int>>> RIGHT_DIAGONAL_GENERATOR {
  {{-2, +2}, {-1, +1}, {0, 0}},
  {{-1, +1}, {0, 0}, {+1, -1}},
  {{0, 0}, {+1, -1}, {+2, -2}},
};

std::vector<std::vector<std::vector<int>>> HORIZONTAL_GENERATOR {
  {{0, -2}, {0, -1}, {0, 0}},
  {{0, -1}, {0, 0}, {0, +1}},
  {{0, 0}, {0, +1}, {0, +2}},
};

std::vector<std::vector<std::vector<int>>> VERTICAL_GENERATOR {
  {{-2, 0}, {-1, 0}, {0, 0}},
  {{-1, 0}, {0, 0}, {+1, 0}},
  {{0, 0}, {+1, 0}, {+2, 0}},
};

std::vector<std::vector<std::vector<std::vector<int>>>> POSITION_GENERATORS {LEFT_DIAGONAL_GENERATOR,
  RIGHT_DIAGONAL_GENERATOR, HORIZONTAL_GENERATOR, VERTICAL_GENERATOR};

std::vector <char> PLAYER_SYMBOL {'x', 'o'};
std::vector <int> PLAYER_MATRIX_CODE {-1, -2};
std::unordered_map <int, char> PLAYER_CODE_TO_SYMBOL {{-1, 'x'}, {-2, 'o'}};

#endif
