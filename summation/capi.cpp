#include <summation/capi.h>

//
// ... Standard header files
//
#include <string>
#include <stdexcept>

//
// ... Summation header files
//
#include <summation/summation.hpp>

using std::to_string;
using std::logic_error;
using namespace Summation;

extern "C" {

  double
  dsum2(Algorithm alg, double x1, double x2){
    double result;
    switch(alg){
    case NAIVE:
      result = sum_args(naive, x1, x2); break;
    case KAHAN:
      result = sum_args(kahan, x1, x2); break;
    case NEUMAIER:
      result = sum_args(neumaier, x1, x2); break;
    case KLEIN:
      result = sum_args(klein, x1, x2); break;
    default:
      throw logic_error("invalid algorithm flag passed to dsum2: " + to_string(alg));
    }
    return result;
  }

  double
  dsum3(Algorithm alg, double x1, double x2, double x3){
    double result;
    switch(alg){
    case NAIVE:
      result = sum_args(naive, x1, x2, x3); break;
    case KAHAN:
      result = sum_args(kahan, x1, x2, x3); break;
    case NEUMAIER:
      result = sum_args(neumaier, x1, x2, x3); break;
    case KLEIN:
      result = sum_args(klein, x1, x2, x3); break;
    default:
      throw logic_error("invalid algorithm flag passed to dsum2: " + to_string(alg));
    }
    return result;
  }

  double
  dsum4(Algorithm alg, double x1, double x2, double x3, double x4){
    double result;
    switch(alg){
    case NAIVE:
      result = sum_args(naive, x1, x2, x3, x4); break;
    case KAHAN:
      result = sum_args(kahan, x1, x2, x3, x4); break;
    case NEUMAIER:
      result = sum_args(neumaier, x1, x2, x3, x4); break;
    case KLEIN:
      result = sum_args(klein, x1, x2, x3, x4); break;
    default:
      throw logic_error("invalid algorithm flag passed to dsum2: " + to_string(alg));
    }
    return result;
  }

} // end of extern "C"
