#pragma once

//
// ... Summation header files
//
#include <summation/details/import.hpp>

namespace Summation::Details
{
  template<typename T, typename Value>
  class ExplicitCoercion : public CRTP<ExplicitCoercion, T>
  {
  public:
    explicit
    operator Value () const { return *static_cast<T const&>(*this); }
  }; // end of class ExplicitCoercion
} // end of namespace Summation::Details
