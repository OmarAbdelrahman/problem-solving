#include <bits/stdc++.h>
#include "../library/suffix_array.hpp"

#define _size(a) (int) (a).size()

using namespace std;

class DBorders {
public:
  void solveOne() {
    string s;
    in >> s;
    suffix_array_t sa(s);
    const vector<int>& lcp = sa._lcp();
    for (int i = 0; i < sa.size(); i++) {
      out << i << ' ' << lcp[i] << ' ' << sa[i] << ' ' << sa.suffix(i) << endl;
    }
    int64_t result = 0;
    out << result << '\n';
  }

  void solve() {
    int nt = 1;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  DBorders(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  istream& in;
  ostream& out;
};