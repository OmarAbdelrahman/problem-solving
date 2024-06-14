#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

#include "../../../../library/vector_utils.hpp"

class MobileCasanova {
public:
  void solveOne(int case_i, int n) {
    std::vector<std::string> phones(n);
    in >> phones;
    std::vector<int> as_ints(n);
    for (int i = 0; i < n; i++) {
      as_ints[i] = std::stoi(phones[i]);
    }
    std::vector<std::vector<std::string>> grouped;
    grouped.emplace_back(1, phones.front());
    for (int i = 1; i < n; i++) {
      int j = i;
      while (j < n && as_ints[j] - as_ints[j - 1] == 1) {
        grouped.back().emplace_back(phones[j]);
        j += 1;
        i += 1;
      }
      if (j < n) {
        grouped.emplace_back(1, phones[j]);
      }
      i = j;
    }
    out << "Case " << case_i << ":" << '\n';
    for (const auto& group : grouped) {
      if (group.size() == 1) {
        out << group << '\n';
      } else {
        const std::string& init = group.front();
        const std::string& last = group.back();
        std::size_t at = 0;
        while (init[at] == last[at]) {
          at += 1;
        }
        out << init << '-' << last.substr(at) << '\n';
      }
    }
    out << '\n';
  }

  void solve() {
    int n;
    for (int _ = 1; in >> n && n != 0; _++) {
      solveOne(_, n);
    }
  }

  MobileCasanova(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};