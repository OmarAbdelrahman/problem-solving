#include <bits/stdc++.h>

using namespace std;

class Digits {
public:
  int solve(const int& length, const int& count) {
    if (length == 1) return count + 1;
    return solve(int(log10(length)) + 1, count + 1);
  }

  void solve() {
    for (string s; in >> s && s[0] != 'E'; ) {
      const int d = s.size();
      if (d == 1 && s[0] == '1') {
        out << 1 << '\n';
      } else {
        out << solve(d, 1) << '\n';
      }
    }
  }

  Digits(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};