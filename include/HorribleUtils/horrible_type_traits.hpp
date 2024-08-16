#ifndef HORRIBLE_UTILS_TYPE_TRAITS_HPP_
#define HORRIBLE_UTILS_TYPE_TRAITS_HPP_

#include <iostream>
#include <type_traits>      // std::is_same<>, std::is_same_v<>

namespace horrible::utils
{

template<typename T> constexpr char const* print_expr_category {"prvalue"};
// partial class template specializations, lvalue-reference and rvalue-reference:
template<typename T> constexpr char const* print_expr_category<T&> {"lvalue"};
template<typename T> constexpr char const* print_expr_category<T&&> {"xvalue"};

// Macro isn't affected by namespaces
#define SHOW(expr) std::cout << #expr ": " << print_expr_category<decltype((expr)) << std::endl





template<typename T>
class IsCallableT {
public:
  static constexpr bool value = std::is_same_v<char, decltype(test<T>(nullptr))>;
private:
  template<typename U, typename = decltype(std::declval<U>()())> static char test(char const *);
  template<typename> static long test(...);
};

// V = ::value, nothing = ::type, T = type trait.
template<typename T>
constexpr bool IsCallableV = IsCallableT<T>::value;



}             // end namespace horrible::utils

#endif        // HORRIBLE_UTILS_TYPE_TRAITS_HPP_