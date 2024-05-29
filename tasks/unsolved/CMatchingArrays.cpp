#include <bits/stdc++.h>
#include "../../library/vector_utils.hpp"

using namespace std;

class CMatchingArrays {
public:
  void solveOne() {
    int n, x;
    in >> n >> x;
    vector<int> a(n), b(n);
    in >> a;
    in >> b;
    vector<int> sorted_a = a;
    sort(begin(sorted_a), end(sorted_a));
    map<int, int> count_bigger;
    for (const int& bi : b) {
      auto lower = lower_bound(begin(sorted_a), end(sorted_a), bi);
      auto upper = upper_bound(begin(sorted_a), end(sorted_a), bi);
      int d_lower = distance(begin(sorted_a), lower);
      int d_upper = distance(begin(sorted_a), upper);
      if (d_lower == d_upper && d_lower == 0) {
        count_bigger[bi] = n;
      } else if (d_upper == n) {
        count_bigger[bi] = 0;
      } else {
        count_bigger[bi] = n - d_upper;
      }
    }
    int movable = 0;
    for (const auto& [bi, count] : count_bigger) {
      movable += (int) (count > 0);
    }
    if (x > movable || (x < n - movable && movable != n - movable)) {
      out << "NO\n";
    } else {
      out << "YES\n";
      vector<int> result;
      sort(begin(b), end(b));
      map<int, int> freq;
      for (const int& bi : b) {
        freq[bi]++;
      }
      for (const int& bi : b)  {
        if (x != 0 && count_bigger[bi] && freq[bi]) {
          result.emplace_back(bi);
          freq[bi]--;
          x--;
        }
      }
      for (const int& bi : b) {
        if (freq[bi]) {
          result.emplace_back(bi);
          freq[bi]--;
        }
      }
      out << result << '\n';
    }
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  CMatchingArrays(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};