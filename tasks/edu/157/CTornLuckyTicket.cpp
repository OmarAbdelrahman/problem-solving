#include <bits/stdc++.h>
using namespace std;

#define _size(a) (int) (a).size()

class CTornLuckyTicket {
public:
  void solveOne(istream& in, ostream& out) {
    int n;
    in >> n;
    vector<string> s(n);
    for (string& si : s) {
      in >> si;
    }
    vector<vector<string>> s_by_len(M_LEN + 1);
    for (const string& si : s) {
      s_by_len[_size(si)].emplace_back(si);
    }
    auto aggregate = [&](const string& str, const int where, const int half) -> int {
      int r = 0;
      for (int i = 0; i < _size(str); i++) {
        int sgn = where + i < half ? -1 : 1;
        r += sgn * (str[i] - '0');
      }
      return r;
    };
    int64_t r = 0;
    for (int a = 1; a <= M_LEN; a++) {
      for (int b = a % 2 != 0 ? 1 : 2; b <= M_LEN; b += 2) {
        assert((a + b) % 2 == 0);
        unordered_map<int, int> freq;
        const int half = (a + b) / 2;
        for (const string& si : s_by_len[a]) {
          freq[aggregate(si, 0, half)] += 1;
        }
        for (const string& si : s_by_len[b]) {
          r += freq[-aggregate(si, a, half)];
        }
      }
    }
    out << r << '\n';
  }

  void solve(istream& in, ostream& out) {
    int nt = 1;
    for (int _ = 0; _ < nt; _++) {
      solveOne(in, out);
    }
  }

private:
  const int M_LEN = 5;
};