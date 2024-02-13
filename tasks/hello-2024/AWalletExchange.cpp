#include <bits/stdc++.h>
#include "../../library/io_utils.hpp"
using namespace std;

class AWalletExchange {
public:
  void solveOne() {
    int a, b;
    in >> a >> b;
    print_conditional(out, abs(b - a) % 2 == 0, {"Alice", "Bob"});
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  AWalletExchange(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};