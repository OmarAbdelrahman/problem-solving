#include <bits/stdc++.h>

using namespace std;


const int SN = 1000010;
char s[SN];

class Digits {
public:
  int solve(int length, const int& count) {
    if (length == 1) return count + 1;
    return solve(int(log10(length)) + 1, count + 1);
  }

  void solve() {
    while (scanf("%s", s) && s[0] != 'E') {
      int d = strlen(s);
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