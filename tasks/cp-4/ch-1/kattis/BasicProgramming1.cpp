#include <bits/stdc++.h>

#include "../../../../library/io.hpp"

using namespace std;
using namespace io;

class BasicProgramming1 {
public:
  void solve() {
    int n, t;
    in >> n >> t;
    vector<int64_t> a(n);
    in >> a;
    if (t == 1) {
      out << 7 << '\n';
    } else if (t == 2) {
      out << value_conditional(a[0] > a[1], {value_conditional(a[0] == a[1], {"Smaller", "Equal"}), "Bigger"}) << '\n';
    } else if (t == 3) {
      sort(begin(a), begin(a) + 3);
      out << a[1] << '\n';
    } else if (t == 4) {
      out << accumulate(begin(a), end(a), INT64_C(0)) << '\n';
    } else if (t == 5) {
      int64_t s = 0;
      for (const int64_t& ai : a) {
        if (ai % 2 == 0) {
          s += ai;
        }
      }
      out << s << '\n';
    } else if (t == 6) {
      for (int64_t& ai : a) {
        ai %= 26;
        out << char(ai + int64_t('a'));
      }
      out << '\n';
    } else {
      int i = 0;
      vector<bool> v(n + 1, false);
      while (true) {
        if (i >= n) {
          out << "Out" << '\n';
          break;
        }
        if (v[i]) {
          out << "Cyclic" << '\n';
          break;
        }
        if (i == n - 1) {
          out << "Done" << '\n';
          break;
        }
        v[i] = true;
        i = a[i];
      }
    }
  }

  template<typename T = std::string>
  T value_conditional(const bool condition, const std::array<T, 2>& options) {
    return options[condition];
  }

  BasicProgramming1(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};