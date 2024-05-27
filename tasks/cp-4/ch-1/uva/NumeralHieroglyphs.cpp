#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdint>

class NumeralHieroglyphs {
public:
  void solveOne(std::string& hieroglyph) {
    std::vector<int> order;
    std::unordered_map<char, int> freq;
    for (const char& ch : hieroglyph) {
      freq[ch] += 1;
      order.emplace_back(value[ch]);
      if (freq[ch] > 9) {
        out << "error" << '\n';
        return;
      }
    }
    if (!is_sorted(order)) {
      out << "error" << '\n';
      return;
    }
    sort(hieroglyph.begin(), hieroglyph.end(), [&](const char a, const char b) -> bool {
      return value[a] > value[b];
    });
    int64_t r = 0;
    for (const char& ch : hieroglyph) {
      r += value[ch];
    }
    out << r << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      std::string hieroglyph;
      in >> hieroglyph;
      solveOne(hieroglyph);
    }
  }

  NumeralHieroglyphs(std::istream& in, std::ostream& out)
    : in(in), out(out)
  {
    value = {
      {'B', 1}, {'U', 10}, {'S', 100}, {'P', 1000},
      {'F', 10000}, {'T', 100000}, {'M', 1000000}
    };
  }

private:
  bool is_sorted(std::vector<int> a) {
    if (!std::is_sorted(a.begin(), a.end())) {
      std::reverse(a.begin(), a.end());
      return std::is_sorted(a.begin(), a.end());
    }
    return true;
  }

private:
  std::istream& in;
  std::ostream& out;

  std::unordered_map<char, int> value;
};