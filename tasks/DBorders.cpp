#include <bits/stdc++.h>
#include "../library/lib.hpp"
#include "../library/suffix_array.hpp"

using namespace std;

#define _size(a) (int) (a).size()

class DBorders {
public: 
  void solveOne(istream& in, ostream& out) {
    string s;
    in >> s;
    suffix_array_t sa(s);
    out << sa.count_distinct_substrings() << endl;
    const vector<int> lcp = sa._lcp();
    for (int i = 0; i < sa.size(); i++) {
      out << lcp[i] << ' ' << sa[i] << ' ' << sa.suffix(i) << endl;
    }
  }

  void solve(istream& in, ostream& out) {
    int nt = 1;
    for (int _ = 0; _ < nt; _++) {
      solveOne(in, out);
    }
  }
};