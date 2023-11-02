#include <bits/stdc++.h>
using namespace std;

using int64 = int64_t;
using uint64 = uint64_t;
using uint = uint32_t;

class AHowMuchDoesDaytonaCost {
public:

  void solveOne(istream &is, ostream &os) {
    int n, k; is >> n >> k;
    vector<int> a(n);
    for (int& ai : a) {
      is >> ai;
    }
    os << (find(begin(a), end(a), k) != end(a) ? "YES" : "NO") << '\n';
  }

  void solve(istream &is, ostream &os) {
    int t; is >> t;
    for (int i = 0; i < t; i++) {
      solveOne(is, os);
    }
  }
};