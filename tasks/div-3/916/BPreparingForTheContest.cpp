#include <bits/stdc++.h>
using namespace std;

class BPreparingForTheContest {
public:
  void solveOne() {
    int n, k;
    in >> n >> k;
    for (int i = n - k; i <= n; i++) {
      out << i << ' ';
    }
    for (int i = n - k - 1; i > 0; i--) {
      out << i << ' ';
    }
    out << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  BPreparingForTheContest(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};