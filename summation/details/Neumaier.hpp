#pragma once

//
// ... Summation header files
//
#include <summation/details/import.hpp>

namespace Summation::Details
{

  template<typename T>
  class Neumaier
  {
    using value_type = T;

    protected:
    Neumaier(value_type x = 0) : accum{x}, comp{0} {}

    value_type
    get_value() const {return accum + comp;}

    void
    incr(value_type x){
      value_type temp = accum + x;
      if(abs(accum) > abs(x)){
        comp += (accum - temp) + x;
      } else {
        comp += (x - temp) + accum;
      }
      accum = temp;
    }

    void
    scal(value_type x){
      accum *= x;
      comp  *= x;
    }

  private:
    value_type accum;
    value_type comp;
  }; // end of class Neumaier
} // end of namespace Summation::Details
