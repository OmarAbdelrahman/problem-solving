#include <bits/stdc++.h>
#include "../../../library/vector_io.hpp"

using namespace std;

class BCollectingGame {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int> a(n);
    in >> a;
    vector<pair<int, int>> a_i(n);
    for (int i = 0; i < n; i++) {
      a_i[i] = {a[i], i};
    }
    sort(begin(a_i), end(a_i));
    vector<int> result(n);
    int64_t sum = a_i[0].first;
    int pi = 0;
    for (int i = 1; i < n; i++) {
      if (sum < a_i[i].first) {
        for (int j = pi; j < i; j++) {
          result[a_i[j].second] = i - 1;
          pi = i;
        }
      }
      sum += a_i[i].first;
    }
    for (int i = pi; i < n; i++) {
      result[a_i[i].second] = n - 1;
    }
    out << result << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  BCollectingGame(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};