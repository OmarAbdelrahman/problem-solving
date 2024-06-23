#include <iostream>
#include <vector>

class APileOfBoxes {
public:
  struct box_t {
    int height;
    int inner_height;
    std::vector<box_t> inner;

    explicit box_t(int _height): height(_height), inner_height(0) {
      inner.clear();
    }

    bool insert(const box_t& other) {
      for (box_t& box : inner) {
        if (box.insert(other)) {
          return true;
        }
      }
      if (other.height > height - inner_height) {
        return false;
      }
      inner.emplace_back(other);
      inner_height += other.height;
      return true;
    }
  };

  void solve() {
    for (int n; in >> n; ) {
      box_t container(1 << 20);
      while (n-- != 0) {
        int height;
        in >> height;
        box_t box(height);
        container.insert(box);
      }
      out << container.inner_height << '\n';
    }
  }

  APileOfBoxes(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};