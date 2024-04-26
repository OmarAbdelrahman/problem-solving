#include <bits/stdc++.h>

#include "../../../library/vector_io.hpp"
using namespace std;

class ATurtlePuzzleRearrangeAndNegate {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int> a(n);
    in >> a;
    ranges::sort(a);
    int r = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] < 0) r += -a[i];
      else r += a[i];
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

  ATurtlePuzzleRearrangeAndNegate(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};