#include "../../../../library/io.hpp"
#include "../../../../library/string_utils.hpp"

using namespace io;

class MusicYourWay {
public:
  void solve() {
    std::string attr;
    std::getline(in, attr);
    std::vector attributes = split_at_space(attr);
    std::unordered_map<std::string, std::size_t> where;
    for (std::size_t i = 0; i < attributes.size(); i++) {
      where[attributes[i]] = i;
    }
    int n;
    in >> n;
    std::vector songs(n, std::vector<std::string>(attributes.size()));
    int steps;
    std_read(in, songs, steps);
    while (steps-- != 0) {
      in >> attr;
      std::stable_sort(songs.begin(), songs.end(), [&](const std::vector<std::string>& a, const std::vector<std::string>& b) {
        return a[where[attr]] < b[where[attr]];
      });
      out << attributes << '\n';
      for (const auto& song : songs) {
        out << song << '\n';
      }
      if (steps != 0) out << '\n';
    }
  }

  MusicYourWay(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};