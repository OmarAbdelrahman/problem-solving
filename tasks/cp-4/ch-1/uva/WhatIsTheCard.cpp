#include <bits/stdc++.h>

using namespace std;

class WhatIsTheCard {
public:
  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      vector<string> cards(CARDS);
      for (string& card : cards) {
        in >> card;
      }
      int Y = 0;
      int where = CARDS - TOP - 1;
      vector<bool> removed(CARDS, false);
      for (int step = 0; step < STEPS; step++) {
        int X = f(cards[where]);
        Y += X;
        removed[where--] = true;
        for (int i = 0; i < MAX - X; i++) {
          removed[where--] = true;
        }
      }
      for (int i = 0, at = 0; i < CARDS; i++) {
        if (removed[i]) continue;
        at += 1;
        if (at == Y) {
          print_case(out, _, cards[i]);
          break;
        }
      }
    }
  }

  void solve1() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      vector<string> cards(CARDS);
      for (string& card : cards) {
        in >> card;
      }
      int Y = 0;
      for (int steps = 0; steps < STEPS; steps++) {
        vector<string> hand;
        for (int i = 0; i < TOP; i++) {
          hand.push_back(cards.back());
          cards.pop_back();
        }
        reverse(begin(hand), end(hand));
        int X = f(cards.back());
        cards.pop_back();
        Y += X;
        for (int i = 0; i < MAX - X; i++) {
          cards.pop_back();
        }
        copy(begin(hand), end(hand), back_inserter(cards));
      }
      print_case(out, _, cards[Y - 1]);
    }
  }

  inline int f(const string& card) {
    return isdigit(card[0]) ? card[0] - '0' : 10;
  }

  template<typename T>
  void print_case(std::ostream& o, const int case_i, const T& result, const bool new_line = true) {
    o << "Case " << case_i << ": " << result << (new_line ? '\n' : char());
  }

  WhatIsTheCard(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const int CARDS = 52;
  const int STEPS = 3;
  const int TOP = 25;
  const int MAX = 10;
};