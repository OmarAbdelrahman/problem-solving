#include <bits/stdc++.h>

#include "../library/vector_io.hpp"
#include "../library/io_utils.hpp"
#include "../library/debug.hpp"
using namespace std;

int64_t _sieve_size;
bitset<10000010> bs;
vector<int64_t> p;

void sieve(int64_t upperbound) {
  _sieve_size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = false;
  for (int64_t i = 2; i < _sieve_size; ++i) {
    if (bs[i]) {
      for (int64_t j = i * i; j < _sieve_size; j += i) {
        bs[j] = false;
      }
      p.push_back(i);
    }
  }
}

bool is_prime(int64_t N) {
  if (N < _sieve_size) return bs[N];
  for (int i = 0; i < size(p) && p[i] * p[i] <= N; ++i)
    if (N % p[i] == 0)
      return false;
  return true;
}

class DTurtleTenacityContinualMods {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int> a(n);
    in >> a;
    int ps = 0;
    for (int ai : a) {
      ps += is_prime(ai);
    }
    print_yes_or_no(out, ps == n / 2 || ps == (n + 1) / 2);
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  DTurtleTenacityContinualMods(istream& in, ostream& out)
    : in(in), out(out) {

    sieve(int(1e7) + 1);
  }

private:
  ostream& out;
  istream& in;

};
