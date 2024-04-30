#include <bits/stdc++.h>

using namespace std;

class GetStraight {
public:
  struct card_t {
    string card;

    card_t() = default;

    explicit card_t(string c): card(std::move(c)) { }

    inline int rank() const {
      switch (card[0]) {
        case 'A': return 0;
        case 'T': return 9;
        case 'J': return 10;
        case 'Q': return 11;
        case 'K': return 12;
        default: return card[0] - '0' - 1;
      }
    }
  };

  void solve() {
    for (vector<string> str_cards(N); in >> str_cards[0] && str_cards[0] != "#"; ) {
      for (int i = 1; i < N; i++) {
        in >> str_cards[i];
      }
      vector<card_t> cards(N);
      for (int i = 0; i < N; i++) {
        cards[i] = card_t(str_cards[i]);
      }
      int no_change_score = score(cards) * DECK_MINUS_N - DECK_MINUS_N;
      int best_score = no_change_score;
      string changed_card;
      for (int which = 0; which < N; which++) {
        int try_score = -DECK_MINUS_N * 2;
        card_t original = cards[which];
        for (const card_t& card : deck) {
          if (in_deck(card, cards)) continue;
          cards[which] = card;
          try_score += score(cards);
          cards[which] = original;
        }
        if (try_score > best_score) {
          best_score = try_score;
          changed_card = original.card;
        }
      }
      if (best_score > no_change_score) {
        out << "Exchange " << changed_card << '\n';
      } else {
        out << "Stay" << '\n';
      }
    }
  }

  static inline bool in_deck(const card_t& card, const vector<card_t>& cards) {
    return any_of(begin(cards), end(cards), [&](const card_t& other) { return card.card == other.card; });
  }

  int score(const vector<card_t>& cards) {
    vector<int> count(SUIT_N, 0);
    for (const card_t& card : cards) count[card.rank()] += 1;
    if (run_of_five(count)) return 100;
    if (run_of_four(count)) return 10;
    if (run_of_three_and_two(count)) return 5;
    if (run_of_three(count)) return 3;
    if (run_of_two_and_two(count)) return 1;
    return 0;
  }

  inline bool run_of_five(vector<int> count) {
    for (int i = 0; i < SUIT_N; i++) {
      int run = 0;
      for (int j = 0; j < 5; j++)
        run += count[(i + j) % SUIT_N] > 0;
      if (run == 5) return true;
    }
    return false;
  }

  inline bool run_of_four(vector<int> count) {
    for (int i = 0; i < SUIT_N; i++) {
      int run = 0;
      for (int j = 0; j < 4; j++)
        run += count[(i + j) % SUIT_N] > 0;
      if (run == 4) return true;
    }
    return false;
  }

  inline bool run_of_three_and_two(vector<int> count) {
    bool three = false;
    for (int i = 0; i < SUIT_N; i++) {
      int run = 0;
      for (int j = 0; j < 3; j++)
        run += count[(i + j) % SUIT_N] > 0;
      if (run == 3) {
        three = true;
        for (int j = 0; j < 3; j++)
          count[(i + j) % SUIT_N] -= 1;
        break;
      }
    }
    if (three) {
      for (int i = 0; i < SUIT_N; i++) {
        int run = 0;
        for (int j = 0; j < 2; j++)
          run += count[(i + j) % SUIT_N] > 0;
        if (run == 2)
          return true;
      }
    }
    return false;
  }

  inline bool run_of_three(vector<int> count) {
    for (int i = 0; i < SUIT_N; i++) {
      int run = 0;
      for (int j = 0; j < 3; j++)
        run += count[(i + j) % SUIT_N] > 0;
      if (run == 3)
        return true;
    }
    return false;
  }

  inline bool run_of_two_and_two(vector<int> count) {
    bool two = false;
    for (int i = 0; i < SUIT_N; i++) {
      int run = 0;
      for (int j = 0; j < 2; j++)
        run += count[(i + j) % SUIT_N] > 0;
      if (run == 2) {
        two = true;
        for (int j = 0; j < 2; j++)
          count[(i + j) % SUIT_N] -= 1;
        break;
      }
    }
    if (two) {
      for (int i = 0; i < SUIT_N; i++) {
        int run = 0;
        for (int j = 0; j < 2; j++)
          run += count[(i + j) % SUIT_N] > 0;
        if (run == 2)
          return true;
      }
    }
    return false;
  }

  GetStraight(istream& in, ostream& out)
    : in(in), out(out) {
    for (const char& suit : suits) {
      for (const char& rank : ranks) {
        string card = string(1, rank) + string(1, suit);
        deck.emplace_back(card);
      }
    }
  }

private:
  ostream& out;
  istream& in;

  const string suits = "SHDC";
  const string ranks = "A23456789TJQK";

  const int N = 5;
  const int SUIT_N = 13;
  const int DECK_MINUS_N = 47;

  vector<card_t> deck;
};