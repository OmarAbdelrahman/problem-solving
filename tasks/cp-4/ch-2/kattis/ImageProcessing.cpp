#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>

#include "../../../../library/vector_utils.hpp"

/*
 * Direct simulation no tricks
 */

class ImageProcessing {
public:
  void solve() {
    int h, w, n, m;
    in >> h >> w >> n >> m;
    std::vector image(h, std::vector<int>(w));
    in >> image;
    std::vector kernel(n, std::vector<int>(m));
    in >> kernel;

    std::reverse(kernel.begin(), kernel.end());
    for (auto& row : kernel) {
      std::reverse(row.begin(), row.end());
    }

    std::vector result(h - n + 1, std::vector<int>(w - m + 1));
    for (std::size_t i = 0; i < result.size(); i++) {
      for (std::size_t j = 0; j < result[i].size(); j++) {
        int product_sum = 0;
        for (int ik = 0; ik < n; ik++) {
          for (int jk = 0; jk < m; jk++) {
            product_sum += kernel[ik][jk] * image[i + ik][j + jk];
          }
        }
        result[i][j] = product_sum;
      }
    }

    for (const auto& row : result) {
      out << row << '\n';
    }
  }

  ImageProcessing(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};