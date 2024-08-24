#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

#include "../../../../library/vector_utils.hpp"

/*
 * Compute max cost for every answer.
 * Get the minimum cost of the computed costs.
 * Print any answer that has a cost equal to the minimum cost.
 */
class FlagQuiz {
public:
  void solve() {
    std::string question;
    std::getline(in, question);
    int n;
    in >> n;
    in.ignore();
    std::vector<std::string> original(n);
    std::vector<std::vector<std::string>> answers(n);
    for (int i = 0; i < n; i++) {
      std::getline(in, original[i]);
      answers[i] = split(original[i]);
    }
    std::vector<int> changes(n, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        changes[i] = std::max(changes[i], count_changes(answers[i], answers[j]));
      }
    }
    int small = *std::min_element(changes.begin(), changes.end());
    vector_for_each_with_index(original, [&](const int i, const auto& answer) {
      if (changes[i] == small) {
        out << answer << '\n';
      }
    });
  }

  std::vector<std::string> split(const std::string& str) {
    const int n = str.size();
    std::vector<std::string> res;
    std::string part;
    for (int i = 0; i < n; i++) {
      if (str[i] == ',') {
        res.emplace_back(part);
        i += 1;
        part.clear();
      } else if (i == n - 1) {
        res.emplace_back(part + str[i]);
      } else {
        part += str[i];
      }
    }
    return res;
  }

  int count_changes(const std::vector<std::string>& a, const std::vector<std::string>& b) {
    int count = 0;
    for (std::size_t i = 0; i < a.size(); i++) {
      count += a[i] != b[i];
    }
    return count;
  }

  FlagQuiz(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};