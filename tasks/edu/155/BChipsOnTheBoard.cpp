#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

class BChipsOnTheBoard {
public:

  void solveOne(istream &is, ostream &os) {
    int n; is >> n;
    vector<int64> a(n), b(n);
    for (int64& x : a) is >> x;
    for (int64& x : b) is >> x;

    sort(begin(a), end(a));
    sort(begin(b), end(b));

    long long sa = a[0] * n, sb = b[0] * n;
    for (int i = 0; i < n; i++) {
      sa += b[i];
      sb += a[i];
    }
    os << min(sa, sb) << '\n';
  }

  void solve(istream &is, ostream &os) {
    int t; is >> t;
    for (int i = 0; i < t; i++) {
      solveOne(is, os);
    }
  }
};