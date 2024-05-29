#include <bits/stdc++.h>
#include "../../../../library/vector_utils.hpp"
using namespace std;

class DeliciousBubbleTea {
public:
  void solve() {
    int n;
    in >> n;
    vector<int> p_tea(n);
    in >> p_tea;
    int m;
    in >> m;
    vector<int> p_top(m);
    in >> p_top;
    int which = numeric_limits<int>::max();
    for (int i = 0; i < n; i++) {
      int k;
      in >> k;
      while (k--) {
        int j;
        in >> j;
        which = min(which, p_tea[i] + p_top[j - 1]);
      }
    }
    int have;
    in >> have;
    have -= which;
    out << have / which << '\n';
  }

  DeliciousBubbleTea(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};