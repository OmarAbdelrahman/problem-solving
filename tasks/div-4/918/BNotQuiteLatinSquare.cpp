#include <bits/stdc++.h>
#include "../../../library/vector_utils.hpp"
using namespace std;

class BNotQuiteLatinSquare {
public:
  void solveOne() {
    vector<string> strs(3);
    in >> strs;
    for (const string& str : strs) {
      if (str.find('?') != string::npos) {
        out << char('A' ^ 'B' ^ 'C' ^ '?' ^ str[0] ^ str[1] ^ str[2]) << '\n';
        return;
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

  BNotQuiteLatinSquare(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};