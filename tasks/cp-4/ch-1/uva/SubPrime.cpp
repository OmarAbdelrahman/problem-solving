#include <bits/stdc++.h>
#include "../../../../library/io_utils.hpp"
using namespace std;

class SubPrime {
public:
  void solve() {
    for (int b, n; in >> b >> n && (b != 0 || n != 0); ) {
      vector<int> m(b);
      for (int& mi : m) {
        in >> mi;
      }
      for (int i = 0; i < n; i++) {
        int d, c, v;
        in >> d >> c >> v;
        m[d - 1] -= v;
        m[c - 1] += v;
      }
      print_conditional(out, all_of(begin(m), end(m), [](int x) { return x >= 0; }), {"N", "S"});
    }
  }

  SubPrime(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};