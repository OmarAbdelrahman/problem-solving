#include <bits/stdc++.h>

using namespace std;

class HangmanJudge {
public:
  void solve() {
    for (int _; in >> _; ) {
      if (_ == -1) break;
      string a, b;
      in >> a >> b;
      vector<bool> used(A, false);
      vector<bool> hang(A, false);
      int r = 1;
      for (char bi : b) {
        if (!hang[bi - 'a'] && !used[bi - 'a']) {
          if (a.find(bi) == string::npos)
            hang[bi - 'a'] = true;
          else
            used[bi - 'a'] = true;
        }
        if (count(begin(hang), end(hang), true) == D) {
          r = 0;
          break;
        }
        if (all_of(begin(a), end(a), [&](char ch) { return used[ch - 'a']; })) {
          r = 2;
          break;
        }
      }
      out << "Round " << _ << '\n';
      array<string, R> result = {"You lose.", "You chickened out.", "You win."};
      out << result[r] << '\n';
    }
  }

  HangmanJudge(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const int A = 26;
  const int D = 7;
  static const int R = 3;
};