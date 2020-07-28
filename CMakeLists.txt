cmake_minimum_required(VERSION 3.12)

project(summation VERSION 0.1.0 LANGUAGES C CXX)

option(summation_BUILD_TESTING "Build the summation tests" ON)

include(GNUInstallDirs)
set(summation_INSTALL_BINDIR ${CMAKE_INSTALL_BINDIR})
set(summation_INSTALL_LIBDIR ${CMAKE_INSTALL_LIBDIR})
set(summation_INSTALL_INCLUDEDIR ${CMAKE_INSTALL_INCLUDEDIR})
set(summation_INSTALL_CONFDIR ${summation_INSTALL_LIBDIR}/cmake/summation-${PROJECT_VERSION})

list(INSERT CMAKE_MODULE_PATH 0 ${PROJECT_SOURCE_DIR}/cmake)
include(summation_deps)

add_subdirectory(summation)

if(summation_BUILD_TESTING)
  include(CTest)
  if(BUILD_TESTING)
    add_subdirectory(summation_testing)
  endif()
endif()

install(EXPORT summation_EXPORTS
  NAMESPACE summation::
  FILE summation-exports.cmake
  DESTINATION ${summation_INSTALL_CONFDIR})

configure_file(summation-config.cmake.in summation-config.cmake)
install(FILES ${PROJECT_BINARY_DIR}/summation-config.cmake
  DESTINATION ${summation_INSTALL_CONFDIR})








