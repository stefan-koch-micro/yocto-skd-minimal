
add_executable(minimal main.cpp)
target_link_libraries(minimal ${LIBS} ${Boost_LIBRARIES} )
install(TARGETS minimal DESTINATION bin)


# ---------------------------------------------------------------------------
# Without this, any build libraries automatically have names "lib{x}.so"
set(CMAKE_SHARED_MODULE_PREFIX "")

# add_boost_test: Create an executable, and mark it as a test.
function(add_python_module PY_FILENAME)
  get_filename_component(PY_NAME ${PY_FILENAME} NAME_WE)
  add_library(${PY_NAME} MODULE ${PY_NAME}.cpp)
  target_link_libraries(${PY_NAME} ${LIBS} ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
  target_include_directories(${PY_NAME} PRIVATE ${PYTHON_INCLUDE_DIRS})
  install(TARGETS ${PY_NAME} DESTINATION ${python_extension_install})
endfunction(add_python_module PY_FILENAME)

add_python_module(calculate.cpp)
