#include <bits/stdc++.h>
#include "../library/suffix_array.hpp"

#define _size(a) (int) (a).size()

using namespace std;

class DBorders {
public:
  void solveOne() {
    string s;
    in >> s;
    const int64_t n = int64_t(s.size());
    suffix_array_t sa(s);
    const vector<int>& lcp = sa._lcp();
    int64_t result = n * (n + 1) / 2;
    for (int i = 1; i < sa.size(); i++) {
      result += lcp[i] * (lcp[i] + 1) / 2;
    }
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