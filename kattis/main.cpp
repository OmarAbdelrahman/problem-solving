#include <iostream>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <ratio>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <map>

#include "../kattis/chrono-playground.hpp"
#include "../kattis/ratio-playground.hpp"
#include "../kattis/templates-playground.hpp"

inline bool is_perfect_square(int64_t x)
{
  auto sr = int64_t(std::round(std::sqrt(x)));
  return (sr * sr == x);
}

inline void clamp_test()
{
  const int low = 3, high = 5;
  for (int i = 0; i < 10; i++) {
    std::cout << i << ' ' << std::clamp(i, low, high) << '\n';
  }
}

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::map<int, char> itc;
  std::map<char, int> cti;

  int i = 0;
  for (char ch = 'a'; ch <= 'z'; ch++) {
    itc[i] = ch;
    cti[ch] = i++;
  }

  std::ifstream fin(R"(C:\Users\omara\CLionProjects\problem-solving\kattis\in.txt)");
  for (std::string s; std::getline(fin, s); ) {
    for (char ch : s) {
      if (std::isalpha(ch)) {
        char cc = std::tolower(ch);
        std::cout << itc[(cti[cc] + 6) % 26];
      } else
        std::cout << ch;
    }
    std::cout << std::endl;
  }
  fin.close();
  return 0;
}
