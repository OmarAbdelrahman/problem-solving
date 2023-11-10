#include <bits/stdc++.h>
#include "../../../library/suffix_array.hpp"
using namespace std;

class BLongestCommonSubstring {
public:
  void solveOne(istream& in, ostream& out) {
    string a, b; in >> a >> b;
    out << suffix_array_t().longest_common_substring(a, b) << '\n';
  }

  void solve(istream& in, ostream& out) {
    solveOne(in, out);
  }
};