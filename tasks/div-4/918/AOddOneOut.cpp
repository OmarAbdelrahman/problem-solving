#include <bits/stdc++.h>

using namespace std;

class AOddOneOut {
public:
  void solveOne() {
    int a, b, c;
    in >> a >> b >> c;
    out << (a ^ b ^ c) << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  AOddOneOut(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};