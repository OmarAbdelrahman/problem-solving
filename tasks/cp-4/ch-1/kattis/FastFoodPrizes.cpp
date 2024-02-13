#include <bits/stdc++.h>

#include "../../../../library/vector_io.hpp"
using namespace std;

class FastFoodPrizes {
public:
  void solve() {
    int nt;
    in >> nt;
    while (nt--) {
      int n, m;
      in >> n >> m;
      vector<vector<int>> p(n);
      vector<int> cash(n);
      for (int i = 0, k; i < n; i++) {
        in >> k;
        p[i] = vector<int>(k);
        in >> p[i] >> cash[i];
      }
      vector<int> t(m);
      in >> t;
      int r = 0;
      for (int i = 0; i < n; i++) {
        int which = numeric_limits<int>::max() / 2;
        for (const int& pj : p[i]) {
          which = min(which, t[pj - 1]);
        }
        for (const int& pj : p[i]) {
          t[pj - 1] -= which;
        }
        r += which * cash[i];
      }
      out << r << '\n';
    }
  }

  FastFoodPrizes(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};