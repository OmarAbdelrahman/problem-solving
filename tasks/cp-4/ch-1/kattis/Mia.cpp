#include <bits/stdc++.h>

using namespace std;

class Mia {
public:
  void solve() {
    for (int s0, s1, r0, r1; in >> s0 >> s1 >> r0 >> r1 && s0 + s1 + r0 + r1 != 0; ) {
      if (s0 < s1) swap(s0, s1);
      if (r0 < r1) swap(r0, r1);
      int s = s0 * 10 + s1;
      int r = r0 * 10 + r1;
      if (s == r) {
        out << "Tie.";
      } else if (s == 21) {
        out << P1;
      } else if (r == 21) {
        out << P2;
      } else if (s0 == s1) {
        if (r0 == r1) {
          out << (s > r ? P1 : P2);
        } else {
          out << P1;
        }
      } else if (r0 == r1) {
        out << P2;
      } else {
        out << (s > r ? P1 : P2);
      }
      out << '\n';
    }
  }

  Mia(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const string P1 = "Player 1 wins.";
  const string P2 = "Player 2 wins.";
};