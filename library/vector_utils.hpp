#ifndef VECTOR_UTILS
#define VECTOR_UTILS

template<typename T, typename U> inline void operator+=(std::vector<T>& ts, U&& u) { for (T& t : ts) t += u; }
template<typename T, typename U> inline void operator-=(std::vector<T>& ts, U&& u) { for (T& t : ts) t -= u; }
template<typename T, typename U> inline void operator*=(std::vector<T>& ts, U&& u) { for (T& t : ts) t *= u; }
template<typename T, typename U> inline void operator/=(std::vector<T>& ts, U&& u) { for (T& t : ts) t /= u; }

template<typename T, typename U>
inline std::vector<T> operator+(const std::vector<T>& ts, U&& u) {
  std::vector<T> uts(ts);
  return uts += u, uts;
}
template<typename T, typename U>
inline std::vector<T> operator-(const std::vector<T>& ts, U&& u) {
  std::vector<T> uts(ts);
  return uts -= u, uts;
}
template<typename T, typename U>
inline std::vector<T> operator*(const std::vector<T>& ts, U&& u) {
  std::vector<T> uts(ts);
  return uts *= u, uts;
}
template<typename T, typename U>
inline std::vector<T> operator/(const std::vector<T>& ts, U&& u) {
  std::vector<T> uts(ts);
  return uts /= u, uts;
}

template<typename U, typename V>
inline void operator+=(std::vector<U>& us, const std::vector<V>& vs) {
  const std::size_t n = std::min(us.size(), vs.size());
  for (std::size_t i = 0; i < n; i++) us[i] += vs[i];
}
template<typename U, typename V>
inline void operator-=(std::vector<U>& us, const std::vector<V>& vs) {
  const std::size_t n = std::min(us.size(), vs.size());
  for (std::size_t i = 0; i < n; i++) us[i] -= vs[i];
}
template<typename U, typename V>
inline void operator*=(std::vector<U>& us, const std::vector<V>& vs) {
  const std::size_t n = std::min(us.size(), vs.size());
  for (std::size_t i = 0; i < n; i++) us[i] *= vs[i];
}
template<typename U, typename V>
inline void operator/=(std::vector<U>& us, const std::vector<V>& vs) {
  const std::size_t n = std::min(us.size(), vs.size());
  for (std::size_t i = 0; i < n; i++) us[i] /= vs[i];
}

template<typename U, typename V>
inline std::vector<U> operator+(const std::vector<U>& us, const std::vector<V>& vs) {
  std::vector<U> res(us);
  return res += vs, res;
}
template<typename U, typename V>
inline std::vector<U> operator-(const std::vector<U>& us, const std::vector<V>& vs) {
  std::vector<U> res(us);
  return res -= vs, res;
}
template<typename U, typename V>
inline std::vector<U> operator*(const std::vector<U>& us, const std::vector<V>& vs) {
  std::vector<U> res(us);
  return res *= vs, res;
}
template<typename U, typename V>
inline std::vector<U> operator/(const std::vector<U>& us, const std::vector<V>& vs) {
  std::vector<U> res(us);
  return res /= vs, res;
}

template<typename T, typename F> inline void vector_for_each(std::vector<T>& ts, F&& f) { for (T& t : ts) f(t); }
template<typename T, typename F> inline void vector_for_each(const std::vector<T>& ts, F&& f) { for (T& t : ts) f(t); }
template<typename T, typename F> inline void vector_for_each_with_index(std::vector<T>& ts, F&& f) {
  for (std::size_t i = 0; i < ts.size(); i++) f(i, ts[i]);
}
template<typename T, typename F> inline void vector_for_each_with_index(const std::vector<T>& ts, F&& f) {
  for (std::size_t i = 0; i < ts.size(); i++) f(i, ts[i]);
}

template<typename T>
inline void vector_pretty_print(std::ostream& out, const std::vector<T>& ts, const bool new_line = true) {
  out << '[';
  vector_for_each_with_index(ts, [&](const std::size_t at, const T& t) {
    out << t;
    if (at < ts.size() - 1) out << ", ";
  });
  out << ']';
  if (new_line) out << '\n';
}

#endif
