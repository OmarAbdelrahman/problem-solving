#include <bits/stdc++.h>

using namespace std;

class BHauntedHouse {
public:
    void solveOne(istream &is, ostream &os) {
      int n; is >> n;
      string b; is >> b;

      vector<int> zeros;
      for (int i = 0; i < n; i++) {
        if (b[i] == '0') {
          zeros.push_back(n - i - 1);
        }
      }
      reverse(begin(zeros), end(zeros));

      int64_t r = 0;
      for (int i = 1; i <= n; i++) {
        if (i > (int) zeros.size()) {
          os << -1;
        } else {
          r += zeros[i - 1] - (i - 1);
          os << r;
        }
        os << " \n"[i == n];
      }
    }

    void solve(istream &is, ostream &os) {
      int t;
      is >> t;
      for (int i = 0; i < t; i++) {
        solveOne(is, os);
      }
    }
};