#include <bits/stdc++.h>

#include "../../../library/vector_utils.hpp"
#include "../../../library/io_utils.hpp"
#include "../../../library/debug.hpp"
using namespace std;

class BMakeEqual {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int64_t> a(n);
    in >> a;
    int64_t total = accumulate(begin(a), end(a), INT64_C(0));
    int64_t to = total / n;
    int64_t pour = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] >= to) {
        pour += (a[i] - to);
        a[i] = to;
      } else {
        if (pour <= 0) continue;
        int64_t take = to - a[i];
        if (take <= pour) {
          pour -= take;
          a[i] = to;
        } else {
          a[i] = pour;
          pour = 0;
        }
      }
    }
    bool ok = all_of(begin(a), end(a), [&](int v) { return v == to; });
    print_yes_or_no(out, ok);
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  BMakeEqual(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};