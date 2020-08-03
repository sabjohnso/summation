configure_file(config.hpp.in config.hpp)
configure_file(capi.h.in capi.h)

add_library(summation_header INTERFACE)
set_target_properties(summation_header PROPERTIES EXPORT_NAME header)
target_include_directories(summation_header
  INTERFACE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<INSTALL_INTERFACE:${summation_INSTALL_INCLUDEDIR}>)
target_link_libraries(summation_header INTERFACE type_utility::type_utility)
add_library(summation::header ALIAS summation_header)

add_library(summation_capi capi.cpp)
set_target_properties(summation_capi PROPERTIES EXPORT_NAME capi)
target_include_directories(summation_capi
  PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<INSTALL_INTERFACE:${summation_INSTALL_INCLUDEDIR}>)
target_link_libraries(summation_capi PRIVATE summation::header)
add_library(summation::capi ALIAS summation_capi)

  
install(TARGETS summation_header summation_capi
  EXPORT summation_EXPORTS
  RUNTIME DESTINATION ${summation_INSTALL_BINDIR}
  LIBRARY DESTINATION ${summation_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${summation_INSTALL_LIBDIR})

install(FILES
  summation.hpp
  ${CMAKE_CURRENT_BINARY_DIR}/config.hpp
  ${CMAKE_CURRENT_BINARY_DIR}/capi.h
  DESTINATION ${summation_INSTALL_INCLUDEDIR})

install(FILES
  details/Accumulator.hpp
  details/accumulators.hpp
  details/base_types.hpp
  details/ExplicitCoercion.hpp
  details/ImplicitCoercion.hpp
  details/import.hpp
  details/Kahan.hpp
  details/Klein.hpp
  details/Naive.hpp
  details/Neumaier.hpp
  details/NoEnhancement.hpp
  details/SumArgs.hpp
  details/SumRange.hpp
  details/Template.hpp
  details/Tran2SumRange.hpp
  details/TranSumArgs.hpp
  details/TranSumRange.hpp
  details/types.hpp
  DESTINATION ${summation_INSTALL_INCLUDEDIR}/details)


