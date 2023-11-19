#include <bits/stdc++.h>

#define _size(a) (int) (a).size()

using namespace std;

class AGameWithIntegers {
public:
  void solveOne(istream& in, ostream& out) {
    int n;
    in >> n;
    if (n % 3 == 0) {
      out << "Second\n";
    } else {
      out << "First\n";
    }
  }

  void solve(istream& in, ostream& out) {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne(in, out);
    }
  }
};