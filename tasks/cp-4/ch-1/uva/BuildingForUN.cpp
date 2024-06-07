#include <iostream>
#include <string>
#include <cctype>

#include "../../../../library/char_utils.hpp"

class BuildingForUN {
public:
  void solveOne(int n) {
    out << 2 << ' ' << n << ' ' << n << '\n';
    for (int i = 0; i < n; i++)
      out << std::string(n, alphabets[i]) << '\n';

    out << '\n';
    for (int _ = 0; _ < n; _++) {
      for (int i = 0; i < n; i++) {
        out << alphabets[i];
      }
      out << '\n';
    }
  }

  void solve() {
    for (int n; in >> n; solveOne(n));
  }

  BuildingForUN(std::istream& in, std::ostream& out)
    : in(in), out(out), alphabets(CAPITAL_ALPHA + SMALL_ALPHA) { }

private:
  std::istream& in;
  std::ostream& out;

  std::string alphabets;
};