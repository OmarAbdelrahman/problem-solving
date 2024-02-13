#include <bits/stdc++.h>
#include "../../../../library/vector_io.hpp"
using namespace std;

class LostLineup {
public:
  void solve() {
    int n;
    in >> n;
    vector<int> r(n);
    r[0] = 1;
    for (int i = 2; i <= n; i++) {
      int d;
      in >> d;
      r[d + 1] = i;
    }
    out << r << '\n';
  }

  LostLineup(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};