#include <bits/stdc++.h>

using namespace std;

class CardsExchange {
public:
  void solve() {
    for (int a, b; in >> a >> b && (a || b); ) {
      set<int> A, B, C;
      for (int i = 0; i < a; i++) {
        int ai;
        in >> ai;
        A.insert(ai);
      }
      for (int i = 0; i < b; i++) {
        int bi;
        in >> bi;
        B.insert(bi);
      }
      set_intersection(begin(A), end(A), begin(B), end(B), inserter(C, begin(C)));
      out << min(A.size(), B.size()) - C.size() << '\n';
    }
  }

  CardsExchange(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};