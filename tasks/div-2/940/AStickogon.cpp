#include <iostream>
#include <vector>
#include <algorithm>

#include "../library/vector_io.hpp"

class AStickogon {
public:
  void solveOne() {
    int n;
    in >> n;
    std::vector<int> a(n);
    in >> a;
    std::vector<int> freq(M, 0);
    for (const int ai : a) {
      freq[ai]++;
    }
    int r = 0;
    for (int i = 0; i < M; i++) {
      if (freq[i] < 3) continue;
      r += freq[i] / 3;
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

  AStickogon(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;

  static const int M = 101;
};
