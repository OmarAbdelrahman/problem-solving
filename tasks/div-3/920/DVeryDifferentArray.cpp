#include <bits/stdc++.h>

#include "../../../library/deque_utils.hpp"
using namespace std;

class DVeryDifferentArray {
public:
  void solveOne() {
    int n, m;
    in >> n >> m;
    deque<int64_t> a(n), b(m);
    in >> a;
    in >> b;
    ranges::sort(a);
    ranges::sort(b);
    int64_t r1 = f(a, b);
    ranges::sort(b, greater{});
    int64_t r2 = f(a, b);
    ranges::sort(a, greater{});
    int64_t r3 = f(a, b);
    ranges::sort(b);
    int64_t r4 = f(a, b);
    out << max(max(r1, r2), max(r3, r4)) << '\n';
  }

  int64_t f(deque<int64_t> a, deque<int64_t> c) {
    const int n = size(a);
    int64_t r = 0;
    while (!a.empty()) {
      if (a.size() >= 2) {
        int64_t af = a.front();
        int64_t ab = a.back();
        int64_t d1_af = abs(af - c.front());
        int64_t d2_af = abs(af - c.back());
        int64_t d1_ab = abs(ab - c.front());
        int64_t d2_ab = abs(ab - c.back());
        int64_t best = max(max(d1_af, d2_af), max(d1_ab, d2_ab));
        if (best == d1_af) {
          a.pop_front();
          c.pop_front();
        } else if (best == d2_af) {
          a.pop_front();
          c.pop_back();
        } else if (best == d1_ab) {
          a.pop_back();
          c.pop_front();
        } else {
          a.pop_back();
          c.pop_back();
        }
        r += best;
      } else {
        int64_t ai = a.front();
        int64_t d1 = abs(ai - c.front());
        int64_t d2 = abs(ai - c.back());
        r += (d1 >= d2 ? d1 : d2);
        a.pop_back();
      }
    }
    return r;
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  DVeryDifferentArray(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};