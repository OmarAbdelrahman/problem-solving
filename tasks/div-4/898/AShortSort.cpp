#include <bits/stdc++.h>

using namespace std;

class AShortSort {
public:
  string b;

  AShortSort() : b("abc") {}

  void solveOne(istream &is, ostream &os) {
    string s;
    is >> s;
    int c = 0;
    for (int i = 0; i < 3; i++) {
      c += s[i] != b[i];
    }
    os << (c <= 2 ? "YES\n" : "NO\n");
  }

  void solve(istream &is, ostream &os) {
    int t;
    is >> t;
    for (int i = 0; i < t; i++) {
      solveOne(is, os);
    }
  }
};