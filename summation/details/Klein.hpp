#pragma once

//
// ... Summation header files
//
#include <summation/details/import.hpp>

namespace Summation::Details
{

  template<typename T>
  class Klein
  {
    using value_type = T;
  protected:
    Klein(value_type x = 0) : accum{x}, comp1{0}, comp2{0} {}

    value_type
    get_value() const { return accum + comp1 + comp2; }

    void
    incr(value_type x){
      value_type const temp1 = accum + x;
      value_type const c =
        abs(accum) >= abs(x)
        ? (accum - temp1) + x
        : (x - temp1) + accum;

      accum = temp1;

      value_type const temp2 = comp1 + c;
      value_type const cc =
        abs(comp1) >= abs(c)
        ? (comp1 - temp2) + c
        : (c - temp2) + comp1;

      comp1 = temp2;
      comp2 += cc;
    }

    void
    scal(value_type x){
      accum *= x;
      comp1 *= x;
      comp2 *= x;
    }
  private:
    value_type accum;
    value_type comp1;
    value_type comp2;
  };
} // end of namespace Summation::Details
