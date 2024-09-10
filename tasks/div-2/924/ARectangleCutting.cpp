#include <bits/stdc++.h>

using namespace std;

class ARectangleCutting {
public:
  void solveOne() {
    int a, b;
    in >> a >> b;
    if (a % 2 == 0 && a / 2 != b) {
      out << "YES" << '\n';
      return;
    }
    if (b % 2 == 0 && b / 2 != a) {
      out << "YES" << '\n';
      return;
    }
    out << "NO" << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  ARectangleCutting(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};