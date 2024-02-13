#include <bits/stdc++.h>

using namespace std;

class BPlusMinusSplit {
public:
  void solveOne() {
    int n;
    in >> n;
    string s;
    in >> s;
    int cnt = 0;
    for (const char& ch : s) {
      if (ch == '+') cnt += 1; else cnt -= 1;
    }
    out << abs(cnt) << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  BPlusMinusSplit(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};