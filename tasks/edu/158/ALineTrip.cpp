#include <bits/stdc++.h>
#include "../../../library/vector_utils.hpp"

using namespace std;

class ALineTrip {
public:
  void solveOne() {
    int n, x;
    in >> n >> x;
    vector<int> a(n);
    in >> a;
    int result = a[0];
    for (int i = 1; i < n; i++) {
      result = max(result, a[i] - a[i - 1]);
    }
    out << max(result, 2 * (x - a.back())) << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  ALineTrip(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};