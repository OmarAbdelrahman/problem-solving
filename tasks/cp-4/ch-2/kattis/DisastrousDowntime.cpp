#include <iostream>
#include <vector>
#include <cmath>

#include "../../../../library/vector_utils.hpp"

class DisastrousDowntime {
public:
  void solve() {
    int n, request_per_server;
    in >> n >> request_per_server;
    std::vector<int> request_time(n);
    in >> request_time;
    std::vector<int> count_running(N);
    for (int ti : request_time) {
      count_running[ti] += 1;
    }
    int peak_running = 0;
    int currently_running = 0;
    for (int i = 0; i < N; i++) {
      currently_running += count_running[i];
      if (i >= TTL) {
        currently_running -= count_running[i - TTL];
      }
      peak_running = std::max(peak_running, currently_running);
    }
    out << int(std::ceil(peak_running * 1.0 / request_per_server * 1.0)) << '\n';
  }

  DisastrousDowntime(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;

  const int N = 100000 + 1;
  const int TTL = 1000;
};