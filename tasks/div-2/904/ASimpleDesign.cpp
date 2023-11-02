#include <bits/stdc++.h>

using namespace std;

class ASimpleDesign {
public:
    void solveOne(istream &is, ostream &os) {
      int x, k;
      is >> x >> k;

      auto ok = [&](int n) -> bool {
        int s = 0;
        while (n != 0) {
          s += n % 10;
          n /= 10;
        }
        return s % k == 0;
      };

      int n = x;
      while (!ok(n)) {
        n++;
      }

      os << n << '\n';
    }

    void solve(istream &is, ostream &os) {
      int t;
      is >> t;
      for (int i = 0; i < t; i++) {
        solveOne(is, os);
      }
    }
};