#include <bits/stdc++.h>
#include "../../../library/suffix_array.hpp"
using namespace std;

class ANumberOfDifferentSubstrings {
public:
  void solveOne(istream& in, ostream& out) {
    string s;
    in >> s;
    out << suffix_array_t(s).count_different_substrings() << '\n';
  }

  void solve(istream& in, ostream& out) {
    solveOne(in, out);
  }
};