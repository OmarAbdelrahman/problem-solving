#include <bits/stdc++.h>
#include "../../../library/lib.hpp"

using namespace std;

class AInSearchOfAnEasyProblem {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int> a(n);
    in >> a;
    if (count(begin(a), end(a), 1) >= 1) {
      out << "HARD\n";
    } else {
      out << "EASY\n";
    }
  }

  void solve() {
    int nt = 1;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  AInSearchOfAnEasyProblem(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};