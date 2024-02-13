#include <bits/stdc++.h>

#include "../../../library/vector_io.hpp"
#include "../../../library/io_utils.hpp"
using namespace std;

class CSendingMessages {
public:
  void solveOne() {
    int n;
    int64_t f, a, b;
    in >> n >> f >> a >> b;
    vector<int64_t> moment(n);
    in >> moment;
    moment.insert(begin(moment), 0);
    for (int i = 1; i < n + 1; i++) {
      int64_t waiting = moment[i] - moment[i - 1];
      int64_t cost = min(b, waiting * a);
      f -= cost;
    }
    print_yes_or_no(out, f > 0);
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  CSendingMessages(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};