#include <bits/stdc++.h>

#include "../../../library/pair_utils.hpp"
#include "../../../library/vector_utils.hpp"
using namespace std;

class ASquare {
public:
  void solveOne() {
    vector<pair<int, int>> a(4);
    in >> a;
    ranges::sort(a);
    out << (int) pow(abs(a[1].second - a[2].second), 2) << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  ASquare(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};