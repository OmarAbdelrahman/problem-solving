#include <bits/stdc++.h>

using namespace std;

class BYetAnotherCoinProblem {
public:
  void solveOne() {
    int n;
    in >> n;
    int r = int(1e9);
    for (int ones = 0; ones <= 2; ones++)
      for (int threes = 0; threes <= 1; threes++)
        for (int sixes = 0; sixes <= 4; sixes++)
          for (int tens = 0; tens <= 2; tens++) {
            int without = 1 * ones + 3 * threes + 6 * sixes + 10 * tens;
            int rem = n - without;
            if (rem % 15 || without > n) continue;
            r = min(r, ones + threes + sixes + tens + (rem / 15));
          }
    out << r << '\n';
  }

  void solveTwo() {
    int n;
    in >> n;
    if (n < 10)
      out << count(n) << '\n';
    else if (n < 20)
      out << min(count(n), count(n - 10) + 1) << '\n';
    else
      out << min({count(n), count(n - 10) + 1, count(n - 20) + 2}) << '\n';
  }

  inline int count(int n) {
    int c = 0;
    c += n / 15;
    n %= 15;
    c += n / 6;
    n %= 6;
    c += n / 3;
    n %= 3;
    c += n;
    return c;
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveTwo();
    }
  }

  BYetAnotherCoinProblem(istream& in, ostream& out)
    : in(in), out(out) {

    coins = {1, 3, 6, 10, 15};
    dp = vector<int>(N, inf);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
      for (int coin : coins) {
        if (i + coin < N) {
          dp[i + coin] = min(dp[i + coin], dp[i] + 1);
        }
      }
    }
  }

private:
  ostream& out;
  istream& in;

  vector<int> dp;
  vector<int> coins;

  const int N = int(1e6);
  const int inf = int(1e9);
};