#include <bits/stdc++.h>
#include "../../../library/pair_io.hpp"
#include "../../../library/vector_utils.hpp"
using namespace std;

class ADistinctButtons {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<pair<int, int>> ps(n);
    in >> ps;
    vector<bool> v(D, false);
    int sx = 0, sy = 0;
    for (const auto& [x, y] : ps) {
      if (x > sx) v[1] = true;
      if (x < sx) v[3] = true;
      if (y > sy) v[0] = true;
      if (y < sy) v[2] = true;
    }
    for (const auto& b : v) {
      if (!b) {
        out << "YES" << '\n';
        return;
      }
    }
    out << "NO" << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  ADistinctButtons(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const int D = 4;
};