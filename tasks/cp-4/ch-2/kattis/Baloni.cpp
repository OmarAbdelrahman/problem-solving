#include <iostream>
#include <vector>
#include <algorithm>

#include "../../../../library/vector_utils.hpp"

class Baloni {
public:
  void solve() {
    int n;
    in >> n;
    std::vector<int> h(n);
    in >> h;
    int highest = *std::max_element(h.begin(), h.end());
    std::vector<int> count(highest + 1, 0);
    for (int height : h) {
      if (count[height] == 0) {
        count[height - 1] += 1;
      } else {
        count[height] -= 1;
        count[height - 1] += 1;
      }
    }
    int r = 0;
    for (int value : count) {
      r += value;
    }
    out << r << '\n';
  }

  Baloni(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};