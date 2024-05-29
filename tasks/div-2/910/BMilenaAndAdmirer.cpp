#include <bits/stdc++.h>
#include "../../../library/vector_utils.hpp"

#define _size(a) (int) (a).size()

using namespace std;

class BMilenaAndAdmirer {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int64_t> a(n);
    in >> a;
    int64_t result = 0;
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] <= a[i + 1]) {
        continue;
      }
      if (a[i] % a[i + 1] == 0) {
        result += a[i] / a[i + 1] - 1;
        a[i] = a[i + 1];
      } else {
        int64_t k = a[i] / a[i + 1] + 1;
        result += k - 1;
        a[i] /= k;
      }
    }
    out << result << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  BMilenaAndAdmirer(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};