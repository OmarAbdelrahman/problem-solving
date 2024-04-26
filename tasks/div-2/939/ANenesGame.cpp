#include <iostream>
#include <vector>
#include "../library/vector_io.hpp"

class ANenesGame {
public:
  void solveOne() {
    int k, q;
    in >> k >> q;
    std::vector<int> a(k);
    in >> a;
    while (q--) {
      int ni;
      in >> ni;
      while (a.front() <= ni) {
        int cnt = 0;
        for (int ai : a) {
          if (ai <= ni) {
            cnt++;
          }
        }
        ni -= cnt;
      }
      out << ni << ' ';
    }
    out << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  ANenesGame(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};
