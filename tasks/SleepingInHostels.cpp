#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

class SleepingInHostels {
public:
  void solveOne(const std::string& layout) {
    std::vector<int> beds_at;
    for (std::size_t i = 0; i < layout.size(); i++) {
      if (layout[i] == 'X') {
        beds_at.push_back(i);
      }
    }
    std::vector<int> dist(1, beds_at.front());
    for (std::size_t i = 1; i < beds_at.size(); i++) {
      dist.push_back(beds_at[i] - beds_at[i - 1] - 1);
    }
    dist.push_back(int(layout.size()) - 1 - beds_at.back());
    int edges = std::max(beds_at.front() - 1, int(layout.size()) - beds_at.back() - 2);
    int largest_dist = *std::max_element(dist.begin(), dist.end());
    if (largest_dist % 2 == 0) {
      out << std::max(edges, largest_dist / 2 - 1) << '\n';
    } else {
      out << std::max(edges, largest_dist / 2) << '\n';
    }
  }

  void solve() {
    for (std::string layout; in >> layout; solveOne(layout));
  }

  SleepingInHostels(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};