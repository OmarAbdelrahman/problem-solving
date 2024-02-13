#include <bits/stdc++.h>
#include "../../../../library/vector_io.hpp"
#include "../../../../library/io_utils.hpp"
using namespace std;

class PopularVote {
public:
  void solve() {
    int nt;
    in >> nt;
    while (nt--) {
      int n;
      in >> n;
      vector<int> v(n);
      in >> v;
      int s = 0, j = 0, b = -1;
      for (int i = 0; i < n; i++) {
        s += v[i];
        if (v[i] > b) {
          b = v[i];
          j = i + 1;
        }
      }
      if (count(begin(v), end(v), b) > 1) {
        out << "no winner" << '\n';
      } else {
        out << value_conditional(b * 2 > s, {"minority", "majority"}) << " winner " << j << '\n';
      }
    }
  }

  PopularVote(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};