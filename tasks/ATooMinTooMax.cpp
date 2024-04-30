#include <bits/stdc++.h>

#include "../library/vector_io.hpp"
using namespace std;

class ATooMinTooMax {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int> a(n);
    in >> a;
    sort(begin(a), end(a));
    out << 2 * (a[n - 1] + a[n - 2] - a[1] - a[0]) << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  ATooMinTooMax(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};