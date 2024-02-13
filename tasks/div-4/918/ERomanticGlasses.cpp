#include <bits/stdc++.h>
#include "../../../library/vector_io.hpp"
#include "../../../library/io_utils.hpp"
using namespace std;

class ERomanticGlasses {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int64_t> a(n);
    in >> a;
    vector<int64_t> s(n + 1, 0);
    for (int i = 0; i < n; i++) {
      s[i + 1] = s[i] + (i % 2 == 0 ? a[i] : -a[i]);
    }
    print_yes_or_no(out, size(set<int64_t>(begin(s), end(s))) != n + 1);
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  ERomanticGlasses(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};