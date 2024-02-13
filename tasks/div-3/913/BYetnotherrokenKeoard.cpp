#include <bits/stdc++.h>

using namespace std;

class BYetnotherrokenKeoard {
public:
  void solveOne() {
    string s;
    in >> s;
    const int n = ssize(s);
    stack<int> upper, lower;
    vector<bool> ok(n, true);
    for (int i = 0; i < n; i++) {
      if (s[i] == 'b') {
        ok[i] = false;
        if (!lower.empty()) {
          ok[lower.top()] = false;
          lower.pop();
        }
      } else if (s[i] == 'B') {
        ok[i] = false;
        if (!upper.empty()) {
          ok[upper.top()] = false;
          upper.pop();
        }
      } else {
        if (islower(s[i])) lower.push(i); else upper.push(i);
      }
    }
    for (int i = 0; i < n; i++) {
      if (ok[i]) {
        out << s[i];
      }
    }
    out << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  BYetnotherrokenKeoard(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};