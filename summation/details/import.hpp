#pragma once

//
// ... Standard header files
//
#include <cmath>
#include <type_traits>

//
// ... External header files
//
#include <type_utility/type_utility.hpp>

namespace Summation::Details
{
  using std::abs;
  using std::result_of_t;
  using std::common_type_t;

  using std::logic_error;

  using TypeUtility::CRTP;
  using TypeUtility::Type;
  using TypeUtility::type;





} // end of namespace Summation::Details
