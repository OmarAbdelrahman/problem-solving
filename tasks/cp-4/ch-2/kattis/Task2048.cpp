#include <iostream>
#include <vector>
#include <cassert>
#include <cstdint>
#include <algorithm>

#include "../../../../library/matrix.hpp"

/*
 * Pick a case and solve it. Either Left, Up, Right, or Down
 *  and map the board to the case that you can solve.
 *  then revert the board after solving the case.
 */
class Task20248 {
public:
  void solve() {
    matrix<int16_t> board(N);
    int dir;
    in >> board >> dir;

    if (dir == L) {
      for (int i = 0; i < N; i++) {
        compress(i, board);
      }
    } else if (dir == U) {
      board.rotate(false);
      for (int i = 0; i < N; i++) {
        compress(i, board);
      }
      board.rotate(true);
    } else if (dir == R) {
      for (int i = 0; i < N; i++) {
        std::reverse(board[i].begin(), board[i].end());
        compress(i, board);
        std::reverse(board[i].begin(), board[i].end());
      }
    } else {
      board.rotate(true);
      for (int i = 0; i < N; i++) {
        compress(i, board);
      }
      board.rotate(false);
    }

    board.print(out);
  }

  void compress(const int at, matrix<int16_t>& board) {
    int zeros = 0;
    std::vector<int16_t> non_zeros;
    for (const int16_t ai : board[at]) {
      if (ai != 0) {
        non_zeros.emplace_back(ai);
      } else {
        zeros += 1;
      }
    }
    const int n = non_zeros.size();
    std::vector<int16_t> compressed;
    for (int i = 0; i < n; i++) {
      if (i + 1 < n && non_zeros[i] == non_zeros[i + 1]) {
        compressed.emplace_back(non_zeros[i] + non_zeros[i + 1]);
        i += 1;
        zeros += 1;
      } else {
        compressed.emplace_back(non_zeros[i]);
      }
    }
    assert(zeros <= N);
    for (int i = 0; i < zeros; i++) {
      compressed.emplace_back(0);
    }
    board[at] = compressed;
  }

  Task2048(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;

  const int L = 0;
  const int U = 1;
  const int R = 2;
  const int D = 3;
  const int N = 4;
};