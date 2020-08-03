#pragma once

//
// ... Summation header files
//
#include <summation/details/accumulators.hpp>
#include <summation/details/SumRange.hpp>
#include <summation/details/TranSumRange.hpp>
#include <summation/details/Tran2SumRange.hpp>
#include <summation/details/SumArgs.hpp>
#include <summation/details/TranSumArgs.hpp>

namespace Summation
{
  using ::Summation::Details::naive;
  using ::Summation::Details::kahan;
  using ::Summation::Details::neumaier;
  using ::Summation::Details::klein;

  using ::Summation::Details::sum_range;
  using ::Summation::Details::transum_range;
  using ::Summation::Details::tran2sum_range;
  using ::Summation::Details::sum_args;
  using ::Summation::Details::transum_args;

} // end of namespace Summation
