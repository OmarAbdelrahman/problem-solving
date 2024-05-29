#include <bits/stdc++.h>

#include "../../../library/vector_utils.hpp"
#include "../../../library/debug.hpp"
using namespace std;

class CMakeEqualAgain {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int> a(n);
    in >> a;
    if (all_of(begin(a), end(a), [&](int v) { return v == a.front(); })) {
      out << 0 << '\n';
      return;
    }
    auto f = [&]() -> int {
      int l = 0, r = n - 1;
      int c = -1;
      while (l < r && a[l] == a[r]) {
        if (c != -1 && a[l] != c) {
          break;
        }
        c = a[l];
        l += 1;
        r -= 1;
      }
      debug(l, r, c, "b");
      if (l == r) {
        return a[l] == c ? 0 : 1;
      }
      if (c == -1) c = a[0];
      while (l < r && a[l] == c) {
        l += 1;
      }
      debug(l, r, c);
      return r - l + 1;
    };
    int x = f();
    ranges::reverse(a);
    out << min(x, f()) << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  CMakeEqualAgain(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};