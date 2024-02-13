#include <bits/stdc++.h>
using namespace std;

class BEraseFirstOrSecondLetter {
public:
  void solveOne() {
    int n;
    in >> n;
    string s;
    in >> s;
    vector<int64_t> dp(n + 1, -1);
    out << solve(s, dp) << '\n';
  }

  int64_t solve(const string& s, vector<int64_t>& dp) {
    if (size(s) < 2) {
      return 0;
    }
    int64_t& result = dp[ssize(s)];
    if (result != -1) {
      return result;
    }
    result = int64_t(s[0] != s[1]);
    string t = s;
    t.erase(begin(t));
    result += solve(t, dp);
    t[0] = s[0];
    result += solve(t, dp);
    return result;
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  BEraseFirstOrSecondLetter(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};