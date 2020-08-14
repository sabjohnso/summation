#pragma once

//
// ... Standard header files
//
#include <cmath>
#include <type_traits>
#include <iterator>

//
// ... External header files
//
#include <type_utility/type_utility.hpp>
#include <function_utility/function_utility.hpp>

namespace Summation::Details
{
  using std::abs;
  using std::result_of_t;
  using std::common_type_t;

  using std::logic_error;

  using std::distance;

  using TypeUtility::CRTP;
  using TypeUtility::Type;
  using TypeUtility::type;

  using FunctionUtility::Static_callable;



} // end of namespace Summation::Details
