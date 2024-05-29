#include <bits/stdc++.h>
#include "../../../../library/vector_utils.hpp"
using namespace std;

class PokerHand {
public:
  void solve() {
    vector<string> cards(N);
    in >> cards;
    vector<int> freq(M, 0);
    for (const auto& card : cards) {
      freq[card[0]]++;
    }
    out << *max_element(begin(freq), end(freq)) << '\n';
  }

  PokerHand(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const int N = 5;
  const int M = 100;
};