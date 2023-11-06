#include <bits/stdc++.h>
using namespace std;

#define _size(a) (int) (a).size()

class ATreasureChest {
public:
  void solveOne(istream& in, ostream& out) {
    int x, y, k;
    in >> x >> y >> k;
    if (x < y) {
      if (k >= y - x) {
        out << y << '\n';
      } else {
        out << y + min(y, y - k) - x << '\n';
      }
    } else {
      out << x << '\n';
    }
  }

  void solve(istream& in, ostream& out) {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne(in, out);
    }
  }
};