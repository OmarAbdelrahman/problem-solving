#include <bits/stdc++.h>
#include "../../../library/vector_io.hpp"
using namespace std;

class CQuests {
public:
  void solveOne() {
    int n, k;
    in >> n >> k;
    vector<int> a(n), b(n);
    in >> a;
    in >> b;
    int64_t a_sum = 0, b_max = 0;
    int64_t result = 0;
    for (int i = 0; i < n && i < k; i++) {
      a_sum += a[i];
      b_max = max(b_max, int64_t(b[i]));
      result = max(result, a_sum + b_max * (k - i - 1));
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

  CQuests(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const int M = 2;
};