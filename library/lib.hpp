#include "iostream"
#include "vector"

template<typename U, typename V>
std::istream& operator >> (std::istream& in, std::pair<U, V>& p) {
  return in >> p.first >> p.second;
}

template<typename U, typename V>
std::ostream& operator << (std::ostream& out, const std::pair<U, V>& p) {
  return out << p.first << ' ' << p.second;
}

template<typename T>
std::istream& operator >> (std::istream& in, std::vector<T>& v) {
  for (auto& vi : v) in >> vi;
  return in;
}

template<typename T>
std::ostream& operator << (std::ostream& out, const std::vector<T>& v) {
  const int n = static_cast<int>(v.size());
  for (int i = 0; i < n; i++) {
    if (i > 0) out << ' ';
    out << v[i];
  }
  return out;
}

template<typename T_vector>
void print_vector_h(std::ostream& out, const T_vector& v, const bool& new_line = false) {
  const int n = static_cast<int>(v.size());
  for (int i = 0; i < n; i++) {
    if (i > 0) out << ' ';
    out << v[i];
  }
  if (new_line) out << '\n';
}

template<typename T_vector>
void print_vector_v(std::ostream& out, const T_vector& v, const bool& new_line = false) {
  const int n = static_cast<int>(v.size());
  for (int i = 0; i < n; i++) {
    out << v[i] << '\n';
  }
  if (new_line) out << '\n';
}

template<typename U, typename V>
void print_pretty_pair(std::ostream& out, const std::pair<U, V>& p, const bool& new_line = false) {
  out << '{' << p.first << ", " << p.second << '}';
  if (new_line) out << '\n';
}