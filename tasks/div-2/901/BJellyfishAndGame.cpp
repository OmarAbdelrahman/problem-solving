#include <bits/stdc++.h>
using namespace std;

class BJellyfishAndGame {
public:

  void solveOne(istream &is, ostream &os) {
    int n, m, k;
    is >> n >> m >> k;
    vector<int64_t> a(n), b(m);
    for (int64_t& ai : a) {
      is >> ai;
    }
    for (int64_t& bi: b) {
      is >> bi;
    }

    sort(begin(a), end(a));
    sort(begin(b), end(b));

    if (a.front() < b.back()) {
      swap(a.front(), b.back());
    }

    sort(begin(a), end(a));
    sort(begin(b), end(b));

    if (k % 2 == 0 && b.front() < a.back()) {
      swap(b.front(), a.back());
    }

    os << accumulate(begin(a), end(a), 0LL) << '\n';
  }

  void solve(istream &is, ostream &os) {
    int t; is >> t;
    for (int i = 0; i < t; i++) {
      solveOne(is, os);
    }
  }
};