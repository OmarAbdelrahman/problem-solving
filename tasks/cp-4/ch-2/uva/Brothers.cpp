#include <iostream>
#include <vector>
#include <cassert>

#include "../../../../library/vector_utils.hpp"

class Brothers {
public:
  void solve() {
    for (int n, r, c, k; in >> n >> r >> c >> k; ) {
      if (!n && !r && !c && !k) {
        break;
      }
      std::vector<std::vector<int>> grid(r, std::vector<int>(c));
      in >> grid;
      auto e = [&](const int h) -> int {
        return (h + 1) % n;
      };
      for (int iter = 0; iter < k; iter++) {
        std::vector<std::vector<int>> tgrid = grid;
        for (int i = 0; i < r; i++) {
          for (int j = 0; j < c; j++) {
            for (int dx = -1; dx <= 1; dx++) {
              for (int dy = -1; dy <= 1; dy++) {
                if ((dx == 0) ^ (dy == 0)) {
                  int ni = i + dx;
                  int nj = j + dy;
                  if (ni >= 0 && ni < r && nj >= 0 && nj < c && grid[ni][nj] == e(grid[i][j])) {
                    tgrid[ni][nj] = grid[i][j];
                  }
                }
              }
            }
          }
        }
        tgrid.swap(grid);
      }
      for (const auto& row : grid) {
        out << row << '\n';
      }
    }
  }

  Brothers(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};