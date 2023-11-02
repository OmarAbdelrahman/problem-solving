#include <bits/stdc++.h>
using namespace std;

using int64 = int64_t;
using u64 = uint64_t;

class BSetsAndUnion {
public:

  void solveOne(istream &is, ostream &os) {
    int n; is >> n;
    vector<int64> s(n);
    int64 og = 0;
    for (int64& si : s) {
      int k; is >> k;
      for (int i = 0; i < k; i++) {
        int v; is >> v;
        si |= 1LL << (v - 1);
      }
      og |= si;
    }

    int r = 0;
    for (int i = 0; i < 50; i++) {
      int64 cs = 0;
      for (int64 si : s) {
        if (!(si & (1LL << i))) {
          cs |= si;
        }
      }
      if (cs != og) {
        r = max(r, __builtin_popcountll(cs));
      }
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