#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

class RomanNumerals {
public:
  void solveOne(const std::string& number) {
    if (std::isdigit(number.front())) {
      out << roman[std::stoi(number)] << '\n';
    } else {
      out << arabic[number] << '\n';
    }
  }

  void solve() {
    for (std::string number; in >> number; solveOne(number));
  }

  RomanNumerals(std::istream& in, std::ostream& out)
    : in(in), out(out) 
  {
    roman[1] = "I", roman[5] = "V";
    arabic[roman[1]] = 1, arabic[roman[5]] = 5;
    roman[10] = "X", roman[50] = "L";
    arabic[roman[10]] = 10, arabic[roman[50]] = 50;
    roman[100] = "C", roman[500] = "D";
    arabic[roman[100]] = 100, arabic[roman[500]] = 500;
    roman[1000] = "M", arabic[roman[1000]] = 1000;
    for (int i = 2; i <= 3; ++i) {
      roman[i] = roman[i - 1] + "I";
      arabic[roman[i]] = i;
      roman[i * 10] = roman[(i - 1) * 10] + "X";
      arabic[roman[i * 10]] = i * 10;
      roman[i * 100] = roman[(i - 1) * 100] + "C";
      arabic[roman[i * 100]] = i * 100;
      roman[i * 1000] = roman[(i - 1) * 1000] + "M";
      arabic[roman[i * 1000]] = i * 1000;
    }
    for (int i = 0; i < 3; ++i) {
      int v = (int)std::pow(10.0, i);
      roman[4 * v] = roman[v] + roman[5 * v];
      arabic[roman[4 * v]] = 4 * v;
      roman[9 * v] = roman[v] + roman[v * 10];
      arabic[roman[9 * v]] = 9 * v;
      for (int j = 6; j <= 8; ++j) {
        roman[j * v] = roman[5 * v] + roman[(j - 5) * v];
        arabic[roman[j * v]] = j * v;
      }
    }
    for (int i = 10; i < 100; i += 10) {
      for (int j = 1; j < 10; ++j) {
        roman[i + j] = roman[i] + roman[j];
        arabic[roman[i + j]] = i + j;
      }
    }
    for (int i = 100; i < 1000; i += 100) {
      for (int j = 1; j < 100; ++j) {
        roman[i + j] = roman[i] + roman[j];
        arabic[roman[i + j]] = i + j;
      }
    }
    for (int i = 1000; i <= 4000; i += 1000) {
      for (int j = 1; j <= 1000; ++j) {
        roman[i + j] = roman[i] + roman[j];
        arabic[roman[i + j]] = i + j;
      }
    }
  }

private:
  std::istream& in;
  std::ostream& out;

  std::unordered_map<int, std::string> roman;
  std::unordered_map<std::string, int> arabic;

  const std::string numerals = "IVXLCDM";
};
