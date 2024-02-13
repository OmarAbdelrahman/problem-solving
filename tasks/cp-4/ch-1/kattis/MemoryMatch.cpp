#include <bits/stdc++.h>

using namespace std;

//#include "../library/debug.hpp"

class MemoryMatch {
public:
  void solve() {
    int n, m;
    in >> n >> m;
    unordered_map<string, int> id;
    vector<int> which_uid(n, -1);
    unordered_set<int> ones;
    unordered_set<int> wanted_twos;
    int remaining_cards = n;
    auto update = [&](int c, int p) -> void {
      if (ones.count(p)) {
        if (which_uid[p] != c) {
          ones.erase(p);
          which_uid[p] = -1;
          wanted_twos.insert(p);
          remaining_cards -= 1;
        }
      } else if (!wanted_twos.count(p)) {
        ones.insert(p);
        which_uid[p] = c;
        remaining_cards -= 1;
      }
    };
    auto remove = [&](int p) -> void {
      if (wanted_twos.count(p)) {
        wanted_twos.erase(p);
      } else if (ones.count(p)) {
        ones.erase(p);
        remaining_cards -= 1;
      } else {
        remaining_cards -= 2;
      }
    };
    int uid = 1;
    for (int i = 0; i < m; i++) {
      int a, b;
      string an, bn;
      in >> a >> b >> an >> bn;
      if (!id[an]) id[an] = uid++;
      if (!id[bn]) id[bn] = uid++;
      if (id[an] == id[bn]) {
        remove(id[an]);
      } else {
        update(a - 1, id[an]);
        update(b - 1, id[bn]);
      }
    }
    int r = size(wanted_twos);
    if (remaining_cards == 2 && empty(ones))
      r += 1;
    else if (remaining_cards == size(ones)) {
      r += remaining_cards;
    }
    out << r << '\n';
  }

  MemoryMatch(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};