#include <bits/stdc++.h>
#include "../library/suffix_array.hpp"
#include "../library/sparse_table.hpp"
#include "../library/vector_io.hpp"
#include "../library/pair_io.hpp"
#include "../library/string_utils.hpp"
#include "../library/io_utils.hpp"
using namespace std;

class DBorders {
public:
  void solveOne() {
    string s;
    in >> s;
    suffix_array_t sa(s);
    int64_t n = ssize(s);
    int64_t result = n * (n + 1) / 2;
    vector<int> lcp = sa._lcp();
    vector<string> subs = substrings_slow(s);
    cout << subs << '\n';
    for (int i = 0; i < sa.size(); i++) {
      cout << i << ' ' << lcp[i] << ' ' << sa[i] << ' ' << sa.suffix(i) << '\n';
    }
    sparse_table<int> sp(lcp, [](const int& a, const int& b) { return min(a, b); });
    int max_border_length = *max_element(begin(lcp), end(lcp));
    for (int i = 0; i < sa.size(); i++) {
      for (int j = i + 1; j < sa.size(); j++) {
        int64_t m_lcp = sp.get(i + (i != j), j);
        result += m_lcp;
        if (m_lcp > 0) {
          int pi = sa[i];
          int pj = sa[j];
          if (pi > pj) swap(pi, pj);
          print_pretty_pair(cout, make_pair(pi, pj));
          cout << " = " << m_lcp << " = " << sa.suffix(i).substr(0, m_lcp) << endl;
        }
      }
    }
    out << result << '\n';
  }

  void solve() {
    int nt = 1;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  DBorders(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  istream& in;
  ostream& out;
};