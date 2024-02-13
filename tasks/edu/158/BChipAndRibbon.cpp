#include <bits/stdc++.h>
#include "../../../library/vector_io.hpp"

using namespace std;

class BChipAndRibbon {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int> a(n);
    in >> a;
    int64_t result = a[0] - 1;
    for (int i = 1; i < n; i++) {
      if (a[i] > a[i - 1]) {
        result += a[i] - a[i - 1];
      }
    }
    out << result << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  BChipAndRibbon(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};