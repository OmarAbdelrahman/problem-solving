#include <iostream>
#include <string>
#include <vector>

#include "../../../../library/vector_utils.hpp"

class EpigDanceOff {
public:
  void solve() {
    int n, m;
    in >> n >> m;
    std::vector<std::string> grid(n, std::string(m, '.'));
    in >> grid;
    int r = 0;
    for (int i = 0; i < m; i++) {
      bool ok = true;
      for (int j = 0; j < n && ok; j++) {
        ok &= grid[j][i] == '_';
      }
      r += int(ok);
    }
    out << r + 1 << '\n';
  }

  EpigDanceOff(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};