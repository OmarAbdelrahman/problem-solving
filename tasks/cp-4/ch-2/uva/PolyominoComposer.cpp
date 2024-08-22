#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <type_traits>
#include <cassert>
#include <tuple>

#include "../../../../library/pair_utils.hpp"
#include "../../../../library/matrix.hpp"

/*
 * Save the stars positions of the small polyomino and map them to start from (0, 0)
 * Then go through the big composed polyomino whenever you find a star,
 *   go through the positions from the small polyomino and remove the stars from the big composed polyomino that maps
 *   to the small polyomino position, if the position of the big composed polyomino does not map or does not contain a star
 *   at this position then it is not possible to compose.
 *
 * In the end the big composed polyomino should be empty with no stars, otherwise it is not possible to compose too.
 */
class PolyominoComposer {
public:
  bool solveOne(const int n, const int m) {
    matrix<char> p1(n), p2(m);
    in >> p1;
    in >> p2;
    const std::pair<int, int> first = p2.find_first_of(STAR);
    std::vector<std::pair<int, int>> stars;
    for (int i = 0; i < p2.rows_count(); i++) {
      for (int j = 0; j < p2.cols_count(); j++) {
        if (p2[i][j] == STAR) {
          stars.emplace_back(std::make_pair(i, j) - first);
        }
      }
    }

    for (int i = 0; i < p1.rows_count(); i++) {
      for (int j = 0; j < p1.cols_count(); j++) {
        if (p1[i][j] == STAR) {
          for (const auto& star : stars) {
            const std::pair<int, int> pos = star + std::make_pair(i, j);
            if (!p1.contains_pos(pos) || p1[pos] == EMPTY) {
              return false;
            }
            p1[pos] = EMPTY;
          }
        }
      }
    }

    return p1.find_first_of(STAR).first == -1;
  }

  void solve() {
    for (int n, m; in >> n >> m && (n || m); ) {
      out << solveOne(n, m) << '\n';
    }
  }

  PolyominoComposer(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;

  const char EMPTY = '.';
  const char STAR  = '*';
};