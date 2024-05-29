#include <bits/stdc++.h>

#include "../library/vector_utils.hpp"
#include "../library/debug.hpp"
using namespace std;

vector<int> beat_count;

struct card_t {
  int rank, suit, i;

  card_t() = default;

  card_t(int r, int s): rank(r), suit(s) { }

  card_t(int r, char s): rank(r), suit(s - 'A') { }

  inline bool can_beat(const card_t& other, int trump) const {
    if (suit == trump) {
      return other.suit == trump ? rank > other.rank : true;
    } else {
      return suit == other.suit ? rank > other.rank : false;
    }
  }

  friend istream& operator >> (istream& i, card_t& c) {
    int r;
    char s;
    i >> r >> s;
    c.rank = r;
    c.suit = s - 'A';
    return i;
  }

  friend ostream& operator << (ostream& o, const card_t& c) {
    return o << c.rank << char(c.suit + 'A');
  }

  bool operator < (const card_t& other) const {
    return beat_count[i] < beat_count[other.i];
  }
};

class DCardGame {
public:
  void solveOne() {
    int n;
    char T;
    in >> n >> T;
    int CARDS = 2 * n;
    vector<card_t> deck(CARDS);
    for (int i = 0; i < CARDS; i++) {
      in >> deck[i];
      deck[i].i = i;
    }
    int trump = T - 'A';
    beat_count = vector<int>(CARDS, 0);
    for (int i = 0; i < CARDS; i++) {
      const auto& c1 = deck[i];
      for (int j = 0; j < CARDS; j++) {
        if (i == j) continue;
        if (c1.can_beat(deck[j], trump)) {
          beat_count[i] += 1;
        }
      }
    }
    sort(begin(deck), end(deck));
    debug(beat_count);
    debug(deck);
    int count = accumulate(begin(beat_count), end(beat_count), 0);
    int need = (n * (n + 1)) / 2;
    if (count < need) {
      out << "IMPOSSIBLE" << '\n';
    } else {
      for (int i = 0; i < n; i++) {
        out << deck[i] << ' ' << deck[i + n] << '\n';
      }
    }
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  DCardGame(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};