#pragma once

//
// ... Summation header files
//
#include <summation/details/import.hpp>

namespace Summation::Details
{

  template<typename T>
  class Naive
  {
    using value_type = T;
  protected:
    Naive(value_type x = 0) : accum(x)
    {}

    value_type
    get_value() const {return accum;}

    void
    incr(value_type x){ accum += x; }

    void
    scal(value_type x){ accum *= x; }

  private:
    value_type accum;
  }; // end of class Naive
} // end of namespace Summation::Details
