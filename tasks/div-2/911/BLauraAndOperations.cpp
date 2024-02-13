#include <bits/stdc++.h>

using namespace std;

class BLauraAndOperations {
public:
  void solveOne() {
    int a, b, c;
    in >> a >> b >> c;
    out << 1 - (b + c) % 2 << ' ' << 1 - (a + c) % 2 << ' ' << 1 - (a + b) % 2 << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  BLauraAndOperations(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};