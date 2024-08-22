template<class U, class V>
std::istream& operator>>(std::istream& in, std::pair<U, V>& p) { return in >> p.first >> p.second; }
template<class U, class V>
std::ostream& operator<<(std::ostream& out, const std::pair<U, V>& p) { return out << p.first << ' ' << p.second; }

template<class U, class V, class T>
inline std::pair<U, V> operator+(const std::pair<U, V>& v, const T x) { return {v.first + x, v.second + x}; }
template<class U, class V, class T>
inline std::pair<U, V> operator-(const std::pair<U, V>& v, const T x) { return {v.first - x, v.second - x}; }
template<class U, class V, class T>
inline std::pair<U, V> operator*(const std::pair<U, V>& v, const T x) { return {v.first * x, v.second * x}; }
template<class U, class V, class T>
inline std::pair<U, V> operator/(const std::pair<U, V>& v, const T x) { return {v.first / x, v.second / x}; }

template<class U, class V, class T> inline void operator+=(std::pair<U, V>& v, const T x) { v = v + x; }
template<class U, class V, class T> inline void operator-=(std::pair<U, V>& v, const T x) { v = v - x; }
template<class U, class V, class T> inline void operator*=(std::pair<U, V>& v, const T x) { v = v * x; }
template<class U, class V, class T> inline void operator/=(std::pair<U, V>& v, const T x) { v = v / x; }

template<class U, class V, class A, class B>
inline std::pair<U, V> operator+(const std::pair<U, V>& l, const std::pair<A, B>& r) { return {l.first + r.first, l.second + r.second}; }
template<class U, class V, class A, class B>
inline std::pair<U, V> operator-(const std::pair<U, V>& l, const std::pair<A, B>& r) { return {l.first - r.first, l.second - r.second}; }
template<class U, class V, class A, class B>
inline std::pair<U, V> operator*(const std::pair<U, V>& l, const std::pair<A, B>& r) { return {l.first * r.first, l.second * r.second}; }
template<class U, class V, class A, class B>
inline std::pair<U, V> operator/(const std::pair<U, V>& l, const std::pair<A, B>& r) { return {l.first / r.first, l.second / r.second}; }

template<class U, class V, class A, class B> inline void operator+=(std::pair<U, V>& l, const std::pair<A, B>& r) { l = l + r; }
template<class U, class V, class A, class B> inline void operator-=(std::pair<U, V>& l, const std::pair<A, B>& r) { l = l - r; }
template<class U, class V, class A, class B> inline void operator*=(std::pair<U, V>& l, const std::pair<A, B>& r) { l = l * r; }
template<class U, class V, class A, class B> inline void operator/=(std::pair<U, V>& l, const std::pair<A, B>& r) { l = l / r; }

template<class U, class V>
void print_pretty_pair(std::ostream& out, const std::pair<U, V>& p, const bool new_line = true) {
  out << '(' << p.first << ", " << p.second << ')';
  if (new_line) out << '\n';
}
