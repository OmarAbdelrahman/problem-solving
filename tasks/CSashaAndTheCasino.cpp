#include <bits/stdc++.h>

using namespace std;

class CSashaAndTheCasino {
public:
  void solveOne() {
    int k, x, a;
    in >> k >> x >> a;
    int low = 0, high = a;
    while (low < high) {
      int mid = low + (high - low) / 2;
    }
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  CSashaAndTheCasino(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};