#include <cstdint>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <set>
#include <vector>

class CanOfBeans {
public:
  struct date_t {
    int64_t year, month, day;
 
    date_t() { }
    date_t(const int64_t m, const int64_t d, const int64_t y)
      : month(m), day(d), year(y) { }
 
    bool leap() const {
      if (year % INT64_C(400) == 0) return true;
      return year % INT64_C(4) == 0 && year % INT64_C(100) != 0;
    }
 
    int64_t days_in_month() const {
      if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
      if (month == 2) return 28 + (leap() ? 1L : 0L);
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

    bool valid_month() const {
      return month >= 1 && month <= 12;
    }

    bool valid_day() const {
      return day >= 1 && day <= days_in_month();
    }

    bool valid() const {
      return valid_month() && valid_day();
    }

    bool operator <(const date_t& other) const {
      if (year != other.year) return year < other.year;
      if (month != other.month) return month < other.month;
      return day < other.day;
    }

    friend std::istream& operator>>(std::istream& i, date_t& date) {
      i >> date.day >> date.month >> date.year;
      return i;
    }

    friend std::ostream& operator<<(std::ostream& o, const date_t& date) {
      o << std::setw(2) << std::setfill('0') << date.year % 100 << ' ' 
        << std::setw(2) << date.month << ' ' 
        << std::setw(2) << date.day;
      return o;
    }
  };

  void solveOne(int64_t c, int64_t x, int64_t y, int64_t z) {
    std::vector<int64_t> a = {x, y, z};
    std::sort(a.begin(), a.end());
    std::set<date_t> q;

    do {
      date_t date(a[0], a[1], c * 100 + a[2]);
      if (date.valid()) {
        q.emplace(date);
      }
    } while (std::next_permutation(a.begin(), a.end()));

    if (q.empty()) {
      out << -1 << '\n';
    } else {
      out << *q.begin() << '\n';
    }
  }

  void solve() {
    int nt;
    in >> nt;
    while (nt--) {
      int64_t c, x, y, z;
      in >> c >> x >> y >> z;
      solveOne(c, x, y, z);
    }
  }

  CanOfBeans(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};
