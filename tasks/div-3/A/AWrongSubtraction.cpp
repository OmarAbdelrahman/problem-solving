#include <bits/stdc++.h>

using namespace std;

class AWrongSubtraction {
public:
  void solveOne() {
    int n, k;
    in >> n >> k;
    while (k-- != 0) {
      if (n % 10 == 0) {
        n /= 10;
      } else {
        n -= 1;
      }
    }
    out << n << '\n';
  }

  void solve() {
    int nt = 1;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  AWrongSubtraction(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};