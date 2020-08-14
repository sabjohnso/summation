//
// ... Testing header files
//
#include <gtest/gtest.h>

//
// ... Summation header files
//
#include <summation/summation.hpp>

namespace Summation::Testing
{

  TEST(Sum, Naive)
  {
    static_assert(sum(naive, 1.0, 2.0, 3.0, 4.0) == 10.0);
  }

  TEST(Sum, Kahan)
  {
    static_assert(sum(kahan, 1.0, 2.0, 3.0, 4.0) == 10.0);
  }

  TEST(Sum, Neumaier)
  {
    static_assert(sum(neumaier, 1.0, 2.0, 3.0, 4.0) == 10.0);
  }



} // end of namespace Summation::Testing
