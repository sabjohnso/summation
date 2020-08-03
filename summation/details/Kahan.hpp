#pragma once

//
// ... Summation header files header files
//
#include <summation/details/import.hpp>

namespace Summation::Details
{
  template<typename T>
  class Kahan
  {
    using value_type = T;
  protected:

    Kahan(value_type x = 0) : accum{x}, comp{0} {}

    value_type
    get_value() const { return accum; }

    void
    incr(value_type x){
      value_type y = x - comp;
      value_type temp = accum + y;
      comp = (temp - accum) - y;
      accum = temp;
    }

    void
    scal(value_type x){
      accum *= x;
      comp *= x;
    }

  private:
    value_type accum;
    value_type comp;
  }; // end of class Kahan
} // end of namespace Summation::Details
