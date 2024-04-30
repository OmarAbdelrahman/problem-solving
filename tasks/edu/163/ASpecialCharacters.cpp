#include <bits/stdc++.h>

using namespace std;

class ASpecialCharacters {
public:
  void solveOne() {
    int n;
    in >> n;
    if (n % 2 != 0) {
      out << "NO" << '\n';
    } else {
      out << "YES" << '\n';
      char ch = 'A';
      string r;
      for (int i = 0; i < n; i += 2) {
        r += ch;
        r += ch;
        ch = (ch + 1) % 'Z';
      }
      out << r << '\n';
    }
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  ASpecialCharacters(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};