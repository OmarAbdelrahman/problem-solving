#include <bits/stdc++.h>

#include "../../../library/vector_utils.hpp"
using namespace std;

class BSummationGame {
public:
  void solveOne() {
    int n, k, x;
    in >> n >> k >> x;
    vector<int> a(n);
    in >> a;
    ranges::sort(a);
    vector<int> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
      prefix_sum[i + 1] = prefix_sum[i] + a[i];
    }
    int r = numeric_limits<int>::min();
    for (int take = 0; take <= k; take++) {
      int at_bob = max(0, n - take - x);
      int bob = prefix_sum[n - take] - prefix_sum[at_bob];
      r = max(r, prefix_sum[at_bob] - bob);
    }
    out << r << '\n';
  }

  void solveTwo() {
    int n, k, x;
    in >> n >> k >> x;
    vector<int> a(n);
    in >> a;
    ranges::sort(a, greater{});
    vector<int> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
      prefix_sum[i + 1] = prefix_sum[i] + a[i];
    }
    auto rsq = [&](const int& b, const int& e) -> int {
      return prefix_sum[e] - prefix_sum[b];
    };
    int r = numeric_limits<int>::min();
    for (int take = 0; take <= k; take++) {
      int mid = min(take + x, n);
      r = max(r, rsq(mid, n) - rsq(take, mid));
    }
    out << r << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  BSummationGame(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};