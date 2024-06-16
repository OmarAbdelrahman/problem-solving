template<typename U, typename V>
std::istream& operator >> (std::istream& in, std::pair<U, V>& p) {
  return in >> p.first >> p.second;
}

template<typename U, typename V>
std::ostream& operator << (std::ostream& out, const std::pair<U, V>& p) {
  return out << p.first << ' ' << p.second;
}

template<typename U, typename V>
void print_pretty_pair(std::ostream& out, const std::pair<U, V>& p, const bool& new_line = true) {
  out << '{' << p.first << ", " << p.second << '}';
  if (new_line) out << '\n';
}

template<typename T>
inline void operator += (std::pair<T, T>& v, const T& x) {
  v.first += x;
  v.second += x;
}

template<typename T>
inline void operator -= (std::pair<T, T>& v, const T& x) {
  v.first -= x;
  v.second -= x;
}

template<typename T>
inline void operator *= (std::pair<T, T>& v, const T& x) {
  v.first *= x;
  v.second *= x;
}

template<typename T>
inline void operator /= (std::pair<T, T>& v, const T& x) {
  assert(x != 0);
  v.first /= x;
  v.second /= x;
}
