#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <type_traits>
#include <algorithm>

#include "../../../../library/adhoc_utils.hpp"
#include "../../../../library/matrix.hpp"

/*
 * Do as described in the problem statement.
 * It will be easier if you converted the map to integers and worked with them.
 * Then go for each ring number starting from 0.
 *   on every iteration of the ring number, if the current position does not belong to a ring,
 *   check if any of the neighbors belong to the current ring iteration, if yes, then assign the current position
 *   to 'ring + 1'.
 * Positions on edges will always belong to ring 1.
 */
class Rings {
public:
  void solve() {
    int n, m;
    in >> n >> m;
    matrix<char> drawing(n, m);
    in >> drawing;

    matrix<int> tree(n, m);

    drawing.for_each_with_indices([&](const int i, const int j, const char ch) {
      tree[i][j] = ch == '.' ? 0 : -1;
    });

    int ring = 0;
    while (true) {
      bool change = false;
      tree.for_each_with_indices([&](const int i, const int j, int& value) {
        if (value != -1) return;
        if (tree.position_on_edge(i, j)) {
          change = true;
          tree[i][j] = 1;
          return;
        }
        for_each_direction(i, j, n, m, _simple_adjacent, [&](const int x, const int y) {
          if (tree[x][y] == ring) {
            change = true;
            tree[i][j] = ring + 1;
            return;
          }
        });
      });
      if (!change) {
        break;
      }
      ring += 1;
    }

    print(ring, tree);
  }

  inline void print(const int ring, matrix<int>& tree) {
    tree.for_each_with_indices([&](const int i, const int j, const int value) {
      if (value == 0) {
        out << (ring < 10 ? ".." : "...");
      } else if (value < 10) {
        if (ring < 10) out << '.' << value; else out << ".." << value;
      } else {
        if (ring < 10) out << value; else out << '.' << value;
      }
      if (j == tree.cols_count() - 1) out << '\n';
    });
  }

  Rings(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};