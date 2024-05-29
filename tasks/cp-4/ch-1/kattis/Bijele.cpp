#include <bits/stdc++.h>

#include "../../../../library/vector_utils.hpp"
using namespace std;

class Bijele {
public:
  void solve() {
    array<int, M> valid = {1, 1, 2, 2, 2, 8};
    vector<int> count(M), r(M);
    in >> count;
    for (int i = 0; i < M; i++) {
      r[i] = valid[i] - count[i];
    }
    out << r << '\n';
  }

  Bijele(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  static const int M = 6;
};