#include <bits/stdc++.h>

#include "../../../library/vector_utils.hpp"
#include "../../../library/io_utils.hpp"
using namespace std;

class BArrayFix {
public:
  void solveAfterContest() {
    int n;
    in >> n;
    vector<int> a(n);
    in >> a;
    bool fail = false;
    int prev = 0;
    for (const int ai : a) {
      if (ai >= 10 && first(ai) >= prev && last(ai) >= first(ai)) {
        prev = last(ai);
      } else {
        if (ai >= prev) {
          prev = ai;
        } else {
          fail = true;
          break;
        }
      }
    }
    print_yes_or_no(out, !fail);
  }

  void solveOne() {
    int n;
    in >> n;
    vector<int> a(n);
    in >> a;
    bool ok = true;
    for (int i = n - 1; i > 0 && ok; i--) {
      if (a[i] >= a[i - 1]) continue;
      int ai = a[i];
      int ai_1 = a[i - 1];
      if (ai_1 < 10) ok = false;
      if (first(ai_1) > last(ai_1) || ai < last(ai_1))
        ok = false;
      a[i - 1] = ai_1 / 10;
    }
    print_yes_or_no(out, ok);
  }

  inline int first(const int& n) {
    return n / 10;
  }

  inline int last(const int& n) {
    return n % 10;
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveAfterContest();
    }
  }

  BArrayFix(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};