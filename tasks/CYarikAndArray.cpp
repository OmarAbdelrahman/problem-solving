#include <bits/stdc++.h>
#include "../library/lib.hpp"

#define _size(a) (int) (a).size()

using namespace std;

class CYarikAndArray {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int> a(n);
    in >> a;
    int result = a[0], total = a[0];
    for (int i = 1; i < n; i++) {
      if (abs(a[i]) % 2 == abs(a[i - 1]) % 2) {
        total = 0;
      }
      total = max(a[i], total + a[i]);
      result = max(result, total);
    }
    out << result << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  CYarikAndArray(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  istream& in;
  ostream& out;
};