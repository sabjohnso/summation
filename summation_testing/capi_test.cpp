//
// ... Testing header files
//
#include <gtest/gtest.h>

//
// ... Summation header files
//
#include <summation/capi.h>

namespace Summation::Testing
{
  TEST(CAPI, DoubleSumArgs1){
    ASSERT_EQ(dsum2(NAIVE, 3.0, 4.0), 7.0);
    ASSERT_EQ(dsum4(NAIVE, 1.0, 2.0, 3.0, 4.0), 10.0);
  }
} // end of namespace Summation::Testing
