#include <bits/stdc++.h>
#include "../../library/vector_io.hpp"

#define _size(a) (int) (a).size()

using namespace std;

class ANextRound {
public:
  void solveOne() {
    int n, k;
    in >> n >> k;
    vector<int> a(n);
    in >> a;
    out << count_if(begin(a), end(a), [&](const int& v) { return v > 0 && v >= a[k - 1]; }) << '\n';
  }

  void solve() {
    int nt = 1;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  ANextRound(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};