#include <bits/stdc++.h>

using namespace std;

class ADivisibilityProblem {
public:
  void solveOne() {
    int a, b;
    in >> a >> b;
    out << (a % b == 0 ? 0 : b - a % b) << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  ADivisibilityProblem(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};