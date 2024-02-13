#include <bits/stdc++.h>
#include "../../../library/vector_io.hpp"
using namespace std;

class BStORageRoom {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<vector<int>> M(n, vector<int>(n));
    in >> M;
    vector<int> a(n, (1 << 30) - 1);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        a[i] &= M[i][j];
        a[j] &= M[i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if ((a[i] | a[j]) != M[i][j]) {
          out << "NO" << '\n';
          return;
        }
      }
    }
    out << "YES" << '\n' << a << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  BStORageRoom(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};