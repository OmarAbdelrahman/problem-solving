#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

class Dyslectionary {
public:
  void solve() {
    std::vector<std::string> v;
    for (std::string s; std::getline(in, s); ) {
      if (s.empty()) {
        do_sort(v);
        out << '\n';
        v.clear();
        continue;
      }
      v.emplace_back(s);
    }
    do_sort(v);
  }

  void do_sort(std::vector<std::string>& v) {
    int w = 0;
    for (auto& vi : v) {
      std::reverse(vi.begin(), vi.end());
      if (vi.size() > w) w = vi.size();
    }
    std::sort(v.begin(), v.end());
    for (auto& vi : v) {
      std::reverse(vi.begin(), vi.end());
    }
    for (const auto& vi : v) {
      out << std::setw(w) << vi << '\n';
    }
  }

  Dyslectionary(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};