#include <bits/stdc++.h>

using namespace std;

class BGettingPoints {
public:
  void solveOne() {
    int64_t days, points, lesson, task;
    in >> days >> points >> lesson >> task;
    const int64_t available_tasks = (days + 6) / 7;
    int64_t l = 0, r = days, result = 0;
    while (l <= r) {
      const int64_t rest_days = l + (r - l) / 2LL;
      const int64_t work_days = days - rest_days;
      if (work_days * lesson + min(work_days * 2, available_tasks) * task >= points) {
        l = rest_days + 1;
        result = max(result, rest_days);
      } else {
        r = rest_days - 1;
      }
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

  BGettingPoints(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};