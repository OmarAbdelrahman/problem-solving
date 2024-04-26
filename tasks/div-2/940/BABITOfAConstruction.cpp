#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <tuple>

#include "../library/debug.hpp"
#include "../library/vector_io.hpp"

class BABITOfAConstruction {
public:
  void solveOne() {
    int n, k;
    in >> n >> k;
    if (n == 1) {
      out << k << '\n';
      return;
    }
    int r = 0;
    {
      int p = 1;
      while (r + p <= k) {
        r += p;
        p *= 2;
      }
    }
    out << r << ' ' << k - r;
    for (int i = 0; i < n - 2; i++) {
      out << " 0";
    }
    out << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }
  
  BABITOfAConstruction(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::string to_binary(int n) {
    std::string r;
    while (n != 0) {
      r += (n % 2 == 0 ? "0" : "1");
      n /= 2;
    }
    std::reverse(r.begin(), r.end());
    return r;
  }

  inline int count_bits(const int n) {
    return __builtin_popcount(n);
  }

  std::istream& in;
  std::ostream& out;
};
