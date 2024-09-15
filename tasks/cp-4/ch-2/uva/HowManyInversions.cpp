#include "../../../../library/io.hpp"

using namespace io;

class HowManyInversions {
public:
  void solve() {
    for (int n; in >> n && n != 0; ) {
      std::vector<int> a(n);
      in >> a;
      out << merge_sort(0, n, a) << '\n';
    }
  }

  uint64_t merge_sort(const int l, const int r, std::vector<int>& a) {
    if (l + 1 >= r) return 0;
    int m = l + (r - l) / 2;
    const auto L = merge_sort(l, m, a);
    const auto R = merge_sort(m, r, a);
    return L + R + do_merge(l, m, r, a);
  }

  uint64_t do_merge(const int l, const int m, const int r, std::vector<int>& a) {
    std::vector<int> L(m - l), R(r - m);
    for (std::size_t i = 0; i < L.size(); i++) {
      L[i] = a[l + i];
    }
    for (std::size_t i = 0; i < R.size(); i++) {
      R[i] = a[m + i];
    }
    std::size_t at_l = 0, at_r = 0;
    uint64_t inv = 0, i;
    for (i = l; i < r && at_l < L.size() && at_r < R.size(); i++) {
      if (L[at_l] < R[at_r]) {
        a[i] = L[at_l];
        at_l += 1;
      } else {
        a[i] = R[at_r];
        at_r += 1;
        inv += ((m - l) - at_l);
      }
    }
    while (at_l < L.size()) {
      a[i++] = L[at_l++];
    }
    while (at_r < R.size()) {
      a[i++] = R[at_r++];
    }
    return inv;
  }

  HowManyInversions(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};