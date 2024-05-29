#include <bits/stdc++.h>
#include "../../../library/vector_utils.hpp"

#define _size(a) (int) (a).size()

using namespace std;

class B250ThousandTonsOfTNT {
public:
  void solveOne(istream& in, ostream& out) {
    int n;
    in >> n;
    vector<int> a(n);
    in >> a;
    auto compute_difference = [&](const int& k) -> int64_t {
      const int size = n / k;
      int64_t big = numeric_limits<int64_t>::min();
      int64_t small = numeric_limits<int64_t>::max();
      for (int i = 0; i < n; i += size) {
        int64_t sum = 0;
        for (int j = i; j < i + size; j++) {
          sum += a[j];
        }
        big = max(big, sum);
        small = min(small, sum);
      }
      return big - small;
    };
    int64_t difference = *max_element(begin(a), end(a)) - *min_element(begin(a), end(a));
    for (int k = 2; k <= n; k++) {
      if (n % k == 0) {
        difference = max(difference, compute_difference(k));
      }
    }
    out << difference << '\n';
  }

  void solve(istream& in, ostream& out) {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne(in, out);
    }
  }
};