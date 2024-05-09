#include <type_traits>
#include <iostream>

void integral_const_and_bool_const()
{
  std::cout << std::boolalpha;

  using my_type = int;
  std::cout << "my_type" << '\n';
  std::cout << std::is_const<my_type>::value << '\n';
  std::cout << std::is_const_v<my_type> << '\n';
  std::cout << '\n';

  using value_type = std::is_const<my_type>::value_type;
  using T = std::is_const<my_type>::type;

  std::cout << "my_type::value_type" << '\n';
  std::cout << std::is_same<value_type, bool>::value << '\n';
  std::cout << std::is_same_v<value_type, bool> << '\n';
  std::cout << '\n';

  std::cout << "my_type::type" << '\n';
  std::cout << std::is_same<T, std::integral_constant<bool, false>>::value << '\n';
  std::cout << std::is_same_v<T, std::bool_constant<false>> << '\n';
  std::cout << std::is_same_v<T, std::false_type> << '\n';
  std::cout << '\n';

  auto instance = std::is_const<my_type>();
  std::cout << "my_type()" << '\n';
  std::cout << std::is_same_v<decltype(instance), std::is_const<int>> << '\n';
  std::cout << instance() << '\n';  // <- yield the value of the type-trait object

  static constexpr auto my_type_is_const = std::is_const<int const>{};
  if constexpr (my_type_is_const) {
    std::cout << "i'm compiled-time checked const" << '\n';
  }

  static_assert(!std::is_const<my_type>{}, "my_type should not be const");
}

void r_value_ref_decltype_check_example(std::string&& s)
{
  std::cout << "check value-reference type for std::string s" << '\n';
  std::cout << std::is_lvalue_reference_v<decltype(s)> << '\n';
  std::cout << std::is_rvalue_reference_v<decltype(s)> << '\n';
  std::cout << '\n';
  std::cout << "check value-reference for std::string s if used as an expression" << '\n';
  std::cout << std::is_lvalue_reference_v<decltype((s))> << '\n';
  std::cout << std::is_rvalue_reference_v<decltype((s))> << '\n';
}

void template_main()
{
  r_value_ref_decltype_check_example("some-string");
}
