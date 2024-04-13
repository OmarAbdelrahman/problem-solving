#include <iostream>
#include <vector>
#include <tuple>

class Electricity {
public:
  struct date_t {
    int month, day, year;
 
    date_t() { }
    date_t(const int m, const int d, const int y)
      : month(m), day(d), year(y) { }
 
    bool leap() const {
      if (year % 400 == 0) return true;
      return year % 4 == 0 && year % 100 != 0;
    }
 
    int days_in_month() const {
      if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
      if (month == 2) return 28 + leap();
      return 31;
    }
 
    bool before_leap() const {
      return month < 2 || (month == 2 && day < 29);
    }
 
    bool after_leap() const {
      return month > 2;
    }

    bool one_day_difference(const date_t& other) const {
      const bool only_day_difference = (year == other.year && month == other.month && day + 1 == other.day);
      const bool month_diff = (year == other.year && month + 1 == other.month && day == days_in_month() && other.day == 1);
      const bool year_diff = (year + 1 == other.year && month == 12 && day == days_in_month() && other.month == 1 && other.day == 1);
      return only_day_difference || month_diff || year_diff;
    }

    friend std::istream& operator>>(std::istream& in, date_t& date) {
      in >> date.day >> date.month >> date.year;
      return in;
    }
  };

  void solveOne(const int& n) {
    std::vector<std::tuple<date_t, int>> dates(n);
    for (int i = 0; i < n; ++i) {
      in >> std::get<0>(dates[i]) >> std::get<1>(dates[i]);
    }
    int result = 0, splits = 0;
    for (int i = 1; i < n; i++) {
      while (i < n && std::get<0>(dates[i - 1]).one_day_difference(std::get<0>(dates[i]))) {
        splits += 1;
        result += std::get<1>(dates[i]) - std::get<1>(dates[i - 1]);
        i += 1;
      }
    }
    out << splits << ' ' << result << '\n';
  }

  void solve() {
    for (int n; in >> n && n != 0; ) {
      solveOne(n);
    }
  }

  Electricity(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};
