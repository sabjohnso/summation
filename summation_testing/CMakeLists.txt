find_package(GTest)

macro(summation_add_test test_name exe_name)
  add_executable(${exe_name} ${ARGN})
  target_link_libraries(${exe_name} PRIVATE
    summation::summation
    GTest::gtest_main)
  add_test(${test_name} ${exe_name})
endmacro()

summation_add_test(naive naive_test naive_test.cpp)
summation_add_test(kahan kahan_test kahan_test.cpp)
summation_add_test(neumaier neumaier_test neumaier_test.cpp)
summation_add_test(klein klein_test klein_test.cpp)

