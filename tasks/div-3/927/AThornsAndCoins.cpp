#include <bits/stdc++.h>

using namespace std;

class AThornsAndCoins {
public:
  void solveOne() {
    int n;
    string s;
    in >> n >> s;
    int r = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '*') {
        if (i + 1 < n && s[i + 1] == '*')
          break;
        else
          continue;
      }
      r += s[i] == '@';
    }
    out << r << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  AThornsAndCoins(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};