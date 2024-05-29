#include <bits/stdc++.h>
#include "../../../library/vector_utils.hpp"

using namespace std;

class CAddDivideAndFloor {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int> a(n);
    in >> a;
    int mn = *min_element(begin(a), end(a));
    int mx = *max_element(begin(a), end(a));
    vector<int> xs;
    while (mn != mx) {
      xs.emplace_back(mn % 2);
      mn += xs.back();
      mx += xs.back();
      mn /= 2;
      mx /= 2;
    }
    out << size(xs) << '\n';
    if (size(xs) <= n && !empty(xs)) {
      out << xs << '\n';
    }
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  CAddDivideAndFloor(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};