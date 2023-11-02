#include <bits/stdc++.h>
using namespace std;

using int64 = int64_t;
using uint64 = uint64_t;
using uint = uint32_t;

class DReverseMadness {
public:

  void solveOne(istream &is, ostream &os) {
    int n, k; is >> n >> k;
    string s; is >> s;
    vector<int> l(k), r(k);
    for (int& li : l) {
      is >> li;
      li--;
    }
    for (int& ri : r) {
      is >> ri;
      ri--;
    }
    int q; is >> q;
    vector<int> c(n, 0);
    while (q-- != 0) {
      int x; is >> x;
      c[x - 1] ^= 1;
    }
    for (int i = 0; i < k; i++) {
      int rev = 0;
      for (int j = l[i]; j < l[i] + r[i] - j; j++) {
        rev ^= c[j] ^ c[l[i] + r[i] - j];
        if (rev != 0) {
          swap(s[j], s[l[i] + r[i] - j]);
        }
      }
    }
    os << s << '\n';
  }

  void solve(istream &is, ostream &os) {
    int t; is >> t;
    for (int i = 0; i < t; i++) {
      solveOne(is, os);
    }
  }
};