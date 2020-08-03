#pragma once

namespace Summation::Details
{

  template<typename T>
  using IdentityType = T;

  template<typename T>
  struct ValueType_ : Type<typename T::value_type>
  {};

  template<typename T>
  struct ValueType_<T*> : Type<T>
  {};

  template<typename T>
  struct ValueType_<const T*> : Type<T>
  {};

  template<typename T>
  using ValueType = typename ValueType_<T>::type;

  template<typename ... Ts>
  struct ReturnType_;

  template<typename T>
  struct ReturnType_<T> : Type<ValueType<T>>
  {};

  template<typename F, typename T, typename ... Ts>
  struct ReturnType_<F, T, Ts ...> : Type<result_of_t<F(T, Ts ...)>>
  {};

  template< typename T, typename ... Ts>
  using ReturnType = typename ReturnType_<T, Ts ...>::type;

} // end of namespace Summation::Details
