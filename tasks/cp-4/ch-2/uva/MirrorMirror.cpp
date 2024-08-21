#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <string>
#include <type_traits>
#include <cstdio>

#include "../../../../library/matrix.hpp"

class MirrorMirror {
public:
  void solveOne(const int ci, const int n) {
    std::vector<std::string> a(n), b(n);
    for (int i = 0; i < n; i++) {
      in >> a[i] >> b[i];
    }
    matrix<char> before(a), after(b);
    print_output(ci, get_message(after, before));
  }

  std::string get_message(const matrix<char>& a, matrix<char> b) {
    if (a == b) {
      return "preserved";
    }
    for (const std::string& rotation : rotations) {
      b.rotate();
      if (a == b) {
        return rotation;
      }
    }
    b.rotate();
    b.reflect_horizontally();
    if (a == b) {
      return reflected_vertically;
    }
    for (const std::string& rotation : rotations) {
      b.rotate();
      if (a == b) {
        return reflected_vertically + " and " + rotation;
      }
    }
    return "improperly transformed";
  }

  void solve() {
    for (int i = 1, n; in >> n; i++) {
      solveOne(i, n);
    }
  }

  inline void print_output(const int ci, const std::string& msg) const {
    out << "Pattern " << ci << " was " << msg << ".\n";
  }

  MirrorMirror(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;

  const std::vector<std::string> rotations {
    "rotated 90 degrees",
    "rotated 180 degrees",
    "rotated 270 degrees",
  };
  const std::string reflected_vertically = "reflected vertically";
};