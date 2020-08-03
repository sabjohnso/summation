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

  constexpr ::Summation::Details::SumRange sum_range{};
  constexpr ::Summation::Details::TranSumRange transum_range{};
  constexpr ::Summation::Details::Tran2SumRange tran2sum_range{};
  constexpr ::Summation::Details::SumArgs sum_args{};
  constexpr ::Summation::Details::TranSumArgs transum_args{};


} // end of namespace Summation
