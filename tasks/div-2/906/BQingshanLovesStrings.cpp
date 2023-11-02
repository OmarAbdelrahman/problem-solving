#include <bits/stdc++.h>
using namespace std;

#define _size(a) (int) (a).size()

class BQingshanLovesStrings {
public:
  void solveOne(istream& in, ostream& out) {
    int n, m;
    in >> n >> m;
    string s, t;
    in >> s >> t;
    if (ok(s)) {
      out << "Yes\n";
      return;
    }
    if (!ok(t)) {
      out << "No\n";
      return;
    }
    for (int i = 0; i + 1 < n; i++) {
      if (s[i] == s[i + 1] && (s[i] == t.front() || s[i + 1] == t.back())) {
        out << "No\n";
        return;
      }
    }
    out << "Yes\n";
  }

  static bool ok(const string& s) {
    for (int i = 0; i + 1 < _size(s); i++) {
      if (s[i] == s[i + 1]) {
        return false;
      }
    }
    return true;
  }

  void solve(istream& in, ostream& out) {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne(in, out);
    }
  }
};