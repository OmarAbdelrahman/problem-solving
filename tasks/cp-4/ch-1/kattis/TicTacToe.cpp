#include <bits/stdc++.h>

#include "../../../../library/vector_utils.hpp"
#include "../../../../library/io_utils.hpp"
using namespace std;

class TicTacToe {
public:
  void solveOne() {
    vector<string> grid(N);
    in >> grid;
    int xs = 0, os = 0;
    for (const string& row : grid) {
      xs += count(begin(row), end(row), 'X');
      os += count(begin(row), end(row), 'O');
    }
    print_conditional(out, valid(xs, os, grid), {"no", "yes"});
  }

  bool valid(const int xs, const int os, const vector<string>& grid) {
    if (win(grid, 'X')) return xs == os + 1;
    if (win(grid, 'O')) return xs == os;
    return xs == os || xs == os + 1;
  }

  bool win(const vector<string>& grid, const char p) {
    for (int r = 0; r < N; r++)
      if (all_of(begin(grid[r]), end(grid[r]), [&](const char ch) { return ch == p; }))
        return true;

    for (int c = 0; c < N; c++)
      if (grid[0][c] == p && grid[1][c] == p && grid[2][c] == p)
        return true;

    if (grid[0][0] == p && grid[1][1] == p && grid[2][2] == p)
      return true;

    if (grid[0][2] == p && grid[1][1] == p && grid[2][0] == p)
      return true;

    return false;
  }

  void solve() {
    int nt;
    in >> nt;
    while (nt--) solveOne();
  }

  TicTacToe(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const int N = 3;
};