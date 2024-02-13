#include <bits/stdc++.h>

using namespace std;

class BABFlipping {
public:
  void solveOne() {
    int n;
    in >> n;
    string s;
    in >> s;
    int min_index_a = 0;
    while (min_index_a < n && s[min_index_a] == 'B') {
      min_index_a++;
    }
    int max_index_b = n - 1;
    while (max_index_b >= 0 && s[max_index_b] == 'A') {
      max_index_b--;
    }
    out << max(0, max_index_b - min_index_a) << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  BABFlipping(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};