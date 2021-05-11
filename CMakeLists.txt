cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project (minimal VERSION 0.0.0)

add_compile_definitions("$<$<CONFIG:Debug>:_DEBUG>")
add_compile_definitions("$<$<CONFIG:Debug>:ENABLE_TEST_MSG>")

# ---------------------------------------------------------------------------
if (NOT CMAKE_CROSSCOMPILING)
  if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    enable_testing()
    include(CTest)
  endif()
endif()

# ---------------------------------------------------------------------------
find_package(PythonLibs 3.7 REQUIRED)
string(REGEX REPLACE "^([0-9]+)\\.([0-9]+)\\.([0-9])+.*$" "\\1" pmajor ${PYTHONLIBS_VERSION_STRING} )
string(REGEX REPLACE "^([0-9]+)\\.([0-9]+)\\.([0-9])+.*$" "\\2" pminor ${PYTHONLIBS_VERSION_STRING} )
set(boost_python "python${pmajor}${pminor}")
set(python_extension_install "/usr/lib/python${pmajor}.${pminor}/site-packages")

if("${CMAKE_CXX_COMPILER_VERSION}" VERSION_LESS "9.1")
  add_compile_options("-Wno-psabi")
endif()

find_package(Boost 1.69 COMPONENTS unit_test_framework ${boost_python} program_options REQUIRED)

# ---------------------------------------------------------------------------
add_subdirectory(src)
