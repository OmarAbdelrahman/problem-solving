#include <bits/stdc++.h>

using namespace std;

class MasterMindHelper {
public:
  void solveOne() {
    in >> a >> correct >> incorrect;
    out << f("", int(a.size())) << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  int f(string s, const int& n) {
    if (int(s.size()) == n) {
      return guess(s) == make_pair(correct, incorrect);
    }
    int r = 0;
    for (char ch = '1'; ch <= '9'; ch++) {
      r += f(s + ch, n);
    }
    return r;
  }

  pair<int, int> guess(const string& b) {
    const int n = int(a.size());
    int c1 = 0;
    vector<int> count(10, 0);
    vector<bool> closed(n, false);
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i]) {
        c1 += 1;
        closed[i] = true;
      } else {
        count[a[i] - '0'] += 1;
      }
    }
    int c2 = 0;
    for (int i = 0; i < n; i++) {
      if (closed[i]) continue;
      if (count[b[i] - '0'] > 0) {
        c2 += 1;
        count[b[i] - '0'] -= 1;
      }
    }
    return {c1, c2};
  }

  MasterMindHelper(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  string a;
  int correct, incorrect;
};