template<typename T>
inline std::istream& operator>>(std::istream& in, std::deque<T>& ts) {
  for (T& t : ts) in >> t;
  return in;
}
template<typename T>
inline std::ostream& operator<<(std::ostream& out, const std::deque<T>& ts) {
  const std::size_t n = ts.size();
  for (std::size_t i = 0; i < n; i++) {
    if (i > 0) out << ' ';
    out << ts[i];
  }
  return out;
}

template<typename T, typename U> inline void operator+=(std::deque<T>& ts, const U u) { for (T& t : ts) t += u; }
template<typename T, typename U> inline void operator-=(std::deque<T>& ts, const U u) { for (T& t : ts) t -= u; }
template<typename T, typename U> inline void operator*=(std::deque<T>& ts, const U u) { for (T& t : ts) t *= u; }
template<typename T, typename U> inline void operator/=(std::deque<T>& ts, const U u) { for (T& t : ts) t /= u; }

template<typename T, typename U>
inline std::deque<U> operator+(const std::deque<T>& ts, const U u) {
  std::deque<T> uts(ts.begin(), ts.end());
  return uts += u, uts;
}
template<typename T, typename U>
inline std::deque<U> operator-(const std::deque<T>& ts, const U u) {
  std::deque<T> uts(ts.begin(), ts.end());
  return uts -= u, uts;
}
template<typename T, typename U>
inline std::deque<U> operator*(const std::deque<T>& ts, const U u) {
  std::deque<T> uts(ts.begin(), ts.end());
  return uts *= u, uts;
}
template<typename T, typename U>
inline std::deque<U> operator/(const std::deque<T>& ts, const U u) {
  std::deque<T> uts(ts.begin(), ts.end());
  return uts /= u, uts;
}

template<typename U, typename V>
inline void operator+=(std::deque<U>& us, const std::deque<V>& vs) {
  const std::size_t n = std::min(us.size(), vs.size());
  for (std::size_t i = 0; i < n; i++) us[i] += vs[i];
}
template<typename U, typename V>
inline void operator-=(std::deque<U>& us, const std::deque<V>& vs) {
  const std::size_t n = std::min(us.size(), vs.size());
  for (std::size_t i = 0; i < n; i++) us[i] -= vs[i];
}
template<typename U, typename V>
inline void operator*=(std::deque<U>& us, const std::deque<V>& vs) {
  const std::size_t n = std::min(us.size(), vs.size());
  for (std::size_t i = 0; i < n; i++) us[i] *= vs[i];
}
template<typename U, typename V>
inline void operator/=(std::deque<U>& us, const std::deque<V>& vs) {
  const std::size_t n = std::min(us.size(), vs.size());
  for (std::size_t i = 0; i < n; i++) us[i] /= vs[i];
}

template<typename U, typename V>
inline std::deque<U> operator+(const std::deque<U>& us, const std::deque<V>& vs) {
  std::deque<U> res(us.begin(), us.end());
  return res += vs, res;
}
template<typename U, typename V>
inline std::deque<U> operator-(const std::deque<U>& us, const std::deque<V>& vs) {
  std::deque<U> res(us.begin(), us.end());
  return res -= vs, res;
}
template<typename U, typename V>
inline std::deque<U> operator*(const std::deque<U>& us, const std::deque<V>& vs) {
  std::deque<U> res(us.begin(), us.end());
  return res *= vs, res;
}
template<typename U, typename V>
inline std::deque<U> operator/(const std::deque<U>& us, const std::deque<V>& vs) {
  std::deque<U> res(us.begin(), us.end());
  return res /= vs, res;
}

template<typename T, typename F> inline void deque_for_each(std::deque<T>& ts, F&& f) { for (T& t : ts) f(t); }
template<typename T, typename F> inline void deque_for_each(const std::deque<T>& ts, F&& f) { for (T& t : ts) f(t); }
template<typename T, typename F> inline void deque_for_each_with_index(std::deque<T>& ts, F&& f) {
  for (std::size_t i = 0; i < ts.size(); i++) f(i, ts[i]);
}
template<typename T, typename F> inline void deque_for_each_with_index(const std::deque<T>& ts, F&& f) {
  for (std::size_t i = 0; i < ts.size(); i++) f(i, ts[i]);
}

template<typename T>
inline void deque_pretty_print(std::ostream& out, const std::deque<T>& ts) {
  out << '[';
  deque_for_each_with_index(ts, [&](const std::size_t at, const T& t) {
    out << t;
    if (at < ts.size() - 1) out << ", ";
  });
  out << "]\n";
}
