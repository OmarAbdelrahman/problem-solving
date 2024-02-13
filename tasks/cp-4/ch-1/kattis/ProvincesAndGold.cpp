#include <bits/stdc++.h>

using namespace std;

class ProvincesAndGold {
public:
  void solve() {
    int g, s, c;
    in >> g >> s >> c;
    int t = g * 3 + s * 2 + c;
    vector<string> r;
    for (const auto& [str, v] : vector<pair<string, int>>{
      {"Province", 8},
      {"Duchy", 5},
      {"Estate", 2},
    }) {
      if (t >= v) r.push_back(str);
    }
    while (size(r) >= 2) {
      r.pop_back();
    }
    for (const auto& [str, v] : vector<pair<string, int>>{
      {"Gold", 6},
      {"Silver", 3},
      {"Copper", 0}
    }) {
      if (t >= v) r.push_back(str);
    }
    if (size(r) >= 2) {
      out << r[0] << " or " << r[1] << '\n';
    } else {
      out << r[0] << '\n';
    }
  }

  ProvincesAndGold(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};