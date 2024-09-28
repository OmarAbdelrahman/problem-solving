#include "../../../../library/io.hpp"

#include "../../../../library/vector_utils.hpp"

using namespace io;

/**
 * This one was a bit hard to solve.
 * It can be solved using fenwick tree which will O(n log n) but I haven't reached to fenwick tree section in the book yet.
 *
 * I used the explanation in this link
 * https://techblogofmrd.blogspot.com/2014/01/linear-solution-to-bread-shuffling.html to solve it in O(n).
 */
class BreadSorting {
public:
  void solve() {
    int n;
    in >> n;
    std::vector<int> to_sort(n), to_match(n);
    std_read(in, to_sort, to_match);
    to_sort -= 1;
    to_match -= 1;
    std::vector<int> index(n);
    for (int i = 0; i < n; i++) {
      index[to_sort[i]] = i;
    }
    for (int i = 0; i < n - 2; i++) {
      const int trg_pos = i;
      const int src_pos = index[to_match[i]];
      const int dist = src_pos - trg_pos;
      if (dist == 0) {
        continue;
      } else if (dist == 1) {
        paddle(trg_pos, to_sort, index);
        paddle(trg_pos, to_sort, index);
      } else if (dist == 2) {
        paddle(trg_pos, to_sort, index);
      } else {
        // 6 5 4 3 2 1 0
        // 0 6 5 4 3 2 1 <- using paddle to the end, since it is odd no need to swap adjacent elements in the end.
        swap(trg_pos, src_pos, to_sort, index);
        // 0 5 4 3 1 2 6 <- using paddle to the other side, since it is even,
        // we need to swap adjacent elements to make 6 reach the end.
        swap(src_pos - 1, src_pos - 2, to_sort, index);
      }
    }
    if (to_sort.back() == to_match.back()) {
      out << "Possible" << '\n';
    } else {
      out << "Impossible" << '\n';
    }
  }

  void paddle(const int at, std::vector<int>& to_sort, std::vector<int>& index) {
    swap(at, at + 2, to_sort, index);
    swap(at + 1, at + 2, to_sort, index);
  }

  void swap(const int f, const int t, std::vector<int>& to_sort, std::vector<int>& index) {
    std::swap(index[to_sort[f]], index[to_sort[t]]);
    std::swap(to_sort[f], to_sort[t]);
  }

  BreadSorting(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};