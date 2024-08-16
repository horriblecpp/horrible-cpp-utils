#ifndef HORRIBLE_UTILS_TYPE_TRAITS_HPP_
#define HORRIBLE_UTILS_TYPE_TRAITS_HPP_

#include <iostream>


namespace horrible::utils
{

template<typename T> constexpr char const* print_expr_category {"prvalue"};
// partial class template specializations, lvalue-reference and rvalue-reference:
template<typename T> constexpr char const* print_expr_category<T&> {"lvalue"};
template<typename T> constexpr char const* print_expr_category<T&&> {"xvalue"};

// Macro isn't affected by namespaces
#define SHOW(expr) std::cout << #expr ": " << print_expr_category<decltype((expr)) << std::endl



}             // end namespace horrible::utils

#endif        // HORRIBLE_UTILS_TYPE_TRAITS_HPP_