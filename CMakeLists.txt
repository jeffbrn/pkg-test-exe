cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    test-exe
    VERSION 0.1.0
    DESCRIPTION "test exe to use test-lib"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    test-exe_lib OBJECT
    source/lib.cpp
)

target_include_directories(
    test-exe_lib ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(test-exe_lib PUBLIC cxx_std_17)

# ---- Declare executable ----

add_executable(test-exe_exe source/main.cpp)
add_executable(test-exe::exe ALIAS test-exe_exe)

set_property(TARGET test-exe_exe PROPERTY OUTPUT_NAME test-exe)

target_compile_features(test-exe_exe PRIVATE cxx_std_17)

target_link_libraries(test-exe_exe PRIVATE test-exe_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT test-exe_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of test-exe"
  )
endif()

include(cmake/dev-mode.cmake)
