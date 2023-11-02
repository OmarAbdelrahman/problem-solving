#include <bits/stdc++.h>
using namespace std;

using int64 = int64_t;
using u64 = uint64_t;
using uint = uint32_t;

class BAleksaAndStack {
public:

  void solveOne(istream &is, ostream &os) {
    int n; is >> n;
    for (int i = 0; i < n; i++) {
      os << i * 2 + 1 << " \n"[i == n - 1];
    }
  }

  void solve(istream &is, ostream &os) {
    int t; is >> t;
    for (int i = 0; i < t; i++) {
      solveOne(is, os);
    }
  }
};