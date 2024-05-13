#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>

#include "../../../../library/arabic_roman_map.hpp"

class RomanNumerals {
public:
  void solveOne(const int arabic) {
    int r = 0;
    std::string roman = m_map[arabic];
    for (const char ch : roman) {
      r += m_cnt[ch];
    }
    out << r << '\n';
  }

  void solve() {
    for (int arabic; in >> arabic; solveOne(arabic));
  }

  RomanNumerals(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;

  std::unordered_map<char, int> m_cnt = {
    {'I', 1},
    {'V', 2},
    {'X', 2},
    {'L', 2},
    {'C', 2},
    {'D', 3},
    {'M', 4}
  };
  arabic_roman_map m_map;
};