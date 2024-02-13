#include <bits/stdc++.h>

using namespace std;

class AProblemsolvingLog {
public:
  void solveOne() {
    int n;
    in >> n;
    string s;
    in >> s;
    vector<int> freq(ALPHABET, 0);
    for (const char& ch : s) {
      freq[ch - 'A']++;
    }
    int result = 0;
    for (int i = 0; i < ALPHABET; i++) {
      if (freq[i] > i) {
        result++;
      }
    }
    out << result << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  AProblemsolvingLog(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const int ALPHABET = 26;
};