#ifndef PAIR_UTILS
#define PAIR_UTILS

template<typename U, typename V, typename T>
inline std::pair<U, V> operator+(const std::pair<U, V>& v, const T x) { return {v.first + x, v.second + x}; }
template<typename U, typename V, typename T>
inline std::pair<U, V> operator-(const std::pair<U, V>& v, const T x) { return {v.first - x, v.second - x}; }
template<typename U, typename V, typename T>
inline std::pair<U, V> operator*(const std::pair<U, V>& v, const T x) { return {v.first * x, v.second * x}; }
template<typename U, typename V, typename T>
inline std::pair<U, V> operator/(const std::pair<U, V>& v, const T x) { return {v.first / x, v.second / x}; }

template<typename U, typename V, typename T> inline void operator+=(std::pair<U, V>& v, const T x) { v.first += x, v.second += x; }
template<typename U, typename V, typename T> inline void operator-=(std::pair<U, V>& v, const T x) { v.first -= x, v.second -= x; }
template<typename U, typename V, typename T> inline void operator*=(std::pair<U, V>& v, const T x) { v.first *= x, v.second *= x; }
template<typename U, typename V, typename T> inline void operator/=(std::pair<U, V>& v, const T x) { v.first /= x, v.second /= x; }

template<typename U, typename V, typename A, typename B>
inline std::pair<U, V> operator+(const std::pair<U, V>& l, const std::pair<A, B>& r) { return {l.first + r.first, l.second + r.second}; }
template<typename U, typename V, typename A, typename B>
inline std::pair<U, V> operator-(const std::pair<U, V>& l, const std::pair<A, B>& r) { return {l.first - r.first, l.second - r.second}; }
template<typename U, typename V, typename A, typename B>
inline std::pair<U, V> operator*(const std::pair<U, V>& l, const std::pair<A, B>& r) { return {l.first * r.first, l.second * r.second}; }
template<typename U, typename V, typename A, typename B>
inline std::pair<U, V> operator/(const std::pair<U, V>& l, const std::pair<A, B>& r) { return {l.first / r.first, l.second / r.second}; }

template<typename U, typename V, typename A, typename B> inline void operator+=(std::pair<U, V>& l, const std::pair<A, B>& r) {
  l.first += r.first, l.second += r.second;
}
template<typename U, typename V, typename A, typename B> inline void operator-=(std::pair<U, V>& l, const std::pair<A, B>& r) {
  l.first -= r.first, l.second -= r.second;
}
template<typename U, typename V, typename A, typename B> inline void operator*=(std::pair<U, V>& l, const std::pair<A, B>& r) {
  l.first *= r.first, l.second *= r.second;
}
template<typename U, typename V, typename A, typename B> inline void operator/=(std::pair<U, V>& l, const std::pair<A, B>& r) {
  l.first /= r.first, l.second /= r.second;
}

template<typename U, typename V> inline std::tuple<U, V> as_tuple(const std::pair<U, V>& p) { return {p.first, p.second}; }
template<typename U, typename V> inline std::pair<U, V> from_tuple(const std::tuple<U, V>& t) { return {std::get<0>(t), std::get<1>(t)}; }

template<typename U, typename V>
void print_pretty_pair(std::ostream& out, const std::pair<U, V>& p, const bool new_line = true) {
  out << '(' << p.first << ", " << p.second << ')';
  if (new_line) out << '\n';
}

#endif
