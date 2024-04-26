#include <bits/stdc++.h>

using namespace std;

class BSashaAndTheDrawing {
public:
  void solveOne() {
    int64_t n, k;
    in >> n >> k;
    int64_t d = 4 * n - 2;
    if (k == d) {
      out << n * 2 << '\n';
    } else {
      out << (k % 2 == 0 ? k / 2 : (k + 1) / 2) << '\n';
    }
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  BSashaAndTheDrawing(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};