#include <bits/stdc++.h>

using namespace std;

class D1DEraser {
public:

  void solveOne(istream &is, ostream &os) {
    int n, k; is >> n >> k;
    string s; is >> s;
    int r = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'B') {
        i += k - 1;
        r += 1;
      }
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