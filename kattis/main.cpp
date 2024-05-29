#include <iostream>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <ratio>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <map>
#include <deque>
#include <sstream>
#include <vector>

#include "../kattis/chrono-playground.hpp"
#include "../kattis/ratio-playground.hpp"
#include "../kattis/templates-playground.hpp"
#include "../library/char_utils.hpp"
#include "../library/vector_utils.hpp"
#include "../library/deque_utils.hpp"

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

struct test_t
{
  std::string input;
  std::string output;
  bool active;
  bool has_output;
};

bool check(std::string expected, std::string actual)
{
  while (!expected.empty() && isspace(*--expected.end()))
    expected.erase(--expected.end());
  while (!actual.empty() && isspace(*--actual.end()))
    actual.erase(--actual.end());
  return expected == actual;
}

void test_runner()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::vector<test_t> tests = {
    {
      "Dear Sally,\n   Please, please do it--1 would 4\nMary very, 1 much.   And 4 6\n8 everything in 5's power to make\n14 pay off for you.\n   -- Thank 2 18 18--\n0\n",
      "Dear Sally,\n   Please, please do it--it would please\nMary very, very much.   And Mary would\ndo everything in Mary's power to make\nit pay off for you.\n   -- Thank you very much--\n",
      true,
      true
    },
  };
  bool allOK = true;
  int testID = 0;
  std::cout << std::fixed;
  double maxTime = 0.0;
  for (const test_t& test: tests) {
    std::cout << "test_t #" << ++testID << std::endl;
    std::cout << "Input: \n" << test.input << std::endl;
    if (test.has_output) {
      std::cout << "Expected output: \n" << test.output << std::endl;
    } else {
      std::cout << "Expected output: \n" << "N/A" << std::endl;
    }
    if (test.active) {
      std::stringstream in(test.input);
      std::ostringstream out;
      std::clock_t start = std::clock();
      //Uncompress solver(in, out);
      //solver.solve();
      std::clock_t finish = std::clock();
      double currentTime = double(finish - start) / CLOCKS_PER_SEC;
      maxTime = std::max(currentTime, maxTime);
      std::cout << "Actual output: \n" << out.str() << std::endl;
      if (test.has_output) {
        bool result = check(test.output, out.str());
        allOK = allOK && result;
        std::cout << "Result: " << (result ? "OK" : "Wrong answer") << std::endl;
      }
      std::cout << "Time: " << currentTime << std::endl;
    } else {
      std::cout << "SKIPPED\n";
    }
    std::cout << std::endl;
  }
  if (allOK) {
    std::cout << "All OK" << std::endl;
  } else {
    std::cout << "Some cases failed" << std::endl;
  }
  std::cout << "Maximal time: " << maxTime << "s." << std::endl;
}

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  //std::ifstream fin(R"(C:\Users\omara\CLionProjects\problem-solving\kattis\in.txt)");
  //fin.close();
  std::vector v = {1, 2, 3};

  v -= 2;
  std::cout << v << '\n';
  v += 3;
  std::cout << v << '\n';

  return 0;
}
