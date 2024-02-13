#include <bits/stdc++.h>

using namespace std;

class OneChickenPerPerson {
public:
  void solve() {
    int n, m;
    in >> n >> m;
    if (n < m) {
      if (m - n == 1)
        out << "Dr. Chaz will have 1 piece of chicken left over!" << '\n';
      else
        out << "Dr. Chaz will have " << m - n << " pieces of chicken left over!" << '\n';
    } else {
      if (n - m == 1)
        out << "Dr. Chaz needs 1 more piece of chicken!" << '\n';
      else
        out << "Dr. Chaz needs " << n - m << " more pieces of chicken!" << '\n';
    }
  }

  OneChickenPerPerson(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};