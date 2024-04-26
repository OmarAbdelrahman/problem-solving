template<typename T>
std::istream& operator >> (std::istream& in, std::vector<T>& v) {
  for (auto& it : v) in >> it;
  return in;
}

template<typename T>
std::ostream& operator << (std::ostream& out, const std::vector<T>& v) {
  const std::size_t n = std::size(v);
  for (std::size_t i = 0; i < n; i++) {
    if (i > 0) out << ' ';
    out << v[i];
  }
  return out;
}

template<typename T_vector>
void print_vector_h(std::ostream& out, const T_vector& v, const bool& new_line = false) {
  const std::size_t n = std::size(v);
  for (std::size_t i = 0; i < n; i++) {
    if (i > 0) out << ' ';
    out << v[i];
  }
  if (new_line) out << '\n';
}

template<typename T_vector>
void print_vector_v(std::ostream& out, const T_vector& v, const bool& new_line = false) {
  const std::size_t n = std::size(v);
  for (std::size_t i = 0; i < n; i++) out << v[i] << '\n';
  if (new_line) out << '\n';
}
