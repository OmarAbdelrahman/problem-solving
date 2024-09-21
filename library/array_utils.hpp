#ifndef ARRAY_UTILS
#define ARRAY_UTILS

template<typename T, std::size_t _t_size, typename U>
inline void operator+=(std::array<T, _t_size>& ts, U&& u) { for (T& t : ts) t += u; }
template<typename T, std::size_t _t_size, typename U>
inline void operator-=(std::array<T, _t_size>& ts, U&& u) { for (T& t : ts) t -= u; }
template<typename T, std::size_t _t_size, typename U>
inline void operator*=(std::array<T, _t_size>& ts, U&& u) { for (T& t : ts) t *= u; }
template<typename T, std::size_t _t_size, typename U>
inline void operator/=(std::array<T, _t_size>& ts, U&& u) { for (T& t : ts) t /= u; }

template<typename T, std::size_t _t_size, typename U>
inline std::array<T, _t_size> operator+(const std::array<T, _t_size>& ts, U&& u) {
  std::array<T, _t_size> us(ts);
  return us += u, us;
}
template<typename T, std::size_t _t_size, typename U>
inline std::array<T, _t_size> operator-(const std::array<T, _t_size>& ts, U&& u) {
  std::array<T, _t_size> us(ts);
  return us -= u, us;
}
template<typename T, std::size_t _t_size, typename U>
inline std::array<T, _t_size> operator*(const std::array<T, _t_size>& ts, U&& u) {
  std::array<T, _t_size> us(ts);
  return us *= u, us;
}
template<typename T, std::size_t _t_size, typename U>
inline std::array<T, _t_size> operator/(const std::array<T, _t_size>& ts, U&& u) {
  std::array<T, _t_size> us(ts);
  return us /= u, us;
}

template<typename U, std::size_t _u_size, typename V, std::size_t _v_size>
inline void operator+=(std::array<U, _u_size>& us, const std::array<V, _v_size>& vs) {
  const std::size_t n = std::min(_u_size, _v_size);
  for (std::size_t i = 0; i < n; i++) us[i] += vs[i];
}
template<typename U, std::size_t _u_size, typename V, std::size_t _v_size>
inline void operator-=(std::array<U, _u_size>& us, const std::array<V, _v_size>& vs) {
  const std::size_t n = std::min(_u_size, _v_size);
  for (std::size_t i = 0; i < n; i++) us[i] -= vs[i];
}
template<typename U, std::size_t _u_size, typename V, std::size_t _v_size>
inline void operator*=(std::array<U, _u_size>& us, const std::array<V, _v_size>& vs) {
  const std::size_t n = std::min(_u_size, _v_size);
  for (std::size_t i = 0; i < n; i++) us[i] *= vs[i];
}
template<typename U, std::size_t _u_size, typename V, std::size_t _v_size>
inline void operator/=(std::array<U, _u_size>& us, const std::array<V, _v_size>& vs) {
  const std::size_t n = std::min(_u_size, _v_size);
  for (std::size_t i = 0; i < n; i++) us[i] /= vs[i];
}

template<typename U, std::size_t _u_size, typename V, std::size_t _v_size>
inline std::array<U, _u_size> operator+(const std::array<U, _u_size>& us, const std::array<V, _v_size>& vs) {
  std::array<U, _u_size> res(us);
  return res += vs, res;
}
template<typename U, std::size_t _u_size, typename V, std::size_t _v_size>
inline std::array<U, _u_size> operator-(const std::array<U, _u_size>& us, const std::array<V, _v_size>& vs) {
  std::array<U, _u_size> res(us);
  return res -= vs, res;
}
template<typename U, std::size_t _u_size, typename V, std::size_t _v_size>
inline std::array<U, _u_size> operator*(const std::array<U, _u_size>& us, const std::array<V, _v_size>& vs) {
  std::array<U, _u_size> res(us);
  return res *= vs, res;
}
template<typename U, std::size_t _u_size, typename V, std::size_t _v_size>
inline std::array<U, _u_size> operator/(const std::array<U, _u_size>& us, const std::array<V, _v_size>& vs) {
  std::array<U, _u_size> res(us);
  return res /= vs, res;
}

template<typename T, std::size_t _t_size, typename F>
inline void array_for_each(std::array<T, _t_size>& ts, F&& f) { for (T& t : ts) f(t); }
template<typename T, std::size_t _t_size, typename F>
inline void array_for_each(const std::array<T, _t_size>& ts, F&& f) { for (T& t : ts) f(t); }
template<typename T, std::size_t _t_size, typename F>
inline void array_for_each_with_index(std::array<T, _t_size>& ts, F&& f) {
  for (std::size_t i = 0; i < ts.size(); i++) f(i, ts[i]);
}
template<typename T, std::size_t _t_size, typename F>
inline void array_for_each_with_index(const std::array<T, _t_size>& ts, F&& f) {
  for (std::size_t i = 0; i < ts.size(); i++) f(i, ts[i]);
}

template<typename T, std::size_t _t_size>
inline void array_pretty_print(std::ostream& out, const std::array<T, _t_size>& ts) {
  out << '[';
  array_for_each_with_index(ts, [&out](const std::size_t at, const T& t) {
    out << t;
    if (at < _t_size - 1) out << ", ";
  });
  out << "]\n";
}

#endif
