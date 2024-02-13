#include <bits/stdc++.h>
#include "../../../../library/io_utils.hpp"
using namespace std;

class EmoogleBalance {
public:
  void solve() {
    for (int _ = 0, n; in >> n && n != 0; _++) {
      int r = 0;
      while (n--) {
        int a;
        in >> a;
        if (a) r += 1; else r -= 1;
      }
      print_case(out, _ + 1, r);
    }
  }

  EmoogleBalance(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};