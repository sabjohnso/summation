#pragma once

//
// ... Summation header files
//
#include <summation/details/import.hpp>
#include <summation/details/Template.hpp>


namespace Summation::Details
{

  class TranSumArgs
  {
  public:
    /**
     * @brief Return the sum of the input values,  where the
     *  sum is computed using the input accumulator type.
     */
    template<template<typename> class Accum, typename F, typename T, typename ... Ts>
    auto
    operator()(Template<Accum> , F&& f, T x, Ts ... xs) const {
      Accum<result_of_t<F(common_type_t<T, Ts ...>)>> accum{};
      return aux(accum, f, x, xs ...);
    }
  private:

    template<typename Accum, typename F>
    static auto
    aux(Accum& accum, F&&){
      return *accum;
    }

    template<typename Accum, typename F, typename T, typename ... Ts>
    static auto
    aux(Accum& accum, F&& f, T x, Ts ... xs){
      accum += f(x);
      return aux(accum, f, xs ...);
    }
  }; // end of class SumArgs

  constexpr TranSumArgs transum_args{};

} // end of namespace Summation::Details
