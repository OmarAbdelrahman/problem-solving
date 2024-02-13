#include <bits/stdc++.h>

using namespace std;

class FizzBuzz {
public:
  void solve() {
    int x, y, n;
    in >> x >> y >> n;
    for (int i = 1; i <= n; i++) {
      if (i % x == 0 && i % y == 0) {
        out << "FizzBuzz";
      } else if (i % x == 0) {
        out << "Fizz";
      } else if (i % y == 0) {
        out << "Buzz";
      } else {
        out << i;
      }
      out << '\n';
    }
  }

  FizzBuzz(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};