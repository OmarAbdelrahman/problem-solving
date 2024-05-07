#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>
#include <cmath>
#include <array>
#include <vector>

#include "../../../../library/arabic_roman_map.hpp"

class RomanDigititis {
public:
  void solveOne(const int pages) {
    std::unordered_map<char, int> freq;
    for (int page = 1; page <= pages; page++) {
      const std::string roman = m_map[page];
      for (const char& c : roman) {
        freq[std::tolower(c)] += 1;
      }
    }
    out << pages << ": " << freq['i'] << " i, " << freq['v'] << " v, " << freq['x'] << " x, " << freq['l'] << " l, " << freq['c'] << " c" << '\n';
  }

  void solveOneDp(const int pages) {
    out << pages << ": " << m_dp[pages][0] << " i, " << m_dp[pages][1] << " v, " << m_dp[pages][2] << " x, " << m_dp[pages][3] << " l, " << m_dp[pages][4] << " c" << '\n';
  }

  void solve() {
    for (int pages; in >> pages && pages; solveOneDp(pages));
  }

  RomanDigititis(std::istream& in, std::ostream& out)
    : in(in), out(out) 
  {
    m_dp = std::vector<std::array<int, FREQ_S>>(PAGES, std::array<int, FREQ_S>{});
    for (int page = 1; page < PAGES; page++) {
      for (int i = 0; i < FREQ_S; i++) {
        m_dp[page][i] = m_dp[page - 1][i];
      }
      const std::string roman = m_map[page];
      for (const char& ch : roman) {
        switch (ch) {
          case 'I': m_dp[page][0] += 1; break;
          case 'V': m_dp[page][1] += 1; break;
          case 'X': m_dp[page][2] += 1; break;
          case 'L': m_dp[page][3] += 1; break;
          case 'C': m_dp[page][4] += 1; break;
        }
      }
    }
  }

private:
  std::istream& in;
  std::ostream& out;

  static const std::size_t FREQ_S = 5;
  static const std::size_t PAGES = 101;

  arabic_roman_map m_map;
  std::vector<std::array<int, FREQ_S>> m_dp;
};
