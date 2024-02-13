void print_yes_or_no(std::ostream& out, const bool& condition, const bool& new_line = true) {
  out << (condition ? "YES" : "NO") << (new_line ? '\n' : char());
}

std::string yes_or_no(const bool& condition) {
  return condition ? "YES" : "NO";
}

template<class T = std::string>
T value_conditional(const bool& condition, const std::array<T, 2>& options) {
  return options[condition];
}

template<class T = std::string>
void print_conditional(std::ostream& out, const bool& condition, const std::array<T, 2>& options, const bool& new_line = true) {
  out << options[condition] << (new_line ? '\n' : char());
}

template<class T>
void print_case(std::ostream& out, const int& case_i, const T& result, const bool& new_line = true) {
  out << "Case " << case_i << ": " << result << (new_line ? '\n' : char());
}
