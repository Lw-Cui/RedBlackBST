cmake_minimum_required(VERSION 2.8)

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.
set(PROJECT_NAME RbBST)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-std=c++14 -O0 -Wall -Wextra -W -ggdb3 -I. -pthread -L. -fprofile-arcs -ftest-coverage")

# If you want your own include/ directory, set this, and then you can do
# include_directories(${COMMON_INCLUDES}) in other CMakeLists.txt files.
# set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)

################################
# Normal Libraries & Executables
################################
#add_library(project1_lib project1.cpp)
add_executable(main main.cpp)
# Key idea: SEPARATE OUT your main() function into its own file so it can be its
# own executable. Separating out main() means you can add this library to be
# used elsewhere.

#target_link_libraries(project1 project1_lib)

################################
# Testing
################################
# This adds another subdirectory, which has 'project(gtest)'.
add_subdirectory(lib/gtest)

enable_testing()

# Include the gtest library. gtest_SOURCE_DIR is available due to
# 'project(gtest)' above.
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

##############
# Unit Tests
##############
add_executable(tests test.cpp)

# Standard linking to gtest stuff.
target_link_libraries(tests gtest gtest_main)

# This is so you can do 'make test' to see all your tests run, instead of
# manually running the executable runtest to see those specific tests.
add_test(NAME normal_test COMMAND tests)