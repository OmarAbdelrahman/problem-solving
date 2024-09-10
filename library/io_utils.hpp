void print_yes_or_no(std::ostream& out, const bool& condition, const bool new_line = true) {
  out << (condition ? "YES" : "NO") << (new_line ? '\n' : char());
}
