#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

const int MOD = 998244353;

class CMakeItAlternating {
public:
  vector<int64> factorial;

  CMakeItAlternating() {
    factorial = vector<int64>(200000);
    factorial[0] = 1;
    for (int i = 1; i < factorial.size(); i++) {
      factorial[i] = factorial[i - 1] * i;
      factorial[i] %= MOD;
    }
  }

  void solveOne(istream &is, ostream &os) {
    string s; is >> s;
    int c = 1, j = 0, n = (int) s.size();
    int64 r = 1;
    for (int i = 1; i < n; i++) {
      if (s[i - 1] != s[i]) {
        c++;
        r *= i - j;
        r %= MOD;
        j = i;
      }
    }
    r *= n - j;
    r %= MOD;
    os << n - c << ' ' << (factorial[n - c] * r) % MOD << '\n';
  }

  void solve(istream &is, ostream &os) {
    int t; is >> t;
    for (int i = 0; i < t; i++) {
      solveOne(is, os);
    }
  }
};