//
// ... Standard header files
//
#include <type_traits>
#include <vector>

//
// ... Testing header files
//
#include <gtest/gtest.h>

//
// ... External header files
//
#include <type_utility/type_utility.hpp>

//
// ... Summation header files
//
#include <summation/summation.hpp>

namespace Summation::Testing
{
  namespace // anonymous
  {
    using std::is_same_v;
    using std::vector;

    using ::TypeUtility::type;
    using ::Summation::klein;

    constexpr auto twc = [](auto x){ return x+x; };
    constexpr auto mul = [](auto x, auto y){ return x*y; };

  } // end of anonymous namespace

  TEST(Naive, DefaultConstruction){
    auto accum = naive(type<double>)();
    static_assert(is_same_v<decltype(*accum),double>);
    ASSERT_EQ(*accum, 0.0);
  }

  TEST(Naive, InitConstruction){
    auto accum = naive(type<double>)(3.0);
    static_assert(is_same_v<decltype(*accum),double>);
    ASSERT_EQ(*accum, 3.0);
  }

  TEST(Naive, MoveConstruction){
    auto accum1 = naive(type<double>)(3.0);
    auto accum2 = accum1;
    ASSERT_EQ(*accum2, 3.0);
  }

  TEST(Naive, SimpleSum){
    auto accum = naive(type<double>)();
    accum += 1.0;
    accum += 2.0;
    accum += 3.0;
    accum += 4.0;
    ASSERT_EQ(*accum, 10.0);
  }

  TEST(Naive, SimpleSumRange){
    vector<double> xs = {1.0, 2.0, 3.0, 4.0};
    ASSERT_EQ(sum_range(naive, begin(xs), end(xs)), 10.0);
  }

  TEST(Naive, SimpleTranSumRange){
    vector<double> xs = {1.0, 2.0, 3.0, 4.0};
    ASSERT_EQ(transum_range(naive, twc, begin(xs), end(xs)), 20.0);
  }

  TEST(Naive, SimpleTran2SumRange){
    vector<double> xs = {1.0, 2.0, 3.0, 4.0};
    vector<double> ys = {5.0, 6.0, 7.0, 8.0};
    ASSERT_EQ(tran2sum_range(naive, mul, begin(xs), end(xs), begin(ys), end(ys)), 70.0);
  }

  TEST(Naive, SimpleSumArgs){
    ASSERT_EQ(sum_args(naive, 1.0, 2.0, 3.0, 4.0), 10.0);
  }

  TEST(Naive, SimpleTranSumArgs){
    ASSERT_EQ(transum_args(naive, twc, 1.0, 2.0, 3.0, 4.0), 20.0);
  }

} // end of namespace Summation::Testing
