#include <bits/stdc++.h>

using namespace std;

class ACandiesAndTwoSisters {
public:
  void solveOne() {
    int n;
    in >> n;
    out << n / 2 - (n % 2 == 0) << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  ACandiesAndTwoSisters(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};