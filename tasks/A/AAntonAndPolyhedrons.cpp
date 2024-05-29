#include <bits/stdc++.h>
#include "../../library/vector_utils.hpp"

using namespace std;

class AAntonAndPolyhedrons {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<string> poly(n);
    in >> poly;
    int result = 0;
    for (const string& s : poly) {
      switch (s.front()) {
        case 'T':
          result += 4;
          break;
        case 'C':
          result += 6;
          break;
        case 'O':
          result += 8;
          break;
        case 'D':
          result += 12;
          break;
        case 'I':
          result += 20;
          break;
      }
    }
    out << result << '\n';
  }

  void solve() {
    int nt = 1;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  AAntonAndPolyhedrons(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};