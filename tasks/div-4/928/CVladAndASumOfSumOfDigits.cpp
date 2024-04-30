#include <bits/stdc++.h>

#include "../../../library/adhoc_utils.hpp"
using namespace std;

class CVladAndASumOfSumOfDigits {
public:
  void solveOne() {
    int n;
    in >> n;
    out << sum[n] << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  CVladAndASumOfSumOfDigits(istream& in, ostream& out): in(in), out(out) {
    sum = pre_compute_sum_of_digits_sum_to(200000);
  }

private:
  ostream& out;
  istream& in;

  vector<int> sum;
};