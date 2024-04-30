#include <bits/stdc++.h>

#include "../../../library/math_utils.hpp"
using namespace std;

class AShuffleParty {
public:
  void solveTwo() {
    int n;
    in >> n;
    int p = 0;
    while (n > 0) {
      n >>= 1;
      p += 1;
    }
    out << power(2, p - 1) << '\n';
  }

  void solveOne() {
    int n;
    in >> n;
    out << (1 << int(log2(n))) << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  AShuffleParty(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};