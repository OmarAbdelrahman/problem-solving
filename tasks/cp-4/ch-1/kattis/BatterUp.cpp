#include <bits/stdc++.h>
#include "../../../../library/vector_io.hpp"
using namespace std;

class BatterUp {
public:
  void solve() {
    int nt;
    in >> nt;
    vector<int> a(nt);
    in >> a;
    int n = 0, d = 0;
    for (int ai : a) {
      if (ai >= 0) {
        n += ai;
        d += 1;
      }
    }
    out << n * 1.0 / d << '\n';
  }

  BatterUp(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};