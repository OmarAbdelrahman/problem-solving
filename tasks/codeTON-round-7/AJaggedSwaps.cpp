#include <bits/stdc++.h>
#include "../../library/vector_io.hpp"

using namespace std;

class AJaggedSwaps {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int> a(n);
    in >> a;
    if (a.front() == 1) {
      out << "YES\n";
    } else {
      out << "NO\n";
    }
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  AJaggedSwaps(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};