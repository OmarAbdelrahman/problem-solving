#include <bits/stdc++.h>
using namespace std;

class APrimeDeletion {
public:
  void solveOne(istream& in, ostream& out) {
    in >> s;
    if (s.find('1') < s.find('3')) {
      out << 13;
    } else {
      out << 31;
    }
    out << '\n';
  }

  void solve(istream& in, ostream& out) {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne(in, out);
    }
  }

private:
  string s;
};