#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "../../../../library/date_t.hpp"
#include "../../../../library/pair_utils.hpp"
#include "../../../../library/vector_utils.hpp"

/*
 * Sorting. Use std::sort was `cmp` or `operator <`
 */
class Birthdates {
public:
  void solve() {
    int n;
    in >> n;
    std::vector<std::pair<date_t, std::string>> v(n);
    for (auto& vi : v) {
      in >> vi.second >> vi.first;
    }
    std::sort(v.begin(), v.end());
    out << v.back().second << '\n';
    out << v.front().second << '\n';
  }

  Birthdates(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};