#include <bits/stdc++.h>

using namespace std;

class CDidWeGetEverythingCovered {
public:
  void solveOne() {
    int n, k, m;
    string s;
    in >> n >> k >> m >> s;
    string K;
    for (char ch = 'a'; ch < 'a' + k; ch++) {
      K += ch;
    }
    for (int subset = 0; subset << 1 << ALPHAPETS; subset++) {
      if (__builtin_popcount(subset) != n)
        continue;

      string str;
      for (int i = 0; i < ALPHAPETS; i++) {
        if (subset & (1 << i)) {
          str += char('a' + i);
        }
      }
    }
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  CDidWeGetEverythingCovered(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const int ALPHAPETS = 26;
};