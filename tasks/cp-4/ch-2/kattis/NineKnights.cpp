#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <cmath>
#include <algorithm>

#include "../../../../library/vector_utils.hpp"
#include "../../../../library/adhoc_utils.hpp"

/*
 * Direct validation, make sure there's exactly 9 knights before grid validation
 */
class NineKnights {
public:
  void solve() {
    std::vector<std::string> grid(N);
    in >> grid;

    int ks = 0;
    for (const auto& row : grid) {
      ks += std::count(row.begin(), row.end(), 'k');
    }

    bool ok = ks == KNIGHTS;
    for (int i = 0; i < N && ok; i++) {
      for (int j = 0; j < N && ok; j++) {
        if (grid[i][j] != 'k') {
          continue;
        }
        for_each_knight(i, j, N, N, [&](const int nx, const int ny) {
          if (grid[nx][ny] == 'k') {
            ok = false;
          }
        });
      }
    }

    out << (ok ? "valid" : "invalid") << '\n';
  }

  NineKnights(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;

  const int N = 5;
  const int KNIGHTS = 9;
};