#include <iostream>
#include <ratio>

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
