Summation
=========
Configurable Algorithms for Floating-Point Addition

### About
This library provides floating-point summation algorithms that are
configurable to provide the necessary balance between performance and
the elimination of round-off errors.

The following summation algorithms are implemented:
  - naive
  - Kahan
  - Neumaier
  - Klein

Additionally, there is a pairwise summation algorithm which uses any
of the aforementioned algorithms as a base and all of the base
algorithms can be configured to use enhanced precision.

### Warning
Certain compilers and compiler flags may eliminate the algorithm in
this library and it is important to take the proper care to ensure
user code is behaving as expected.
