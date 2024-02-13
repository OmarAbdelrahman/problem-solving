#include <bits/stdc++.h>

#include "../../../../library/io_utils.hpp"
using namespace std;

class BitsEqualizer {
public:
  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      string s, t;
      in >> s >> t;
      const int n = size(s);
      int s1 = 0, t1 = 0, qs = 0;
      int tf = 0, ft = 0;
      for (int i = 0; i < n; i++) {
        s1 += s[i] == '1';
        t1 += t[i] == '1';
        qs += s[i] == '?';
        if (s[i] != t[i]) {
          tf += s[i] == '1';
          ft += s[i] == '0';
        }
      }
      print_case(out, _ + 1, value_conditional<int>(s1 > t1, {qs + max(tf, ft), -1}));
    }
  }

  BitsEqualizer(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};