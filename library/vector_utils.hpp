template<class T>
inline std::istream& operator>>(std::istream& in, std::vector<T>& ts) {
  for (T& t : ts) in >> t;
  return in;
}

template<class T>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T>& ts) {
  const std::size_t n = ts.size();
  for (std::size_t i = 0; i < n; i++) {
    if (i > 0) out << ' ';
    out << ts[i];
  }
  return out;
}

template<class T, class U> inline void operator+=(std::vector<T>& ts, const U u) { for (T& t : ts) t += u; }
template<class T, class U> inline void operator-=(std::vector<T>& ts, const U u) { for (T& t : ts) t -= u; }
template<class T, class U> inline void operator*=(std::vector<T>& ts, const U u) { for (T& t : ts) t *= u; }
template<class T, class U> inline void operator/=(std::vector<T>& ts, const U u) { for (T& t : ts) t /= u; }

template<class T, class U>
inline std::vector<U> operator+(const std::vector<T>& ts, const U u) {
  std::vector<T> uts(ts.begin(), ts.end());
  return uts += u, uts;
}
template<class T, class U>
inline std::vector<U> operator-(const std::vector<T>& ts, const U u) {
  std::vector<T> uts(ts.begin(), ts.end());
  return uts -= u, uts;
}
template<class T, class U>
inline std::vector<U> operator*(const std::vector<T>& ts, const U u) {
  std::vector<T> uts(ts.begin(), ts.end());
  return uts *= u, uts;
}
template<class T, class U>
inline std::vector<U> operator/(const std::vector<T>& ts, const U u) {
  std::vector<T> uts(ts.begin(), ts.end());
  return uts /= u, uts;
}

template<class U, class V>
inline void operator+=(std::vector<U>& us, const std::vector<V>& vs) {
  const std::size_t n = std::min(us.size(), vs.size());
  for (std::size_t i = 0; i < n; i++) us[i] += vs[i];
}
template<class U, class V>
inline void operator-=(std::vector<U>& us, const std::vector<V>& vs) {
  const std::size_t n = std::min(us.size(), vs.size());
  for (std::size_t i = 0; i < n; i++) us[i] -= vs[i];
}
template<class U, class V>
inline void operator*=(std::vector<U>& us, const std::vector<V>& vs) {
  const std::size_t n = std::min(us.size(), vs.size());
  for (std::size_t i = 0; i < n; i++) us[i] *= vs[i];
}
template<class U, class V>
inline void operator/=(std::vector<U>& us, const std::vector<V>& vs) {
  const std::size_t n = std::min(us.size(), vs.size());
  for (std::size_t i = 0; i < n; i++) us[i] /= vs[i];
}

template<class U, class V>
inline std::vector<U> operator+(const std::vector<U>& us, const std::vector<V>& vs) {
  std::vector<U> res(us.begin(), us.end());
  return res += vs, res;
}
template<class U, class V>
inline std::vector<U> operator-(const std::vector<U>& us, const std::vector<V>& vs) {
  std::vector<U> res(us.begin(), us.end());
  return res -= vs, res;
}
template<class U, class V>
inline std::vector<U> operator*(const std::vector<U>& us, const std::vector<V>& vs) {
  std::vector<U> res(us.begin(), us.end());
  return res *= vs, res;
}
template<class U, class V>
inline std::vector<U> operator/(const std::vector<U>& us, const std::vector<V>& vs) {
  std::vector<U> res(us.begin(), us.end());
  return res /= vs, res;
}

template<class T, class F> inline void vector_for_each(std::vector<T>& ts, F&& f) { for (T& t : ts) f(t); }
template<class T, class F> inline void vector_for_each(const std::vector<T>& ts, F&& f) { for (T& t : ts) f(t); }
template<class T, class F> inline void vector_for_each_with_index(std::vector<T>& ts, F&& f) {
  for (std::size_t i = 0; i < ts.size(); i++) f(i, ts[i]);
}
template<class T, class F> inline void vector_for_each_with_index(const std::vector<T>& ts, F&& f) {
  for (std::size_t i = 0; i < ts.size(); i++) f(i, ts[i]);
}

template<class T>
inline void pretty_print_vector(std::ostream& out, const std::vector<T>& ts) {
  out << '[';
  vector_for_each_with_index(ts, [&](const std::size_t at, const T &t) {
    out << t;
    if (at < ts.size() - 1) out << ", ";
  });
  out << "]\n";
}
