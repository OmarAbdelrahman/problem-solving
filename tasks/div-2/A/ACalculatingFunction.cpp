#include <bits/stdc++.h>

using namespace std;

class ACalculatingFunction {
public:
  void solveOne() {
    int64_t n;
    in >> n;
    if (n % 2 == 0) {
      out << n / 2 << '\n';
    } else {
      out << -(n / 2 + 1) << '\n';
    }
  }

  void solve() {
    int nt = 1;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  ACalculatingFunction(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};