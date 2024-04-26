#include <bits/stdc++.h>

#include "../../../library/vector_io.hpp"
using namespace std;

class ASashaAndTheBeautifulArray {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int64_t> a(n);
    in >> a;
    int64_t s = 0;
    ranges::sort(a);
    for (int i = 1; i < n; i++) {
      s += (a[i] - a[i - 1]);
    }
    out << s << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  ASashaAndTheBeautifulArray(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};