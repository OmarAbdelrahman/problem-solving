#include <bits/stdc++.h>

using namespace std;

class ShufflingAlong {
public:
  void solve() {
    int n;
    in >> n;
    string direction;
    in >> direction;
    vector<int> t(n), d(n);
    iota(begin(t), end(t), 0);
    d = t;
    const int m = n / 2;
    auto out_shuffle = [&]() -> void {
      vector<int> a = d;
      if (n % 2 == 0) {
        for (int i = 0, at = 0; i < m; i++) {
          a[at++] = d[0 + i];
          a[at++] = d[m + i];
        }
      } else {
        for (int i = 0, at = 0; i < m + 1; i++) {
          a[at++] = d[0 + i];
          if (i < m)
            a[at++] = d[m + 1 + i];
        }
      }
      a.swap(d);
    };
    auto in_shuffle = [&]() -> void {
      vector<int> a = d;
      if (n % 2 == 0) {
        for (int i = 0, at = 0; i < m; i++) {
          a[at++] = d[m + i];
          a[at++] = d[0 + i];
        }
      } else {
        for (int i = 0, at = 0; i < m + 1; i++) {
          a[at++] = d[m + i];
          if (i < m)
            a[at++] = d[0 + i];
        }
      }
      a.swap(d);
    };
    auto do_shuffle = [&]() -> void {
      direction[0] == 'o' ? out_shuffle() : in_shuffle();
    };
    int r = 0;
    do {
      do_shuffle();
      r += 1;
    } while (d != t);
    out << r << '\n';
  }

  ShufflingAlong(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};