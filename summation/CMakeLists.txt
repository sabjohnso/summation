configure_file(config.hpp.in config.hpp)

add_library(summation INTERFACE)
target_include_directories(summation
  INTERFACE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<INSTALL_INTERFACE:${summation_INSTALL_INCLUDEDIR}>)
target_link_libraries(summation INTERFACE type_utility::type_utility)

add_library(summation::summation ALIAS summation)
  
install(TARGETS summation
  EXPORT summation_EXPORTS
  RUNTIME DESTINATION ${summation_INSTALL_BINDIR}
  LIBRARY DESTINATION ${summation_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${summation_INSTALL_LIBDIR})

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/config.hpp
  summation.hpp
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


