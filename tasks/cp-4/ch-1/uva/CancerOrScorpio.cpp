#include <iostream>
#include <string>
#include <iomanip>

class CancerOrScorpio {
public:
  struct date_t {
    static const int JAN = 1;
    static const int FEB = 2;
    static const int MAR = 3;
    static const int APR = 4;
    static const int MAY = 5;
    static const int JUN = 6;
    static const int JUL = 7;
    static const int AUG = 8;
    static const int SEP = 9;
    static const int OCT = 10;
    static const int NOV = 11;
    static const int DEC = 12;

    int month, day, year;
 
    date_t() { }
    date_t(const int d, const int m, const int y)
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

    date_t plus_days(const int& n) {
      date_t date = *this;
      date.day += n;
      while (date.day > date.days_in_month()) {
        date.day -= date.days_in_month();
        date.month += 1;
        if (date.month > 12) {
          date.month = 1;
          date.year += 1;
        }
      }
      return std::move(date);
    }

    std::string sign() {
      if ((month == JAN && day >= 21) || (month == FEB && day <= 19))
        return "aquarius";
      if ((month == FEB && day >= 20) || (month == MAR && day <= 20))
        return "pisces";
      if ((month == MAR && day >= 21) || (month == APR && day <= 20))
        return "aries";
      if ((month == APR && day >= 21) || (month == MAY && day <= 21))
        return "taurus";
      if ((month == MAY && day >= 22) || (month == JUN && day <= 21))
        return "gemini";
      if ((month == JUN && day >= 22) || (month == JUL && day <= 22))
        return "cancer";
      if ((month == JUL && day >= 23) || (month == AUG && day <= 21))
        return "leo";
      if ((month == AUG && day >= 22) || (month == SEP && day <= 23))
        return "virgo";
      if ((month == SEP && day >= 24) || (month == OCT && day <= 23))
        return "libra";
      if ((month == OCT && day >= 24) || (month == NOV && day <= 22))
        return "scorpio";
      if ((month == NOV && day >= 23) || (month == DEC && day <= 22))
        return "sagittarius";
      return "capricorn";
    }

    friend std::istream& operator>>(std::istream& in, date_t& date) {
      in >> date.day >> date.month >> date.year;
      return in;
    }

    friend std::ostream& operator<<(std::ostream& o, const date_t& date) {
      o << std::setw(2) << std::setfill('0') << date.month << '/'
        << std::setw(2) << date.day << '/' 
        << std::setw(2) << date.year;
      return o;
    }
  };

  void solveOne(const int T, const std::string& date) {
    const int month = std::stoi(date.substr(0, 2));
    const int day = std::stoi(date.substr(2, 2));
    const int year = std::stoi(date.substr(4, 4));

    date_t date_obj(day, month, year);
    date_t birth_date = date_obj.plus_days(40 * 7);

    out << T << ' ' << birth_date << ' ' << birth_date.sign() << '\n';
  }


  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      std::string date;
      in >> date;
      solveOne(_, date);
    }
  }

  CancerOrScorpio(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};
