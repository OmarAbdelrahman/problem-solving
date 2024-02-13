#include <bits/stdc++.h>

using namespace std;

class Bela {
public:
  void solve() {
    int n;
    in >> n;
    char S;
    in >> S;
    int r = 0;
    for (int _ = 0; _ < 4 * n; _++) {
      string s;
      in >> s;
      r += value(s[0], s[1] == S);
    }
    out << r << '\n';
  }

  inline int value(const char& ch, bool dominant) {
    if (ch == 'A') return 11;
    if (ch == 'K') return 4;
    if (ch == 'Q') return 3;
    if (ch == 'J') return dominant ? 20 : 2;
    if (ch == 'T') return 10;
    if (ch == '9') return dominant ? 14 : 0;
    return 0;
  }

  Bela(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};