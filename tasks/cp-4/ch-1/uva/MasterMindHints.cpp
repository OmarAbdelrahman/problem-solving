#include <bits/stdc++.h>

using namespace std;

class MasterMindHints {
public:
  void solve() {
    for (int _ = 1, n; in >> n && n > 0; _++) {
      vector<int> a(n);
      for (int& ai : a) in >> ai;
      out << "Game " << _ << ":" << '\n';
      while (true) {
        vector<int> b(n);
        for (int& bi : b) in >> bi;
        if (count(begin(b), end(b), 0) == n) {
          break;
        }
        int correct = 0;
        vector<int> count(10, 0);
        vector<bool> closed(n, false);
        for (int i = 0; i < n; i++) {
          if (a[i] == b[i]) {
            correct += 1;
            closed[i] = true;
          } else {
            count[a[i]] += 1;
          }
        }
        int incorrect = 0;
        for (int i = 0; i < n; i++) {
          if (closed[i]) continue;
          if (count[b[i]] > 0) {
            incorrect += 1;
            count[b[i]] -= 1;
          }
        }
        out << "    (" << correct << ',' << incorrect << ')' << '\n';
      }
    }
  }

  MasterMindHints(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};