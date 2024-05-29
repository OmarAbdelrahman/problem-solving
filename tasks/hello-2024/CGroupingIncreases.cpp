#include <bits/stdc++.h>
#include "../../library/vector_utils.hpp"
using namespace std;

class CGroupingIncreases {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int> a(n);
    in >> a;
    int x = int(1e9), y = int(1e9);
    int r = 0;
    for (const int& ai : a) {
      if (x > y) {
        swap(x, y);
      }
      if (ai <= x) {
        x = ai;
      } else if (ai <= y) {
        y = ai;
      } else {
        x = ai;
        r += 1;
      }
    }
    out << r << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  CGroupingIncreases(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};