#include <bits/stdc++.h>

#define _size(a) (int) (a).size()

using namespace std;

class AElephant {
public:
  void solveOne() {
    int n;
    in >> n;
    out << n / 5 + (n % 5 != 0) << '\n';
  }

  void solve() {
    int nt = 1;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  AElephant(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};