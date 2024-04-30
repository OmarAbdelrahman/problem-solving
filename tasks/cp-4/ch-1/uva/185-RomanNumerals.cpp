#include <iostream>
#include <string>
#include <unordered_map>
#include <array>
#include <algorithm>
#include <cmath>

class roman_numerals_t {
public:
  roman_numerals_t() {
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
  
public:
  std::unordered_map<int, std::string> roman;
  std::unordered_map<std::string, int> arabic;

private:
  const std::string numerals = "IVXLCDM";
};

class small_roman_numerals_t {
public:
  small_roman_numerals_t() = default;

  small_roman_numerals_t(const int inclusive_limit) {
    for (int i = 1; i <= inclusive_limit; i++) {
      const std::string _roman = arabic_to_roman(i);
      arabic[_roman] = i;
      roman[i] = _roman;
    }
  }

  small_roman_numerals_t(const small_roman_numerals_t& other) {
    roman = other.roman;
    arabic = other.arabic;
  }

  small_roman_numerals_t(small_roman_numerals_t&& other) {
    roman = std::move(other.roman);
    arabic = std::move(other.arabic);
  }

  small_roman_numerals_t& operator=(const small_roman_numerals_t& other) {
    roman = other.roman;
    arabic = other.arabic;
    return *this;
  }
  
private:
  std::string arabic_to_roman(int num) {
    std::string ans;
    for (int i = 0; i < 13; i++) {
      while (num >= val[i]) {
        num -= val[i];
        ans += ch[i];
      }
    }
    return ans;
  }

public:
  std::unordered_map<std::string, int> arabic;
  std::unordered_map<int, std::string> roman;

private:
  static const std::size_t Size = 13;

  const std::array<std::string, Size> ch = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  const std::array<int, Size> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
};

class RomanNumerals {
public:
  void solveOne(const std::string& input) {
    r1 = r2 = res = "";
    values.fill(-1);
    used.fill(false);
    
    const std::size_t plus = input.find('+');
    const std::size_t equal = input.find('=');
    for (std::size_t i = 0; i < input.length(); i++) {
      if (i == plus || i == equal) continue;
      if (i < plus) r1 += input[i];
      else if (i < equal) r2 += input[i];
      else res += input[i];
    }

    if (numerals.arabic[r1] + numerals.arabic[r2] == numerals.arabic[res]) {
      out << "Correct ";
    } else {
      out << "Incorrect ";
    }

    if (r1.length() > res.length() || r2.length() > res.length()) {
      out << "impossible" << '\n';
      return;
    }

    std::reverse(r1.begin(), r1.end());
    std::reverse(r2.begin(), r2.end());
    std::reverse(res.begin(), res.end());
    
    const int count = dfs(0, 0);
    if (count == 0) {
      out << "impossible" << '\n';
    } else if (count == 1) {
      out << "valid" << '\n';
    } else {
      out << "ambiguous" << '\n';
    }
  }

  void solve() {
    for (std::string input; in >> input && input.front() != '#'; ) {
      solveOne(input);
    }
  }

  RomanNumerals(std::istream& in, std::ostream& out)
    : in(in), out(out) {}

private:
  int dfs(const int at, const int carry) {
    if (at == res.length()) {
      return carry == 0 && values[r1.back()] != 0 && values[r2.back()] != 0 && values[res.back()] != 0;
    }

    std::array<bool, SUMS> default_initiated{};
    default_initiated.fill(false);

    auto init = [&](const int _at, const std::string& _r, const int where, int& _val) {
      if (_at >= _r.length()) {
        _val = 0;
        default_initiated[where] = true;
      } else if (values[_r[_at]] != -1) {
        _val = values[_r[_at]];
        default_initiated[where] = true;
      }
    };
    
    auto _define = [&](const int _at, const std::string& _r, const int where, const int digit, int& _val) {
      if (!default_initiated[where]) {
        values[_r[_at]] = digit;
        _val = digit;
        used[digit] = true;
      }
    };

    int count = 0;
    int a = -1, b = -1;

    init(at, r1, 0, a);
    for (int i = (default_initiated[0] ? 9 : 0); i < 10; i++) {
      if (!default_initiated[0] && used[i]) {
        continue;
      }
      _define(at, r1, 0, i, a);
      init(at, r2, 1, b);
      for (int j = (default_initiated[1] ? 9 : 0); j < 10; j++) {
        if (!default_initiated[1] && used[j]) {
          continue;
        }
        _define(at, r2, 1, j, b);
        const int sum = a + b + carry;
        const int c = sum % 10;
        if (values[res[at]] == -1 && !used[c]) {
          used[c] = true;
          values[res[at]] = c;
          count += dfs(at + 1, sum / 10);
          values[res[at]] = -1;
          used[c] = false;
        } else if (values[res[at]] == c) {
          count += dfs(at + 1, sum / 10);
        }
        if (!default_initiated[1]) {
          values[r2[at]] = -1;
          used[j] = false;
        }
      }
      if (!default_initiated[0]) {
        values[r1[at]] = -1;
        used[i] = false;
      }
    }
    return count;
  }

private:
  std::istream& in;
  std::ostream& out;

  static const std::size_t CHARS = 100;
  static const std::size_t DIGITS = 10;
  static const std::size_t SUMS = 2;

  std::array<int, CHARS> values;
  std::array<bool, DIGITS> used;
  roman_numerals_t numerals;
  std::string r1, r2, res;
};
