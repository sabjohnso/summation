#pragma once

//
// ... Summation header files
//
#include <summation/details/import.hpp>
#include <summation/details/Template.hpp>
#include <summation/details/Accumulator.hpp>
#include <summation/details/Naive.hpp>
#include <summation/details/Kahan.hpp>
#include <summation/details/Neumaier.hpp>
#include <summation/details/Klein.hpp>

namespace Summation::Details
{

  template<typename T>
  using NaiveAccumulator = Accumulator<T,Naive>;
  constexpr auto naive = tmplt<NaiveAccumulator>;

  template<typename T>
  using KahanAccumulator = Accumulator<T,Kahan>;
  constexpr auto kahan = tmplt<KahanAccumulator>;

  template<typename T>
  using NeumaierAccumulator = Accumulator<T,Neumaier>;
  constexpr auto neumaier = tmplt<NeumaierAccumulator>;

  template<typename T>
  using KleinAccumulator = Accumulator<T, Klein>;
  constexpr auto klein = tmplt<KleinAccumulator>;

} // end of namespace Summation::Details
