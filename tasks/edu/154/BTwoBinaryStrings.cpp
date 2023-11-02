#include <bits/stdc++.h>
using namespace std;

class BTwoBinaryStrings {
public:
  void solveOne(istream& in, ostream& out) {
    string a, b;
    in >> a >> b;
    for (int i = 0; i < (int) a.length() - 1; i++) {
      if (a[i] == b[i] && a[i] == '0' && a[i + 1] == b[i + 1] && a[i + 1] == '1') {
        out << "YES" << '\n';
        return;
      }
    }
    out << "NO" << '\n';
  }

  void solve(istream& in, ostream& out) {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne(in, out);
    }
  }
};