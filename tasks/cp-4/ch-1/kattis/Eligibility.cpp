#include <bits/stdc++.h>

using namespace std;

class Eligibility {
public:
  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      string name, d1, d2;
      int courses;
      in >> name >> d1 >> d2 >> courses;
      int s1 = stoi(d1.substr(0, 4));
      int s2 = stoi(d2.substr(0, 4));
      out << name;
      if (s1 >= 2010 || s2 >= 1991) {
        out << " eligible" << '\n';
      } else if (courses > 40) {
        out << " ineligible" << '\n';
      } else {
        out << " coach petitions" << '\n';
      }
    }
  }

  Eligibility(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};