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




  float
  fsum_range(Algorithm alg, const float* first, const float* last){
    double result;
    switch(alg){
    case NAIVE:
      result = sum_range(naive, first, last); break;
    case KAHAN:
      result = sum_range(kahan, first, last); break;
    case NEUMAIER:
      result = sum_range(neumaier, first, last); break;
    case KLEIN:
      result = sum_range(klein, first, last); break;
    default:
      throw logic_error("invalid algorithm flag passed to dsum2: " + to_string(alg));
    }
    return result;
  }

  double
  dsum_range(Algorithm alg, const double* first, const double* last){
    double result;
    switch(alg){
    case NAIVE:
      result = sum_range(naive, first, last); break;
    case KAHAN:
      result = sum_range(kahan, first, last); break;
    case NEUMAIER:
      result = sum_range(neumaier, first, last); break;
    case KLEIN:
      result = sum_range(klein, first, last); break;
    default:
      throw logic_error("invalid algorithm flag passed to dsum2: " + to_string(alg));
    }
    return result;
  }

  long double
  lsum_range(Algorithm alg, const long double* first, const long double* last){
    long double result;
    switch(alg){
    case NAIVE:
      result = sum_range(naive, first, last); break;
    case KAHAN:
      result = sum_range(kahan, first, last); break;
    case NEUMAIER:
      result = sum_range(neumaier, first, last); break;
    case KLEIN:
      result = sum_range(klein, first, last); break;
    default:
      throw logic_error("invalid algorithm flag passed to dsum2: " + to_string(alg));
    }
    return result;
  }

  float
  ftransum_range(Algorithm alg, float(*f)(float), const float* first, const float* last){
    float result;
    switch(alg){
    case NAIVE:
      result = transum_range(naive, f, first, last); break;
    case KAHAN:
      result = transum_range(kahan, f, first, last); break;
    case NEUMAIER:
      result = transum_range(neumaier, f, first, last); break;
    case KLEIN:
      result = transum_range(klein, f, first, last); break;
    default:
      throw logic_error("invalid algorithm flag passed to dsum2: " + to_string(alg));
    }
    return result;
  }

  double
  dtransum_range(Algorithm alg, double(*f)(double), const double* first, const double* last){
    double result;
    switch(alg){
    case NAIVE:
      result = transum_range(naive, f, first, last); break;
    case KAHAN:
      result = transum_range(kahan, f, first, last); break;
    case NEUMAIER:
      result = transum_range(neumaier, f, first, last); break;
    case KLEIN:
      result = transum_range(klein, f, first, last); break;
    default:
      throw logic_error("invalid algorithm flag passed to dsum2: " + to_string(alg));
    }
    return result;
  }

  long double
  ltransum_range(Algorithm alg, long double(*f)(long double), const long double* first, const long double* last){
    long double result;
    switch(alg){
    case NAIVE:
      result = transum_range(naive, f, first, last); break;
    case KAHAN:
      result = transum_range(kahan, f, first, last); break;
    case NEUMAIER:
      result = transum_range(neumaier, f, first, last); break;
    case KLEIN:
      result = transum_range(klein, f, first, last); break;
    default:
      throw logic_error("invalid algorithm flag passed to dsum2: " + to_string(alg));
    }
    return result;
  }

  float
  ftran2sum_range(
    Algorithm alg, float(*f)(float, float),
    const float* first1, const float* last1,
    const float* first2, const float* last2) {
    float result;
    switch(alg){
    case NAIVE:
      result = tran2sum_range(naive, f, first1, last1, first2, last2); break;
    case KAHAN:
      result = tran2sum_range(kahan, f, first1, last1, first2, last2); break;
    case NEUMAIER:
      result = tran2sum_range(neumaier, f, first1, last1, first2, last2); break;
    case KLEIN:
      result = tran2sum_range(klein, f, first1, last1, first2, last2); break;
    default:
      throw logic_error("invalid algorithm flag passed to dsum2: " + to_string(alg));
    }
    return result;
  }

  double
  dtran2sum_range(
    Algorithm alg, double(*f)(double, double),
    const double* first1, const double* last1,
    const double* first2, const double* last2) {
    double result;
    switch(alg){
    case NAIVE:
      result = tran2sum_range(naive, f, first1, last1, first2, last2); break;
    case KAHAN:
      result = tran2sum_range(kahan, f, first1, last1, first2, last2); break;
    case NEUMAIER:
      result = tran2sum_range(neumaier, f, first1, last1, first2, last2); break;
    case KLEIN:
      result = tran2sum_range(klein, f, first1, last1, first2, last2); break;
    default:
      throw logic_error("invalid algorithm flag passed to dsum2: " + to_string(alg));
    }
    return result;
  }

  long double
  ltran2sum_range(
    Algorithm alg, long double(*f)(long double, long double),
    const long double* first1, const long double* last1,
    const long double* first2, const long double* last2) {
    long double result;
    switch(alg){
    case NAIVE:
      result = tran2sum_range(naive, f, first1, last1, first2, last2); break;
    case KAHAN:
      result = tran2sum_range(kahan, f, first1, last1, first2, last2); break;
    case NEUMAIER:
      result = tran2sum_range(neumaier, f, first1, last1, first2, last2); break;
    case KLEIN:
      result = tran2sum_range(klein, f, first1, last1, first2, last2); break;
    default:
      throw logic_error("invalid algorithm flag passed to dsum2: " + to_string(alg));
    }
    return result;
  }

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
