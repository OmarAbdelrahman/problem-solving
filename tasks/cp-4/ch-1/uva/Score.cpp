#include <bits/stdc++.h>

using namespace std;

class Score {
public:
  void solve() {
    int nt;
    in >> nt;
    while (nt--) {
      string s;
      in >> s;
      int r = 0, c = 0;
      for (const char& ch : s) {
        if (ch == 'X') {
          c = 0;
        } else {
          c += 1;
        }
        r += c;
      }
      out << r << '\n';
    }
  }

  Score(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};