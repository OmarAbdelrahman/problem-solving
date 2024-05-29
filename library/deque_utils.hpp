template<typename T>
std::istream& operator >> (std::istream& in, std::deque<T>& d) {
  for (auto& it : d) in >> it;
  return in;
}

template<typename T>
std::ostream& operator << (std::ostream& out, const std::deque<T>& d) {
  const std::size_t n = std::size(d);
  for (std::size_t i = 0; i < n; i++) {
    if (i > 0) out << ' ';
    out << d[i];
  }
  return out;
}

template<typename T_deque>
void print_deque_h(std::ostream& out, const T_deque& d, const bool& new_line = true) {
  const std::size_t n = std::size(d);
  for (std::size_t i = 0; i < n; i++) {
    if (i > 0) out << ' ';
    out << d[i];
  }
  if (new_line) out << '\n';
}

template<typename T_deque>
void print_deque_v(std::ostream& out, const T_deque& d, const bool& new_line = true) {
  const std::size_t n = std::size(d);
  for (std::size_t i = 0; i < n; i++) {
    out << d[i] << '\n';
  }
  if (new_line) out << '\n';
}

template<typename T>
inline void operator += (std::deque<T>& d, const T& x) {
  for (T& di : d) di += x;
}

template<typename T>
inline void operator -= (std::deque<T>& d, const T& x) {
  for (T& di : d) di -= x;
}

template<typename T>
inline void operator *= (std::deque<T>& d, const T& x) {
  for (T& di : d) di *= x;
}

template<typename T>
inline void operator /= (std::deque<T>& d, const T& x) {
  assert(x != 0);
  for (T& di : d) di /= x;
}
