#include <iostream>
#include <array>
#include <algorithm>

class AChessForThree {
public:
  void solveOne() {
    int p1, p2, p3;
    in >> p1 >> p2 >> p3;
    int p = p1 + p2 + p3;
    if (p == 0) {
      out << 0 << '\n';
      return;
    }
    if (p % 2 != 0) {
      out << -1 << '\n';
    } else {
      std::array<int, 3> a = {p1, p2, p3};
      int res = 0;
      while (a[0] + a[1] != 0 && a[0] + a[2] != 0 && a[1] + a[2] != 0) {
        if (a[0] > 0) {
          res += 1;
          a[0] -= 1;
          a[2] -= 1;
        }
        if (a[1] > 0) {
          res += 1;
          a[1] -= 1;
          a[2] -= 1;
        }
        std::sort(a.begin(), a.end());
      }
      out << res << '\n';
    }
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  AChessForThree(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};