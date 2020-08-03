#pragma once

//
// ... Summation header files
//
#include <summation/details/import.hpp>
#include <summation/details/types.hpp>
#include <summation/details/Template.hpp>

namespace Summation::Details
{

  class Tran2SumRange
  {
  public:
    /**
     * @brief Return the sum of the values in the two input ranges
     * transformed by the input function, where the sum is computed
     * using the input accumulator.
     */
    template<template<typename >class Accum, typename F, typename Iter1, typename Iter2>
    auto
    operator()(Template<Accum>, F&& f, Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2) const {
      Accum<result_of_t<F(ValueType<Iter1>, ValueType<Iter2>)>> accum{};
      if(distance(first1, last1) == distance(first2, last2)){
        while(first1 != last1){
          accum += f(*first1++, *first2++);
        }
        return *accum;
      } else {
        throw logic_error("Trans2SumRange requires input ranges with equal lengths");
      }
    }
  }; // end of class Tran2SumRange
} // end of namespace Summation::Details
