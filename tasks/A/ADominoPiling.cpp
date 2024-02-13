#include <bits/stdc++.h>

#define _size(a) (int) (a).size()

using namespace std;

class ADominoPiling {
public:
  void solveOne() {
    int m, n;
    in >> m >> n;
    out << m * n / 2 << '\n';
  }

  void solve() {
    int nt = 1;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  ADominoPiling(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};