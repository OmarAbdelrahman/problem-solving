#include <bits/stdc++.h>

#include "../../../../library/io.hpp"

using namespace std;
using namespace io;

class TariffPlan {
public:
  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      int n;
      in >> n;
      vector<int> a(n);
      for (int& ai : a) {
        in >> ai;
      }
      int m = 0, j = 0;
      for (const int& ai : a) {
        m += ((ai / M) + 1) * CM;
        j += ((ai / J) + 1) * CJ;
      }
      if (m < j) {
        print_case<pair<string, int>>(out, _ + 1, {MILE, m});
      } else if (m > j) {
        print_case<pair<string, int>>(out, _ + 1, {JUICE, j});
      } else {
        print_case<pair<string, int>>(out, _ + 1, {MILE + ' ' + JUICE, j});
      }
    }
  }

  template<typename T>
  void print_case(std::ostream& o, const int case_i, const T& result, const bool new_line = true) {
    o << "Case " << case_i << ": " << result << (new_line ? '\n' : char());
  }

  TariffPlan(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const string MILE = "Mile";
  const string JUICE = "Juice";

  const int M = 30, CM = 10;
  const int J = 60, CJ = 15;
};