#include <bits/stdc++.h>

using namespace std;

class BABalancedProblemset {
public:
  void solveOne() {
    int x, n;
    in >> x >> n;
    int r = 0;
    for (int d1 = 1; d1 * d1 <= x; d1++) {
      if (x % d1) continue;
      int d2 = x / d1;
      if (n <= d2) r = max(r, d1);
      if (n <= d1) r = max(r, d2);
    }
    out << r << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  BABalancedProblemset(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};