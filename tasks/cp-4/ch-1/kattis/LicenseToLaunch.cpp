#include <bits/stdc++.h>
#include "../../../../library/vector_io.hpp"
using namespace std;

class LicenseToLaunch {
public:
  void solve() {
    int n;
    in >> n;
    vector<int> a(n);
    in >> a;
    out << find(begin(a), end(a), *min_element(begin(a), end(a))) - begin(a) << '\n';
  }

  LicenseToLaunch(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};