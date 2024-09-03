struct date_t {
  int month, day, year;

  date_t() = default;
  date_t(const int m, const int d, const int y)
          : month(m), day(d), year(y) { }

  inline bool leap() const {
    if (year % 400 == 0) return true;
    return year % 4 == 0 && year % 100 != 0;
  }

  inline int days_in_month() const {
    if (month == 4 || month == 6 || month == 9 || month == 11)
      return 30;
    if (month == 2) return 28 + leap();
    return 31;
  }

  inline bool before_leap() const {
    return month < 2 || (month == 2 && day < 29);
  }

  inline bool after_leap() const {
    return month > 2;
  }

  inline bool one_day_difference(const date_t& other) const {
    const bool only_day_difference = (year == other.year && month == other.month && day + 1 == other.day);
    const bool month_diff = (year == other.year && month + 1 == other.month && day == days_in_month() && other.day == 1);
    const bool year_diff = (year + 1 == other.year && month == 12 && day == days_in_month() && other.month == 1 && other.day == 1);
    return only_day_difference || month_diff || year_diff;
  }

  inline bool operator<(const date_t& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
  }

  inline friend std::ostream& operator<<(std::ostream& out, const date_t& date) {
    return out << date.day << ' ' << date.month << ' ' << date.year;
  }

  inline friend std::istream& operator>>(std::istream& in, date_t& date) {
    in >> date.day >> date.month >> date.year;
    return in;
  }
};
