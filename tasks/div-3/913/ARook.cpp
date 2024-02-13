#include <bits/stdc++.h>

using namespace std;

class ARook {
public:
  void solveOne() {
    string s;
    in >> s;
    for (int i = 1; i <= 8; i++) {
      if (i != s.back() - '0') {
        out << s[0] << i << '\n';
      }
    }
    for (char ch = 'a'; ch <= 'h'; ch++) {
      if (ch != s.front()) {
        out << ch << s[1] << '\n';
      }
    }
    out << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  ARook(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};