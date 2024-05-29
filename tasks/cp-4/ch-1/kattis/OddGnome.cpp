#include <bits/stdc++.h>
#include "../../../../library/vector_utils.hpp"
using namespace std;

class OddGnome {
public:
  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      int n;
      in >> n;
      vector<int> a(n);
      in >> a;
      for (int i = 1; i + 1 < n; i++) {
        if (a[i] != a[i - 1] + 1) {
          out << i + 1 << '\n';
          break;
        }
      }
    }
  }

  OddGnome(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};