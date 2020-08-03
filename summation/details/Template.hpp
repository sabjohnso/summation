#pragma once

//
// ... Summation header files
//
#include <summation/details/Template.hpp>

namespace Summation::Details
{
  template<template<typename > class K>
  struct Template
  {
    template<typename T>
    constexpr auto
    operator ()(Type<T>) const {
      return type<K<T>>;
    }
  };

  template<template<typename> class K>
  constexpr Template<K> tmplt{};
} // end of namespace Summation::Details
