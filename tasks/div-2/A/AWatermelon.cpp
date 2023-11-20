#include <bits/stdc++.h>

#define _size(a) (int) (a).size()

using namespace std;

class AWatermelon {
public:
  void solveOne() {
    int n;
    in >> n;
    out << (n % 2 == 0 && n > 2 ? "YES\n" : "NO\n");
  }

  void solve() {
    int nt = 1;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  AWatermelon(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};