#include <bits/stdc++.h>

using namespace std;

class ARecoveringASmallString {
public:
  void solveOne() {
    int n;
    in >> n;
    set<string> r;
    for (int i = 1; i <= 26; i++) {
      for (int j = 1; j <= 26; j++) {
        for (int k = 1; k <= 26; k++) {
          if (i + j + k == n) {
            string s;
            s += char('a' + i - 1);
            s += char('a' + j - 1);
            s += char('a' + k - 1);
            r.insert(s);
          }
        }
      }
    }
    out << *(begin(r)) << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  ARecoveringASmallString(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};