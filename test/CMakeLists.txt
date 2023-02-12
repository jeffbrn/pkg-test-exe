# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(test-exeTests LANGUAGES CXX)

# ---- Tests ----

add_executable(test-exe_test source/test-exe_test.cpp)
target_link_libraries(test-exe_test PRIVATE test-exe_lib)
target_compile_features(test-exe_test PRIVATE cxx_std_17)

add_test(NAME test-exe_test COMMAND test-exe_test)

# ---- End-of-file commands ----

add_folders(Test)
