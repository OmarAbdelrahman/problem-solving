#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "../../../../library/vector_utils.hpp"
#include "../../../../library/io.hpp"

/*
 * Just use std::stable_sort.
 */
class SortOfSorting {
public:
  void solve() {
    for (int n, newline = 0; in >> n && n; newline++) {
      if (newline) out << '\n';
      std::vector<std::string> names(n);
      read(in, names);
      std::stable_sort(names.begin(), names.end(), [](const std::string& a, const std::string& b) {
        return a.substr(0, 2) < b.substr(0, 2);
      });
      for (const auto& name : names) {
        out << name << '\n';
      }
    }
  }

  SortOfSorting(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};