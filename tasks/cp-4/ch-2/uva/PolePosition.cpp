#include <iostream>
#include <vector>
#include <cstdio>

#include "../../../../library/pair_utils.hpp"
#include "../../../../library/vector_utils.hpp"

class PolePosition {
public:
  void solveOne(const std::vector<std::pair<int, int>>& grid) {
    std::vector<int> result(grid.size(), 0);
    for (std::size_t i = 0; i < grid.size(); i++) {
      const int at = i + grid[i].second;
      if (at < 0 || at >= grid.size() || result[at] != 0) {
        out << -1 << '\n';
        return;
      }
      result[at] = grid[i].first;
    }
    out << result << '\n';
  }

  void solve() {
    for (int n; in >> n && n != 0; ) {
      std::vector<std::pair<int, int>> grid(n);
      in >> grid;
      solveOne(grid);
    }
  }

  PolePosition(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};