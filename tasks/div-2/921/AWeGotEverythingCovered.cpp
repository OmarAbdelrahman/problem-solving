#include <bits/stdc++.h>

using namespace std;

class AWeGotEverythingCovered {
public:
  void solveOne() {
    int n, k;
    in >> n >> k;
    string s;
    for (char ch = 'a'; ch < 'a' + k; ch++) {
      s += ch;
    }
    for (int i = 0; i < n; i++) {
      out << s;
    }
    out << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  AWeGotEverythingCovered(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};