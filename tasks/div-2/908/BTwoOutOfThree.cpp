#include <bits/stdc++.h>
using namespace std;

#define _size(a) (int) (a).size()

class BTwoOutOfThree {
public:
  void solveOne(istream& in, ostream& out) {
    int n;
    in >> n;
    vector<int> a(n);
    for (int& ai : a) {
      in >> ai;
    }
    vector<int> f(N, 0), b(n, 1);
    int what = 2;
    for (int i = 0; i < n; i++) {
      f[a[i]]++;
      if (f[a[i]] == 2) {
        b[i] = what;
        what++;
        if (what == 4) {
          break;
        }
      }
    }
    if (what != 4) {
      out << -1 << '\n';
      return;
    }
    for (int i = 0; i < n; i++) {
      out << b[i] << " \n"[i == n - 1];
    }
  }

  void solve(istream& in, ostream& out) {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne(in, out);
    }
  }

private:
  const int N = 101;
};