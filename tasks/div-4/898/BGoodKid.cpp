#include <bits/stdc++.h>

using namespace std;

class BGoodKid {
public:

  void solveOne(istream &is, ostream &os) {
    int n; is >> n;
    vector<int> a(n);
    for (int& x : a) is >> x;
    sort(begin(a), end(a));
    int r = a[0] + 1;
    for (int i = 1; i < n; i++) {
      r *= a[i];
    }
    os << r << "\n";
  }

  void solve(istream &is, ostream &os) {
    int t; is >> t;
    for (int i = 0; i < t; i++) {
      solveOne(is, os);
    }
  }
};