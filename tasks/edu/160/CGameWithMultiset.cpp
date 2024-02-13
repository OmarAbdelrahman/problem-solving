#include <bits/stdc++.h>

using namespace std;

class CGameWithMultiset {
public:
  void solve() {
    int nt;
    in >> nt;
    vector<int> freq(SIZE, 0);
    while (nt--) {
      int ti, vi;
      in >> ti >> vi;
      if (ti == 1) {
        freq[vi]++;
      } else {
        for (int i = SIZE - 1; i >= 0; i--) {
          for (int _ = 0; _ < freq[i]; _++) {
            if (vi >= (1 << i)) {
              vi -= (1 << i);
            } else {
              break;
            }
          }
        }
        out << (vi ? "NO" : "YES") << '\n';
      }
    }
  }

  CGameWithMultiset(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const int SIZE = 30;
};