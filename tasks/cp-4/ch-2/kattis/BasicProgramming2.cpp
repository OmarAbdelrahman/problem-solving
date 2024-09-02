#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

#include "../../../../library/vector_utils.hpp"

/*
 * Straight forward. The only trick is the first case.
 * Make sure not to do it in O(n^2)
 */
class BasicProgramming2 {
public:
  void solve() {
    int n, action;
    in >> n >> action;

    v = std::vector<uint32_t>(n);
    in >> v;

    std::sort(v.begin(), v.end());

    if (action == 1) out << one();
    else if (action == 2) out << two();
    else if (action == 3) out << three();
    else if (action == 4) out << four();
    else out << five();

    out << '\n';
  }

  std::string one() {
    std::unordered_set<uint32_t> s;
    for (const auto vi : v) {
      s.emplace(vi);
    }
    for (const auto vi : v) {
      if (s.contains(TARGET - vi)) {
        return "Yes";
      }
    }
    return "No";
  }

  std::string two() {
    for (int i = 1; i < v.size(); i++) {
      if (v[i] == v[i - 1]) {
        return "Contains duplicate";
      }
    }
    return "Unique";
  }

  int three() {
    const int boundary = int(v.size()) / 2;
    std::unordered_map<uint32_t, int> freq;
    for (const auto vi : v) {
      freq[vi] += 1;
    }
    for (const auto& [n, f] : freq) {
      if (f > boundary) {
        return int(n);
      }
    }
    return -1;
  }

  std::vector<uint32_t> four() {
    const int size = int(v.size());
    const int mid = size / 2;
    if (size % 2 == 0) {
      return {v[mid - 1], v[mid]};
    }
    return {v[mid]};
  }

  std::vector<uint32_t> five() {
    std::vector<uint32_t> res;
    for (const auto vi : v) {
      if (vi >= 100 && vi < 1000) {
        res.emplace_back(vi);
      }
    }
    return res;
  }

  BasicProgramming2(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;

  std::vector<uint32_t> v;

  const uint32_t TARGET = 7777;
};