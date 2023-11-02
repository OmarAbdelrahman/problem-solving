#include <bits/stdc++.h>
using namespace std;

class ARigged {
public:

  void solveOne(istream &is, ostream &os) {
    int n; is >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
      int s, e; is >> s >> e;
      a[i] = { s, e };
    }
    pair<int, int> poly = a[0];
    for (int i = 1; i < n; i++) {
      if (poly.first <= a[i].first && poly.second <= a[i].second) {
        os << "-1\n";
        return;
      }
    }
    os << poly.first << '\n';
  }

  void solve(istream &is, ostream &os) {
    int t; is >> t;
    for (int i = 0; i < t; i++) {
      solveOne(is, os);
    }
  }
};