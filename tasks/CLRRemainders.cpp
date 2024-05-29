#include <bits/stdc++.h>

#include "../library/vector_utils.hpp"
using namespace std;

class CLRRemainders {
public:
  void solveOne() {
    int n;
    int64_t m;
    in >> n >> m;
    vector<int64_t> a(n);
    in >> a;
    string cmds;
    in >> cmds;
    int64_t p = 1;
    for (const int64_t& ai : a) {
      p *= ai;
    }
    int li = 0, ri = n - 1;
    for (int i = 0; i < n; i++) {
      out << p % m << " \n"[i == n - 1];
      const char cmd = cmds[i];
      if (cmd == 'L') {
        p /= a[li++];
      } else {
        p /= a[ri--];
      }
    }
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  CLRRemainders(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};