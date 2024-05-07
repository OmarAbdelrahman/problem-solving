#include <iostream>
#include <cstdint>
#include <cmath>
#include <ratio>
#include <chrono>
#include <iomanip>

inline bool is_perfect_square(int64_t x) {
  auto sr = int64_t(std::round(std::sqrt(x)));
  return (sr * sr == x);
}

void ratio_playground() {
  std::ratio<5, 3> five_thirds;
  std::cout << five_thirds.num << '/' << five_thirds.den << '\n';

  typedef std::ratio<25, 15> another_five_thirds;
  std::cout << another_five_thirds::num << '/' << another_five_thirds::den << '\n';

  std::ratio<15, 15> one;
  std::cout << one.num << '/' << one.den << '\n';

  std::ratio<0> zero;
  std::cout << zero.num << '/' << zero.den << '\n';

  typedef std::ratio<7, -3> neg;
  std::cout << neg::num << '/' << neg::den << '\n';

  using two_third = std::ratio<2, 3>;
  using one_sixth = std::ratio<1, 6>;
  using product = std::ratio_multiply<two_third, one_sixth>;

  static_assert(std::ratio_equal<product, std::ratio<13, 117>>::value);
  static_assert(std::ratio_equal_v<product, std::ratio<1, 9>>);

  std::cout << two_third::num << '/' << two_third::den << " * " << one_sixth::num << '/' << one_sixth::den << " = "
            << product::num << '/' << product::den << '\n';
}

void chrono_duration_playground() {
  // optional second template argument defines the unit type in seconds
  std::chrono::duration<int> twenty_seconds(20);
  std::chrono::seconds twenty_seconds_2(20);
  std::chrono::duration<double, std::ratio<60>> half_a_minute(0.5);
  std::chrono::hours a_day(24);
  std::chrono::duration<int64_t, std::ratio<1, 1000>> one_milli_second(1); // 1/1000 of a second
  std::chrono::milliseconds milli_second(42);

  std::chrono::duration<int, std::ratio<1, 3>> d1(1);
  std::chrono::duration<int, std::ratio<1, 5>> d2(1);

  std::cout << d1 << ' ' << d2 << ' ' << d1 + d2 << '\n'; // yields 8 ticks of (1/15) seconds
  std::cout << milli_second << '\n';

  std::chrono::milliseconds ms(0);
  std::cout << ms << '\n';
  ms += twenty_seconds_2 + a_day;
  std::cout << ms << '\n';
  --ms;
  std::cout << ms << '\n';
  ms *= 2;
  std::cout << ms << '\n';
  std::cout << std::chrono::nanoseconds(ms) << '\n';

  std::chrono::seconds fifty_five_seconds(65);
  // std::chrono::minutes m1 = fifty_five_seconds; ERROR
  std::chrono::duration<double, std::ratio<60>> from_fifty_five_seconds = std::chrono::duration_cast<std::chrono::duration<double, std::ratio<60>>>(fifty_five_seconds);
  std::cout << fifty_five_seconds << ' ' << from_fifty_five_seconds << '\n';

  // std::chrono::seconds half_a_minute_in_seconds = half_a_minute; ERROR
  std::chrono::seconds half_a_minute_in_seconds = std::chrono::duration_cast<std::chrono::seconds>(half_a_minute);
  std::cout << half_a_minute << ' ' << half_a_minute_in_seconds << '\n';

  std::cout << std::chrono::seconds::max() << ' ' << std::chrono::seconds::min() << '\n';

  std::chrono::milliseconds to_split(7255042);
  std::chrono::hours hh = std::chrono::duration_cast<std::chrono::hours>(to_split);
  std::chrono::minutes mm = std::chrono::duration_cast<std::chrono::minutes>(to_split % std::chrono::hours(1));
  std::chrono::seconds ss = std::chrono::duration_cast<std::chrono::seconds>(to_split % std::chrono::minutes(1));
  std::chrono::milliseconds msecs = std::chrono::duration_cast<std::chrono::milliseconds>(to_split % std::chrono::seconds(1));

  std::cout << to_split << '\n';
  std::cout << hh << ' ' << mm << ' ' << ss << ' ' << msecs << '\n';
  std::cout << std::setfill('0')
            << std::setw(2) << hh.count() << ':'
            << std::setw(2) << mm.count() << ':'
            << std::setw(2) << ss.count() << ':'
            << std::setw(3) << msecs.count() << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  chrono_duration_playground();
  return 0;
}