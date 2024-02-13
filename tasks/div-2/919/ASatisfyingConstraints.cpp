#include <bits/stdc++.h>

#include "../../../library/vector_io.hpp"
using namespace std;

class ASatisfyingConstraints {
public:
  void solveOne() {
    int n;
    in >> n;
    int l = numeric_limits<int>::min();
    int r = numeric_limits<int>::max();
    unordered_map<int, bool> not_valid;
    for (int i = 0; i < n; i++) {
      int a, x;
      in >> a >> x;
      if (a == 1) l = max(l, x);
      if (a == 2) r = min(r, x);
      if (a == 3) not_valid[x] = true;
    }
    if (r < l) {
      out << 0 << '\n';
      return;
    }
    int count = r - l + 1;
    for (const auto& [v, b] : not_valid) {
      if (b && v >= l && v <= r) {
        count -= 1;
      }
    }
    out << count << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  ASatisfyingConstraints(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};