#include <bits/stdc++.h>

using namespace std;

class GuessingGame {
public:
  void solve() {
    int high = 11;
    int low = 0;
    for (int guess; in >> guess; ) {
      in.ignore();
      if (guess == 0) break;
      string pos;
      getline(in, pos);
      if (pos[0] == 'r') {
        if (guess > low && guess < high) {
          out << "Stan may be honest" << '\n';
        } else {
          out << "Stan is dishonest" << '\n';
        }
        high = 11;
        low = 0;
      } else {
        if (pos[4] == 'h') high = min(high, guess);
        else low = max(low, guess);
      }
    }
  }

  GuessingGame(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const int N = 11;
};