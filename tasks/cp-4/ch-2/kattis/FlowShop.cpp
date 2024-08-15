#include <iostream>
#include <vector>
#include <algorithm>

#include "../../../../library/vector_utils.hpp"

/*
 * Tricky/Unclear problem statement:
 *   on each step you need to decide which time to add
 *   except on the first row and first column, you should know which time to add.
 */

class FlowShop {
public:
  void solve() {
    int n, m;
    in >> n >> m;
    std::vector p(n, std::vector<int>(m));
    in >> p;
    for (int i = 1; i < m; i++) {
      p[0][i] += p[0][i - 1];
    }
    for (int i = 1; i < n; i++) {
      p[i][0] += p[i - 1][0];
    }
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        p[i][j] += std::max(p[i - 1][j], p[i][j - 1]);
      }
    }
    out << p[0].back();
    for (int i = 1; i < n; i++) {
      out << ' ' << p[i].back();
    }
    out << '\n';
  }

  FlowShop(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};