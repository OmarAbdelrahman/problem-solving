#include <bits/stdc++.h>

#include "../library/vector_utils.hpp"
using namespace std;

class BChayaCalendar {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int> a(n);
    in >> a;
    int year = a[0];
    for (int i = 1; i < n; i++) {
      if (a[i] <= year) {
        int m = 1;
        while (a[i] * m <= year) {
          m += 1;
        }
        year = a[i] * m;
      } else {
        year = a[i];
      }
    }
    out << year << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  BChayaCalendar(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};