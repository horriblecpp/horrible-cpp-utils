cmake_minimum_required(VERSION 3.18...3.20)

project(HorribleUtils
  VERSION 0.0.0.1
  DESCRIPTION  "C++ Standard Library lacks some stuff. "
  HOMEPAGE_URL "git@github.com:horriblecpp/horrible-cpp-utils.git"
  LANGUAGES CXX
)

set(CMAKE_MODULE_PATH "${HorribleUtils_SOURCE_DIR}/cmake")











option(CREATE_TESTS "Tests on by default" ON)

if (CREATE_TESTS)
  enable_testing()
  include(GoogleTest)
  add_subdirectory(tests)
endif()

