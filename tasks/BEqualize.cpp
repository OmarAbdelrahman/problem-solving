#include <bits/stdc++.h>

#include "../library/vector_utils.hpp"
#include "../library/debug.hpp"
using namespace std;

class BEqualize {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int64_t> a(n), p(n), pv(n), pi(n, -1);
    in >> a;
    iota(begin(p), end(p), 1);
    for (int i = 0; i < n; i++) {
      pv[p[i] - 1] = n - i;
    }
    ranges::sort(a, greater{});
    set<int64_t> is_p;
    for (int i = 0; i < n; i++) {
      const int64_t ai = a[i];
      if (ai >= 1 && ai <= n && !is_p.contains(ai)) {
        is_p.insert(ai);
        pi[i] = pv[ai - 1];
      }
    }
    unordered_map<int64_t, int64_t> next;
    int e = 1;
    for (int i = 0; i < n; i++) {
      if (pi[i] != -1) {
        next[a[i]] = pi[i] - 1;
      } else {
        if (is_p.contains(a[i])) {
          pi[i] = next[a[i]];
          next[a[i]] = pi[i] - 1;
        } else {
          while (is_p.contains(e)) {
            e += 1;
          }
          pi[i] = e;
          e += 1;
        }
      }
    }
    vector<int64_t> s(n);
    for (int i = 0; i < n; i++) {
      s[i] = a[i] + pi[i];
    }
    unordered_map<int64_t, int> count;
    for (const int64_t& si : s) {
      count[si] += 1;
    }
    int r = 0;
    for (const auto& [_, c] : count) {
      r = max(r, c);
    }
    out << r << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  BEqualize(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};