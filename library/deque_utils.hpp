template<class T>
inline std::istream& operator>>(std::istream& in, std::deque<T>& ts) {
  for (T& t : ts) in >> t;
  return in;
}

template<class T>
inline std::ostream& operator<<(std::ostream& out, const std::deque<T>& ts) {
  const std::size_t n = ts.size();
  for (std::size_t i = 0; i < n; i++) {
    if (i > 0) out << ' ';
    out << ts[i];
  }
  return out;
}

template<class T, class U> inline void operator+=(std::deque<T>& ts, const U u) { for (T& t : ts) t += u; }
template<class T, class U> inline void operator-=(std::deque<T>& ts, const U u) { for (T& t : ts) t -= u; }
template<class T, class U> inline void operator*=(std::deque<T>& ts, const U u) { for (T& t : ts) t *= u; }
template<class T, class U> inline void operator/=(std::deque<T>& ts, const U u) { for (T& t : ts) t /= u; }

template<class T, class U>
inline std::deque<U> operator+(const std::deque<T>& ts, const U u) {
  std::deque<T> uts(ts.begin(), ts.end());
  return uts += u, uts;
}
template<class T, class U>
inline std::deque<U> operator-(const std::deque<T>& ts, const U u) {
  std::deque<T> uts(ts.begin(), ts.end());
  return uts -= u, uts;
}
template<class T, class U>
inline std::deque<U> operator*(const std::deque<T>& ts, const U u) {
  std::deque<T> uts(ts.begin(), ts.end());
  return uts *= u, uts;
}
template<class T, class U>
inline std::deque<U> operator/(const std::deque<T>& ts, const U u) {
  std::deque<T> uts(ts.begin(), ts.end());
  return uts /= u, uts;
}

template<class U, class V>
inline void operator+=(std::deque<U>& us, const std::deque<V>& vs) {
  const std::size_t n = std::min(us.size(), vs.size());
  for (std::size_t i = 0; i < n; i++) us[i] += vs[i];
}
template<class U, class V>
inline void operator-=(std::deque<U>& us, const std::deque<V>& vs) {
  const std::size_t n = std::min(us.size(), vs.size());
  for (std::size_t i = 0; i < n; i++) us[i] -= vs[i];
}
template<class U, class V>
inline void operator*=(std::deque<U>& us, const std::deque<V>& vs) {
  const std::size_t n = std::min(us.size(), vs.size());
  for (std::size_t i = 0; i < n; i++) us[i] *= vs[i];
}
template<class U, class V>
inline void operator/=(std::deque<U>& us, const std::deque<V>& vs) {
  const std::size_t n = std::min(us.size(), vs.size());
  for (std::size_t i = 0; i < n; i++) us[i] /= vs[i];
}

template<class U, class V>
inline std::deque<U> operator+(const std::deque<U>& us, const std::deque<V>& vs) {
  std::deque<U> res(us.begin(), us.end());
  return res += vs, res;
}
template<class U, class V>
inline std::deque<U> operator-(const std::deque<U>& us, const std::deque<V>& vs) {
  std::deque<U> res(us.begin(), us.end());
  return res -= vs, res;
}
template<class U, class V>
inline std::deque<U> operator*(const std::deque<U>& us, const std::deque<V>& vs) {
  std::deque<U> res(us.begin(), us.end());
  return res *= vs, res;
}
template<class U, class V>
inline std::deque<U> operator/(const std::deque<U>& us, const std::deque<V>& vs) {
  std::deque<U> res(us.begin(), us.end());
  return res /= vs, res;
}

template<class T, class F> inline void deque_for_each(std::deque<T>& ts, F&& f) { for (T& t : ts) f(t); }
template<class T, class F> inline void deque_for_each(const std::deque<T>& ts, F&& f) { for (T& t : ts) f(t); }
template<class T, class F> inline void deque_for_each_with_index(std::deque<T>& ts, F&& f) {
  for (std::size_t i = 0; i < ts.size(); i++) f(i, ts[i]);
}
template<class T, class F> inline void deque_for_each_with_index(const std::deque<T>& ts, F&& f) {
  for (std::size_t i = 0; i < ts.size(); i++) f(i, ts[i]);
}

template<class T>
inline void pretty_print_deque(std::ostream& out, const std::deque<T>& ts) {
  out << '[';
  deque_for_each_with_index(ts, [&](const std::size_t at, const T &t) {
    out << t;
    if (at < ts.size() - 1) out << ", ";
  });
  out << "]\n";
}
