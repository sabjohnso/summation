#pragma once

//
// ... Summation header files
//
#include <summation/details/import.hpp>
#include <summation/details/types.hpp>
#include <summation/details/Template.hpp>

namespace Summation::Details
{
  class SumRange
  {
  public:

    /**
     * @brief Return the sum of the values in the input range,
     * where the sum is computed using the input accumulator type.
     */
    template<template<typename> class Accum, typename Iter>
    auto
    operator ()(Template<Accum>, Iter first, Iter last) const {
      Accum<ValueType<Iter>> accum{};
      while(first != last){
        accum += *first++;
      }
      return *accum;
    }
  }; // end of class SumRange

} // end of namespace Summation::Details
