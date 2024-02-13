#include <bits/stdc++.h>

using namespace std;

class ACMContestScoring {
public:
  void solve() {
    vector<int> f(N, 0);
    vector<bool> ac(N, false);
    for (int m; in >> m && m != -1; ) {
      char ch;
      string s;
      in >> ch >> s;
      int at = ch - 'A';
      if (ac[at]) {
        continue;
      }
      if (s[0] == 'r') {
        f[at] += m;
        ac[at] = true;
      } else {
        f[at] += 20;
      }
    }
    int s = 0, r = 0;
    for (int i = 0; i < N; i++) {
      if (ac[i]) {
        s += 1;
        r += f[i];
      }
    }
    out << s << ' ' << r << '\n';
  }

  ACMContestScoring(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const int N = 26;
};