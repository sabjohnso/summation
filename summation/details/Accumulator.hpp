#pragma once

//
// ... Summation header files
//
#include <summation/details/import.hpp>
#include <summation/details/Neumaier.hpp>
#include <summation/details/NoEnhancement.hpp>
#include <summation/details/ExplicitCoercion.hpp>

namespace Summation::Details
{
  /**
   * @brief Configurable accumulor
   *
   * @tpar T        - Value type to be returned by the accumulator
   * @tpar Algorith - Summation algorithm
   * @tpar PrecEn   - Precision enhancement
   * @tpar Coercion - Coercing policy for coercing the accumulator to the value type
   */
  template<
    typename T,
    template<typename> class Algorithm = Neumaier,
    template<typename> class PrecEn = NoEnhancement,
    template<typename, typename> class Coercion = ExplicitCoercion
    >
  class Accumulator
    : public Algorithm<PrecEn<T>>
    , public Coercion<Accumulator<T,PrecEn,Algorithm,Coercion>, T>
  {
  public:

    using value_type = T;
    using enhanced_type = PrecEn<value_type>;
    using algorithm = Algorithm<enhanced_type>;

    Accumulator() : algorithm{} {}
    Accumulator(enhanced_type x) : algorithm{x} {}


    /**
     * @brief Return the accumulated value
     */
    value_type
    operator*() const { return algorithm::get_value(); }

    /**
     * @brief Increment the accumulated value by the input value
     */
    Accumulator&
    operator +=(enhanced_type x){
      algorithm::incr(x);
      return *this;
    }

    /**
     * @brief Decrement the accumulated value by the input value
     */
    Accumulator&
    operator -=(enhanced_type x){
      algorithm::incr(-x);
      return *this;
    }

    /**
     * @brief Scale the accumulated value
     */
    Accumulator&
    operator *=(enhanced_type x){
      algorithm::scal(x);
    }

    /**
     * @brief Reciprocal scale the accumulated value
     */
    Accumulator&
    operator /=(enhanced_type x){
      algorithm::scal(1/x);
    }

    friend Accumulator
    operator +(Accumulator x, Accumulator y){
      x += *y;
      return x;
    }

    friend Accumulator
    operator +(Accumulator x, enhanced_type y){
      x += y;
      return x;
    }

    friend Accumulator
    operator +(enhanced_type x, Accumulator y){
      y += x;
      return y;
    }

    friend Accumulator
    operator -(Accumulator x, Accumulator y){
      x -= *y;
      return x;
    }

    friend Accumulator
    operator -(Accumulator x, enhanced_type y){
      x -= y;
      return x;
    }

    friend Accumulator
    operator -(enhanced_type x, Accumulator y){
      y -= x;
      return y;
    }

    friend Accumulator
    operator *(Accumulator x, Accumulator y){
      x *= *y;
      return x;
    }

    friend Accumulator
    operator *(Accumulator x, enhanced_type y){
      x *= y;
      return x;
    }

    friend Accumulator
    operator *(enhanced_type x, Accumulator y){
      y *= x;
      return y;
    }


    friend Accumulator
    operator /(Accumulator x, Accumulator y){
      x /= *y;
      return x;
    }

    friend Accumulator
    operator /(Accumulator x, enhanced_type y){
      x /= y;
      return x;
    }

    friend Accumulator
    operator /(enhanced_type x, Accumulator y){
      y /= x;
      return y;
    }
  }; // end of class Accumulator
} // end of namespace Summation::Details
