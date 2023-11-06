#include <bits/stdc++.h>
using namespace std;

#define _size(a) (int) (a).size()

class BPointsAndMinimumDistance {
public:
  void solveOne(istream& in, ostream& out) {
    int n;
    in >> n;
    vector<int> a(2 * n);
    for (int& ai : a) {
      in >> ai;
    }
    sort(begin(a), end(a));
    out << (a[n - 1] - a[0]) + (a[2 * n - 1] - a[n]) << '\n';
    for (int i = 0; i < n; i++) {
      out << a[i] << ' ' << a[2 * n - i - 1] << '\n';
    }
  }

  void solve(istream& in, ostream& out) {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne(in, out);
    }
  }
};