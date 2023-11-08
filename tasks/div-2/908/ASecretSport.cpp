#include <bits/stdc++.h>
using namespace std;

#define _size(a) (int) (a).size()

class ASecretSport {
public:
  void solveOne(istream& in, ostream& out) {
    int n;
    in >> n;
    string s;
    in >> s;
    out << s.back() << '\n';
  }

  void solve(istream& in, ostream& out) {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne(in, out);
    }
  }
};