using position = std::tuple<int, int>;
using directions = std::vector<position>;

// N, E, S, W
directions _simple_adjacent = { { {-1, 0}, {0, 1}, {1, 0}, {0, -1} } };
directions _all_adjacent = { { {-1, 0}, {0, 1}, {1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} }};

inline bool inside(const int i, const int j, const int height, const int width) {
  return i >= 0 && i < height && j >= 0 && j < width;
}

template<class Fun>
void for_each_knight(const int x, const int y, const int height, const int width, Fun&& f) {
  for (int dx = -2; dx <= 2; dx++) {
    for (int dy = -2; dy <= 2; dy++) {
      if (std::abs(dx * dy) == 2) {
        const int nx = x + dx;
        const int ny = y + dy;
        if (inside(nx, ny, height, width))
          f(nx, ny);
      }
    }
  }
}

template<class Fun>
void for_each_direction(const int x, const int y, const int height, const int width, const directions& dirs, Fun&& f) {
  for (const auto& dir : dirs) {
    const int nx = x + std::get<0>(dir);
    const int ny = y + std::get<1>(dir);
    if (inside(nx, ny, height, width))
      f(nx, ny);
  }
}
