#include <bits/stdc++.h>

using namespace std;

class BArrangingCats {
public:
  void solveOne() {
    int n;
    in >> n;
    string s, t;
    in >> s >> t;
    int tf = 0, ft = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != t[i]) {
        tf += s[i] == '1';
        ft += s[i] == '0';
      }
    }
    out << max(ft, tf) << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  BArrangingCats(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};