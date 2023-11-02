#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

class AIncreasingSequence {
public:

  void solveOne(istream &is, ostream &os) {
    int n; is >> n;
    vector<int> a(n);
    for (int& x : a) is >> x;

    int r = 0;
    for (int x : a) {
      r++;
      if (r == x)
        r++;
    }
    os << r << '\n';
  }

  void solve(istream &is, ostream &os) {
    int t; is >> t;
    for (int i = 0; i < t; i++) {
      solveOne(is, os);
    }
  }
};