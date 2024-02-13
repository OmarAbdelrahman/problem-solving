#include <bits/stdc++.h>

using namespace std;

class DUnnaturalLanguageProcessing {
public:
  void solveOne() {
    int n;
    in >> n;
    string str;
    in >> str;
    string result;
    for (int i = n - 1; i >= 0; ) {
      for (int c = 0; c < 3 - (int) vowel(str[i]); c++) {
        if (i - c < 0) continue;
        result += str[i - c];
      }
      i -= (3 - (int) vowel(str[i]));
      if (i > 0) result += '.';
    }
    ranges::reverse(result);
    out << result << '\n';
  }

  bool vowel(const char& ch) {
    return ch == 'a' || ch == 'e';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  DUnnaturalLanguageProcessing(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const int V = 2;
  const int C = 3;
};