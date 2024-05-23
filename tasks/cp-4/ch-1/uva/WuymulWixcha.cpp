#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

class WuymulWixcha {
public:
  void solveOne(const int n, const std::string& message) {
    for (const char ch : message) {
      if (is_alpha(ch)) {
        char lower = to_lower(ch);
        char encrypted = itc[negative_mod(cti[lower] + n, MOD)];
        out << (is_upper(ch) ? to_upper(encrypted) : encrypted);
      } else {
        out << ch;
      }
    }
    out << '\n';
  }

  void solve() {
    for (int n = 1; in >> n && n; n++) {
      in.ignore();
      std::string message;
      std::getline(in, message);
      solveOne(n, message);
    }
  }

  WuymulWixcha(std::istream& in, std::ostream& out)
    : in(in), out(out)
  {
    int i = 0;
    for (char ch = 'a'; ch <= 'z'; ch++) {
      itc[i] = ch;
      cti[ch] = i++;
    }
  }

private:
  inline int negative_mod(const int a, const int b) {
    return (a % b + b) % b;
  }

  inline bool is_alpha(const char ch) {
    return std::isalpha(static_cast<unsigned char>(ch));
  }

  inline char to_lower(const char ch) {
    return static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
  }

  inline bool is_upper(const char ch) {
    return std::isupper(static_cast<unsigned char>(ch));
  }

  inline char to_upper(const char ch) {
    return static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
  }

private:
  std::istream& in;
  std::ostream& out;

  std::unordered_map<int, char> itc;
  std::unordered_map<char, int> cti;

  const int MOD = 26;
};