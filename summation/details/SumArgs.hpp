#pragma once

//
// ... Summation header files
//
#include <summation/details/Template.hpp>

namespace Summation::Details
{

  class SumArgs
  {
  public:
    /**
     * @brief Return the sum of the input values,  where the
     *  sum is computed using the input accumulator type.
     */
    template<template<typename> class Accum, typename T, typename ... Ts>
    auto
    operator()(Template<Accum> , T x, Ts ... xs) const {
      Accum<common_type_t<T, Ts ...>> accum{};
      return aux(accum, x, xs ...);
    }
  private:

    template<typename Accum>
    static auto
    aux(Accum& accum){
      return *accum;
    }

    template<typename Accum, typename T, typename ... Ts>
    static auto
    aux(Accum& accum, T x, Ts ... xs){
      accum += x;
      return aux(accum, xs ...);
    }
  }; // end of class SumArgs

  constexpr SumArgs sum_args{};

} // end of namespace Summation::Details
