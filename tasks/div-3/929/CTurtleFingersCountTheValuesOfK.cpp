#include <bits/stdc++.h>

#include "../../../library/math_utils.hpp"
#include "../../../library/debug.hpp"
using namespace std;

class CTurtleFingersCountTheValuesOfK {
public:
  void solveOne() {
    int64_t a, b, l;
    in >> a >> b >> l;
    unordered_set<int64_t> r;
    for (int64_t x = 0; x < 30; x++) {
      int64_t ax = power(a, x);
      if (ax > l) break;
      for (int64_t y = 0; y < 30; y++) {
        int64_t by = power(b, y);
        if (by > l || ax * by > l) {
          break;
        }
        if (l % (ax * by) == 0) {
          int64_t v = l / (ax * by);
          if (v >= 0)
            r.insert(v);
        }
      }
    }
    out << size(r) << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  CTurtleFingersCountTheValuesOfK(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};