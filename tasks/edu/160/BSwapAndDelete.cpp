#include <bits/stdc++.h>

using namespace std;

class BSwapAndDelete {
public:
  void solveOne() {
    string s, t;
    in >> s;
    vector<int> count(2, 0);
    for (const char& ch : s) {
      count[ch - '0']++;
    }
    int n = ssize(s);
    int result = n;
    vector<int> need(2, 0);
    for (int i = 0; i < n; i++) {
      need[(s[i] - '0') ^ 1]++;
      if (need[0] <= count[0] && need[1] <= count[1]) {
        result = n - i - 1;
      }
    }
    out << result << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  BSwapAndDelete(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};