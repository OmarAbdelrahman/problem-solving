#include <bits/stdc++.h>

#include "../../../library/vector_utils.hpp"
#include "../../../library/debug.hpp"
using namespace std;

class BTurtleMathFastThreeTask {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int64_t> a(n);
    in >> a;
    int64_t total = accumulate(begin(a), end(a), INT64_C(0));
    if (total % 3 == 0) {
      out << 0 << '\n';
    } else {
      if ((total + 1) % 3 == 0) {
        out << 1 << '\n';
        return;
      }
      for (int i = 0; i < n; i++) {
        if ((total - a[i]) % 3 == 0) {
          out << 1 << '\n';
          return;
        }
      }
      out << 2 << '\n';
    }
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  BTurtleMathFastThreeTask(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};