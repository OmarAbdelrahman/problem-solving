#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <type_traits>
#include <algorithm>
#include <cstdio>

#include "../../../../library/adhoc_utils.hpp"
#include "../../../../library/pair_utils.hpp"
#include "../../../../library/matrix.hpp"

/*
 * Just do as told, simulation.
 * Calculate which direction you need to go when you hit a mirror.
 */
class FunHouse {
public:
  inline void print(const int ci, const matrix<char>& maze) const {
    out << "HOUSE " << ci << '\n';
    maze.print(out);
  }

  void solveOne(const int ci, const int rows, const int cols) {
    matrix<char> maze(rows, cols);
    in >> maze;
    position entry = maze.find_first_of(ENTRY);
    if (entry.second == 0) {
      move(entry, RIGHT, maze);
    } else if (entry.second == cols - 1) {
      move(entry, LEFT, maze);
    } else if (entry.first == 0) {
      move(entry, DOWN, maze);
    } else {
      move(entry, UP, maze);
    }
    print(ci, maze);
  }

  void move(position pos, const direction& dir, matrix<char>& maze) {
    if (!maze.contains_pos(pos)) return;
    char& ch = maze[pos];
    if (ch == ENTRY || ch == EMPTY) {
      move(pos + dir, dir, maze);
      return;
    }
    auto [x, y] = pos;
    if (x == 0 || x == maze.rows_count() - 1 || y == 0 || y == maze.cols_count() - 1) {
      maze[pos] = EXIT;
    } else {
      direction next = get_next_direction(dir, ch);
      move(pos + next, next, maze);
    }
  }

  direction get_next_direction(const direction& now, const char mirror) {
    if (now == RIGHT) return mirror == FORWARD_MIRROR ? UP : DOWN;
    if (now == UP) return mirror == FORWARD_MIRROR ? RIGHT : LEFT;
    if (now == LEFT) return mirror == FORWARD_MIRROR ? DOWN : UP;
    return mirror == FORWARD_MIRROR ? LEFT : RIGHT;
  }

  void solve() {
    for (int c = 1, w, l; in >> w >> l && (w || l); c++) {
      solveOne(c, l, w);
    }
  }

  FunHouse(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;

  const char ENTRY = '*';
  const char FORWARD_MIRROR = '/';
  const char BACKWARD_MIRROR = '\\';
  const char EXIT = '&';
  const char EMPTY = '.';
};