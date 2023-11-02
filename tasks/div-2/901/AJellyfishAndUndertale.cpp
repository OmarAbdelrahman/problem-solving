#include <bits/stdc++.h>
using namespace std;

class AJellyfishAndUndertale {
public:

  void solveOne(istream &is, ostream &os) {
    int64_t a, b, n; is >> a >> b >> n;
    vector<int64_t> x(n);
    for (int64_t& xi : x) {
      is >> xi;
    }
    for (int64_t& xi : x) {
      xi = min(xi + 1, a) - 1;
    }
    os << accumulate(begin(x), end(x), b) << '\n';
  }

  void solve(istream &is, ostream &os) {
    int t; is >> t;
    for (int i = 0; i < t; i++) {
      solveOne(is, os);
    }
  }
};