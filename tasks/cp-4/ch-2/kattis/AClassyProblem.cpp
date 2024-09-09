#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>
#include <sstream>
#include <cstddef>

#include "../../../../library/string_utils.hpp"
#include "../../../../library/io.hpp"

/*
 * The only trick is to add middle class if no 10 class are offered.
 */
class AClassyProblem {
public:
  struct someone {
    std::string name;
    std::vector<uint8_t> rank;

    someone() = default;

    someone(const std::string& _name, const std::string& _class)
      : name(_name.substr(0, _name.size() - 1))
    {
      rank.clear();
      foreach_token_split_at_space(_class, [&](const std::string& token) {
        if (token == "upper") rank.emplace_back(3);
        if (token == "middle") rank.emplace_back(2);
        if (token == "lower") rank.emplace_back(1);
      });
      std::reverse(rank.begin(), rank.end());
      while (rank.size() < 10) {
        rank.emplace_back(2);
      }
    }

    bool operator<(const someone& other) const {
      for (std::size_t i = 0; i < rank.size(); i++)
        if (rank[i] != other.rank[i])
          return rank[i] > other.rank[i];
      return name < other.name;
    }
  };

  void solve() {
    int nt;
    in >> nt;
    while (nt-- != 0) {
      int n;
      in >> n;
      std::vector<someone> people(n);
      for (int i = 0; i < n; i++) {
        std::string name, _class, ignore;
        read(in, name, _class, ignore);
        for (char& ch : _class) {
          if (ch == '-') {
            ch = ' ';
          }
        }
        people[i] = someone(name, _class);
      }
      std::sort(people.begin(), people.end());
      for (const auto& one : people) {
        out << one.name << '\n';
      }
      out << std::string(30, '=') << '\n';
    }
  }

  AClassyProblem(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};