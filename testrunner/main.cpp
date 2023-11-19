#include "../tasks/CYarikAndArray.cpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <ctime>

namespace jhelper {

  struct Test {
    std::string input;
    std::string output;
    bool active;
    bool has_output;
  };

  bool check(std::string expected, std::string actual) {
    while (!expected.empty() && isspace(*--expected.end()))
      expected.erase(--expected.end());
    while (!actual.empty() && isspace(*--actual.end()))
      actual.erase(--actual.end());
    return expected == actual;
  }

} // namespace jhelper

int main() {
	std::vector<jhelper::Test> tests = {
		{"7\n5\n1 2 3 4 5\n4\n9 9 8 8\n6\n-1 4 -1 0 5 -4\n4\n-1 2 4 -3\n1\n-1000\n3\n101 -99 101\n20\n-10 5 -8 10 6 -10 7 9 -2 -6 7 2 -4 6 -1 7 -6 -7 4 1\n", "15\n17\n8\n4\n-1000\n101\n10\n", true, true},
	};
	bool allOK = true;
	int testID = 0;
	std::cout << std::fixed;
	double maxTime = 0.0;
	for (const jhelper::Test& test: tests) {
		std::cout << "Test #" << ++testID << std::endl;
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
			CYarikAndArray solver(in, out);
      solver.solve();
			std::clock_t finish = std::clock();
			double currentTime = double(finish - start) / CLOCKS_PER_SEC;
			maxTime = std::max(currentTime, maxTime);
			std::cout << "Actual output: \n" << out.str() << std::endl;
			if (test.has_output) {
				bool result = jhelper::check(test.output, out.str());
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
	return 0;
}
