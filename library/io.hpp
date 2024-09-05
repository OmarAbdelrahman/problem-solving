template<typename... Ts>
inline void read(std::istream& in, Ts&... ts) {
  (in >> ... >> ts);
}
template<typename T>
inline void print(std::ostream& out, const T& t) { out << t << '\n'; }
template<typename H, typename... T>
inline void print(std::ostream& out, const H& h, const T&... t) {
  print(out, h);
  print(out, t...);
}
template<typename T>
inline void print_one_line(std::ostream& out, const T& t) { out << t; }
template<typename H, typename... T>
inline void print_one_line(std::ostream& out, const H& h, const T&... t) {
  print_one_line(out, h);
  out << ' ';
  print_one_line(out, t...);
  if (sizeof...(t) == 1) out << '\n';
}
