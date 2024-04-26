#include <bits/stdc++.h>

using namespace std;

class AVladAndTheBestOfFive {
public:
  void solveOne() {
    string a;
    in >> a;
    if (count(begin(a), end(a), 'A') > count(begin(a), end(a), 'B')) {
      out << 'A' << '\n';
    } else {
      out << 'B' << '\n';
    }
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  AVladAndTheBestOfFive(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};