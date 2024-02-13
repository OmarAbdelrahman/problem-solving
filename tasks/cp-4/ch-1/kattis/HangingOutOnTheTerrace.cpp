#include <bits/stdc++.h>

using namespace std;

class HangingOutOnTheTerrace {
public:
  void solve() {
    int L, x;
    in >> L >> x;
    int t = 0, r = 0;
    while (x--) {
      string s;
      int n;
      in >> s >> n;
      if (s[0] == 'e') {
        if (t + n <= L) {
          t += n;
        } else {
          r += 1;
        }
      } else {
        t -= n;
      }
    }
    out << r << '\n';
  }

  HangingOutOnTheTerrace(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};