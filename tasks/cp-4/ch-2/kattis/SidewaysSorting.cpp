#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <type_traits>
#include <algorithm>
#include <cstddef>

#include "../../../../library/char_utils.hpp"
#include "../../../../library/matrix.hpp"

class SidewaysSorting {
public:
  void solve() {
    for (int r, c, endline = 0; in >> r >> c && (r || c); endline++) {
      if (endline) out << '\n';
      matrix<char> m(r, c);
      in >> m;
      m.rotate();
      std::stable_sort(m.begin(), m.end(), [](const std::vector<char>& a, const std::vector<char>& b) {
        const int n = a.size();
        for (int i = n - 1; i >= 0; i--) {
          const char ca = to_lower(a[i]);
          const char cb = to_lower(b[i]);
          if (ca != cb) {
            return ca < cb;
          }
        }
        return false;
      });
      m.rotate(false);
      m.print(out);
    }
  }

  SidewaysSorting(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};