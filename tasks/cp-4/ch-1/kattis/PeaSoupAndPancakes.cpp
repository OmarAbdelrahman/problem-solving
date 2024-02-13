#include <bits/stdc++.h>
#include "../../../../library/io_utils.hpp"
using namespace std;

class PeaSoupAndPancakes {
public:
  void solve() {
    int n;
    in >> n;
    string r;
    while (n--) {
      int m;
      in >> m;
      in.ignore();
      string name;
      getline(in, name);
      bool pan = false, pea = false;
      while (m--) {
        string s;
        getline(in, s);
        pan |= s == "pancakes";
        pea |= s == "pea soup";
      }
      if (pan && pea && r.empty()) {
        r = name;
      }
    }
    print_conditional(out, r.empty(), {r, "Anywhere is fine I guess"});
  }

  PeaSoupAndPancakes(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};