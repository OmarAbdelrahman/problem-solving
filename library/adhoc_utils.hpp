using direction = std::pair<int, int>;
using position = std::pair<int, int>;
using directions = std::vector<direction>;

const direction RIGHT = {0, 1};
const direction LEFT = {0, -1};
const direction UP = {-1, 0};
const direction DOWN = {1, 0};

const direction BOTTOM_LEFT = {1, 1};
const direction BOTTOM_RIGHT = {1, -1};
const direction TOP_LEFT = {-1, 1};
const direction TOP_RIGHT = {-1, -1};

// N, E, S, W
directions _simple_adjacent = {UP, RIGHT, DOWN, LEFT};
directions _all_adjacent = {UP, RIGHT, DOWN, LEFT, BOTTOM_LEFT, BOTTOM_RIGHT, TOP_LEFT, TOP_RIGHT};

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
    const int nx = x + dir.first;
    const int ny = y + dir.second;
    if (inside(nx, ny, height, width))
      f(nx, ny);
  }
}
