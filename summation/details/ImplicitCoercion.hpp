#pragma once

//
// ... Summation header files
//
#include <summation/details/import.hpp>

namespace Summation::Details
{
  template<typename T, typename Value>
  class ImplicitCoercion : public CRTP<T, ImplicitCoercion>
  {
  public:
    operator Value () const { return *static_cast<T const&>(*this); }
  }; // end of class ImplicitCoercion
} // end of namespace Summation::Details
