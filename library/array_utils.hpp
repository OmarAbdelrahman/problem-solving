template<typename T, std::size_t _t_size>
inline std::istream& operator>>(std::istream& in, std::array<T, _t_size>& ts) {
  for (T& t : ts) in >> t;
  return in;
}
template<typename T, std::size_t _t_size>
inline std::ostream& operator<<(std::ostream& out, const std::array<T, _t_size>& ts) {
  for (std::size_t i = 0; i < _t_size; i++) {
    if (i > 0) out << ' ';
    out << ts[i];
  }
  return out;
}

template<class T, std::size_t _t_size, class U>
inline void operator+=(std::array<T, _t_size>& ts, const U u) { for (T& t : ts) t += u; }
template<class T, std::size_t _t_size, class U>
inline void operator-=(std::array<T, _t_size>& ts, const U u) { for (T& t : ts) t -= u; }
template<class T, std::size_t _t_size, class U>
inline void operator*=(std::array<T, _t_size>& ts, const U u) { for (T& t : ts) t *= u; }
template<class T, std::size_t _t_size, class U>
inline void operator/=(std::array<T, _t_size>& ts, const U u) { for (T& t : ts) t /= u; }

template<class T, std::size_t _t_size, class U>
inline std::array<T, _t_size> operator+(const std::array<T, _t_size>& ts, const U u) {
  std::array<T, _t_size> us(ts);
  return us += u, us;
}
template<class T, std::size_t _t_size, class U>
inline std::array<T, _t_size> operator-(const std::array<T, _t_size>& ts, const U u) {
  std::array<T, _t_size> us(ts);
  return us -= u, us;
}
template<class T, std::size_t _t_size, class U>
inline std::array<T, _t_size> operator*(const std::array<T, _t_size>& ts, const U u) {
  std::array<T, _t_size> us(ts);
  return us *= u, us;
}
template<class T, std::size_t _t_size, class U>
inline std::array<T, _t_size> operator/(const std::array<T, _t_size>& ts, const U u) {
  std::array<T, _t_size> us(ts);
  return us /= u, us;
}

template<class U, std::size_t _u_size, class V, std::size_t _v_size>
inline void operator+=(std::array<U, _u_size>& us, const std::array<V, _v_size>& vs) {
  const std::size_t n = std::min(_u_size, _v_size);
  for (std::size_t i = 0; i < n; i++) us[i] += vs[i];
}
template<class U, std::size_t _u_size, class V, std::size_t _v_size>
inline void operator-=(std::array<U, _u_size>& us, const std::array<V, _v_size>& vs) {
  const std::size_t n = std::min(_u_size, _v_size);
  for (std::size_t i = 0; i < n; i++) us[i] -= vs[i];
}
template<class U, std::size_t _u_size, class V, std::size_t _v_size>
inline void operator*=(std::array<U, _u_size>& us, const std::array<V, _v_size>& vs) {
  const std::size_t n = std::min(_u_size, _v_size);
  for (std::size_t i = 0; i < n; i++) us[i] *= vs[i];
}
template<class U, std::size_t _u_size, class V, std::size_t _v_size>
inline void operator/=(std::array<U, _u_size>& us, const std::array<V, _v_size>& vs) {
  const std::size_t n = std::min(_u_size, _v_size);
  for (std::size_t i = 0; i < n; i++) us[i] /= vs[i];
}

template<class U, std::size_t _u_size, class V, std::size_t _v_size>
inline std::array<U, _u_size> operator+(const std::array<U, _u_size>& us, const std::array<V, _v_size>& vs) {
  std::array<U, _u_size> res(us);
  return res += vs, res;
}
template<class U, std::size_t _u_size, class V, std::size_t _v_size>
inline std::array<U, _u_size> operator-(const std::array<U, _u_size>& us, const std::array<V, _v_size>& vs) {
  std::array<U, _u_size> res(us);
  return res -= vs, res;
}
template<class U, std::size_t _u_size, class V, std::size_t _v_size>
inline std::array<U, _u_size> operator*(const std::array<U, _u_size>& us, const std::array<V, _v_size>& vs) {
  std::array<U, _u_size> res(us);
  return res *= vs, res;
}
template<class U, std::size_t _u_size, class V, std::size_t _v_size>
inline std::array<U, _u_size> operator/(const std::array<U, _u_size>& us, const std::array<V, _v_size>& vs) {
  std::array<U, _u_size> res(us);
  return res /= vs, res;
}

template<class T, std::size_t _t_size, class F>
inline void array_for_each(std::array<T, _t_size>& ts, F&& f) { for (T& t : ts) f(t); }
template<class T, std::size_t _t_size, class F>
inline void array_for_each(const std::array<T, _t_size>& ts, F&& f) { for (T& t : ts) f(t); }
template<class T, std::size_t _t_size, class F>
inline void array_for_each_with_index(std::array<T, _t_size>& ts, F&& f) {
  for (std::size_t i = 0; i < ts.size(); i++) f(i, ts[i]);
}
template<class T, std::size_t _t_size, class F>
inline void array_for_each_with_index(const std::array<T, _t_size>& ts, F&& f) {
  for (std::size_t i = 0; i < ts.size(); i++) f(i, ts[i]);
}

template<class T, std::size_t _t_size>
inline void array_pretty_print(std::ostream& out, const std::array<T, _t_size>& ts) {
  out << '[';
  array_for_each_with_index(ts, [&out](const std::size_t at, const T& t) {
    out << t;
    if (at < _t_size - 1) out << ", ";
  });
  out << "]\n";
}
