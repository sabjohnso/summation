#pragma once

//
// ... Summation header files
//
#include <summation/details/import.hpp>
#include <summation/details/Template.hpp>

namespace Summation::Details
{
  template<typename Alg>
  class Sum;

  template<>
  class Sum<Template<NaiveAccumulator>> : public Static_callable<Sum<Template<NaiveAccumulator>>>
  {
  public:
    template<typename ... Ts>
    static constexpr auto
    call(Ts ... xs){
      return (xs + ... + 0);
    }
  }; // end of classs Sum


  template<>
  class Sum<Template<KahanAccumulator>> : public Static_callable<Sum<Template<Kahan>>>
  {
  public:
    template<typename T, typename ... Ts>
    static constexpr auto
    call(T x, Ts ... xs){
      using U = common_type_t<T, Ts...>;
      return accumulate(U(0), U(0), x, xs ...);
    }
  private:

    template<typename A, typename C>
    static constexpr auto
    accumulate(A accum, C){ return accum; }

    template<typename A, typename C, typename T, typename ... Ts>
    static constexpr auto
    accumulate(A accum, C comp, T x, Ts ... xs){
      return compensate1(accum, x - comp, xs ...);
    }

    template<typename A, typename U, typename ... Ts>
    static constexpr auto
    compensate1(A accum, U y, Ts ... xs){
      return compensate2(accum, y, accum+y, xs ...);
    }
    template<typename A, typename U, typename V, typename ... Ts>
    static constexpr auto
    compensate2(A accum, U y, V temp,  Ts ... xs){
      return accumulate(temp, (temp - accum) - y, xs ...);
    }
  }; // end of Sum

  template<>
  class Sum<Template<NeumaierAccumulator>> : public Static_callable<Sum<Template<Neumaier>>>
  {
  public:
    template<typename T, typename ... Ts>
    static constexpr auto
    call(T x, Ts ... xs){
      using U = common_type_t<T, Ts...>;
      return accumulate(U(0), U(0), x, xs ...);
    }
  private:

    template<typename A, typename C>
    static constexpr auto
    accumulate(A accum, C comp){ return accum + comp; }

    template<typename A, typename C, typename T, typename ... Ts>
    static constexpr auto
    accumulate(A accum, C comp, T x, Ts ... xs){
      return compensate(accum, comp, accum + x, x, xs ...);
    }

    template<typename A, typename C, typename U, typename T, typename ... Ts>
    static constexpr auto
    compensate(A accum, C, U temp, T x, Ts ... xs){
      return abs(accum) > abs(x)
        ? accumulate(temp, (accum - temp) + x, xs ...)
        : accumulate(temp, (x - temp) + accum, xs ...);
    }
  }; // end of Sum


  template<template<typename> class Alg, typename T, typename ... Ts>
  constexpr auto
  sum(Template<Alg>, T x, Ts ... xs){
    return Sum<Template<Alg>>::call(x, xs ...);
  }

} // end of namespace Summation::Details
