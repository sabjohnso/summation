#pragma once

//
// ... Summation header files
//
#include <summation/details/import.hpp>
#include <summation/details/types.hpp>
#include <summation/details/Template.hpp>

namespace Summation::Details
{
  class TranSumRange
  {
  public:
    /**
     * @brief Return the sum of the values in the input range
     * transformed by the input function, where the sum is computed
     * using the input accumulator.
     */
    template<template<typename>class Accum, typename F, typename Iter>
    auto
    operator()(Template<Accum>, F&& f, Iter first, Iter last) const {
      Accum<result_of_t<F(ValueType<Iter>)>> accum{};
      while(first != last){
        accum += f(*first++);
      }
      return *accum;
    }
  }; // end of class TranSumRange

  constexpr TranSumRange transum_range{};

} // end of namespace Summation::Details
