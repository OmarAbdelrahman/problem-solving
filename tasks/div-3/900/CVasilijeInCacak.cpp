#include <bits/stdc++.h>
using namespace std;

using int64 = int64_t;
using uint64 = uint64_t;
using uint = uint32_t;

class CVasilijeInCacak {
public:

  void solveOne(istream &is, ostream &os) {
    uint64 n, k, x; is >> n >> k >> x;
    if (k * (k + 1) <= 2 * x && 2 * x <= n * (n + 1) - (n - k) * (n - k + 1)) {
      os << "YES\n";
    } else {
      os << "NO\n";
    }
  }

  void solve(istream &is, ostream &os) {
    int t; is >> t;
    for (int i = 0; i < t; i++) {
      solveOne(is, os);
    }
  }
};