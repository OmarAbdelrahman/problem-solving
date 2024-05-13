#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

#include "../library/arabic_roman_map.hpp"

class TheReturnOfTheRomanEmpire {
public:
  void solveOne(const std::string& roman) {
    if (m_map.roman_exists(roman))
      out << m_map[roman] << '\n';
    else
      out << "This is not a valid number" << '\n';
  }

  void solve() {
    for (std::string roman; getline(in, roman); solveOne(roman));
  }

  TheReturnOfTheRomanEmpire(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;

  arabic_roman_map m_map;
};