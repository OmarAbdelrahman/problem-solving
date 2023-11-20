#include <bits/stdc++.h>

#define _size(a) (int) (a).size()

using namespace std;

class AMilicaAndString {
public:
  void solveOne() {
    int n, k;
    in >> n >> k;
    string s;
    in >> s;
    int bs = count(begin(s), end(s), 'B');
    if (bs == k) {
      out << "0\n";
    } else {
      out << "1\n";
      if (bs < k) {
        for (int i = 0; i < n; i++) {
          bs += (int) (s[i] == 'A');
          if (bs == k) {
            out << i + 1 << " B\n";
            return;
          }
        }
      } else {
        for (int i = 0; i < n; i++) {
          bs -= (int) (s[i] == 'B');
          if (bs == k) {
            out << i + 1 << " A\n";
            return;
          }
        }
      }
    }
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  AMilicaAndString(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};