#include <bits/stdc++.h>
#include "../../library/vector_utils.hpp"
using namespace std;

class BMakeAlmostEqualWithMod {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int64_t> a(n);
    in >> a;
    int64_t low = 1, high = int64_t(1e18);
    while (low <= high) {
      int64_t k = low + (high - low) / 2;
      vector<int64_t> b = a;
      for (int64_t& v : b) {
        v %= k;
      }
      int count = count_distinct(b);
      if (count == 2) {
        out << k << '\n';
        return;
      }
      if (count < 2) {
        low = k + 1;
      } else {
        high = k - 1;
      }
    }
  }

  int count_distinct(const vector<int64_t>& v) {
    unordered_set<int64_t> s;
    for (const int64_t& a : v) s.emplace(a);
    return ssize(s);
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  BMakeAlmostEqualWithMod(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};