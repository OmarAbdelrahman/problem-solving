template<typename T>
inline void read(std::istream& in, T& t) { in >> t; }
template<typename H, typename... T>
inline void read(std::istream& in, H& h, T&... t) {
  read(in, h);
  read(in, t...);
}
template<typename T>
inline void print_vertically(std::ostream& out, const T& t) { out << t << '\n'; }
template<typename H, typename... T>
inline void print_vertically(std::ostream& out, const H& h, const T&... t) {
  print_vertically(out, h);
  print_vertically(out, t...);
}
template<typename T>
inline void print_horizontally(std::ostream& out, const T& t) { out << t; }
template<typename H, typename... T>
inline void print_horizontally(std::ostream& out, const H& h, const T&... t) {
  print_horizontally(out, h);
  out << ' ';
  print_horizontally(out, t...);
  if (sizeof...(t) == 1) out << '\n';
}