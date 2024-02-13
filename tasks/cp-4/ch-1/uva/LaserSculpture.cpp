#include <bits/stdc++.h>
using namespace std;

class LaserSculpture {
public:
  void solve() {
    for (int h, l; in >> h >> l && h; ) {
      vector<int> fh(1, h);
      int r = 0;
      while (l--) {
        int a;
        in >> a;
        fh.push_back(a);
        int i = int(fh.size()) - 1;
        if (fh[i - 1] > fh[i]) {
          r += fh[i - 1] - fh[i];
        }
      }
      out << r << '\n';
    }
  }

  LaserSculpture(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};