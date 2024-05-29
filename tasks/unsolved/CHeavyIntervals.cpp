#include <bits/stdc++.h>
#include "../../library/vector_utils.hpp"
using namespace std;

class CHeavyIntervals {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int> l(n), r(n), c(n);
    in >> l;
    in >> r;
    in >> c;
    int64_t result = numeric_limits<int64_t>::max();
    ranges::sort(l);
    ranges::sort(r);
    ranges::sort(c);
    if (holds(l, r)) result = min(result, cost(l, r, c));
    ranges::sort(l, ranges::greater{});
    if (holds(l, r)) result = min(result, cost(l, r, c));
    ranges::sort(r, ranges::greater{});
    if (holds(l, r)) result = min(result, cost(l, r, c));
    ranges::sort(l);
    if (holds(l, r)) result = min(result, cost(l, r, c));
    out << result << '\n';
  }

  bool holds(const vector<int>& l, const vector<int>& r) {
    const int n = ssize(l);
    for (int i = 0; i < n; i++) {
      if (l[i] >= r[i]) {
        return false;
      }
    }
    return true;
  }

  int64_t cost(const vector<int>& l, const vector<int>& r, const vector<int>& c) {
    const int n = ssize(c);
    int64_t result = 0;
    for (int i = 0; i < n; i++) {
      result += c[i] * INT64_C(1) * (r[i] - l[i]);
    }
    return result;
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  CHeavyIntervals(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};