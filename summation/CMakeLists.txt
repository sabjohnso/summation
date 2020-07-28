configure_file(config.hpp.in config.hpp)

add_library(summation INTERFACE)
target_include_directories(summation
  INTERFACE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<INSTALL_INTERFACE:${summation_INSTALL_INCLUDEDIR}>)

add_library(summation::summation ALIAS summation)
  
install(TARGETS summation
  EXPORT summation_EXPORTS
  RUNTIME DESTINATION ${summation_INSTALL_BINDIR}
  LIBRARY DESTINATION ${summation_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${summation_INSTALL_LIBDIR})

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/config.hpp
  DESTINATION ${summation_INSTALL_INCLUDEDIR})
