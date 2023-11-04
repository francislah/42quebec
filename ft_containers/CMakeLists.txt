cmake_minimum_required(VERSION 3.22.1)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 98)
add_compile_options(-Wall -Werror -Wextra -ffast-math -ftree-vectorize)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_EXTRACT_TIMESTAMP true #To get rid of the warning
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(
	ft_STL
	SHARED
	inc/vector.hpp
	inc/type_traits.hpp
	inc/reverse_iterator.hpp
	inc/iterator_traits.hpp
)
set_target_properties(
	ft_STL
	PROPERTIES LINKER_LANGUAGE CXX
)

# add_executable(Equal test/Equal.cpp)
# target_link_libraries(Equal PUBLIC ft_STL GTest::gtest_main)
# add_test(NAME Equal COMMAND $<TARGET_FILE:Equal>)

# add_executable(MakePair test/MakePair.cpp)
# target_link_libraries(MakePair PUBLIC ft_STL GTest::gtest_main)
# add_test(NAME MakePair COMMAND $<TARGET_FILE:MakePair>)

# add_executable(LexicographicalCompare test/LexicographicalCompare.cpp)
# target_link_libraries(LexicographicalCompare PUBLIC ft_STL GTest::gtest_main)
# add_test(NAME LexicographicalCompare COMMAND $<TARGET_FILE:LexicographicalCompare>)

# add_executable(Map test/Map.cpp)
# target_link_libraries(Map PUBLIC ft_STL GTest::gtest_main)
# add_test(NAME Map COMMAND $<TARGET_FILE:Map>)

# add_executable(Pair test/Pair.cpp)
# target_link_libraries(Pair PUBLIC ft_STL GTest::gtest_main)
# add_test(NAME Pair COMMAND $<TARGET_FILE:Pair>)

add_executable(Reverse_Iterator test/Reverse_Iterator.cpp)
target_link_libraries(Reverse_Iterator PUBLIC ft_STL GTest::gtest_main)
add_test(NAME Reverse_Iterator COMMAND $<TARGET_FILE:Reverse_Iterator>)

add_executable(Type_Traits test/Type_Traits.cpp)
target_link_libraries(Type_Traits PUBLIC ft_STL GTest::gtest_main)
add_test(NAME Type_Traits COMMAND $<TARGET_FILE:Type_Traits>)

add_executable(Vector test/Vector.cpp)
target_link_libraries(Vector PUBLIC ft_STL GTest::gtest_main)
add_test(NAME Vector COMMAND $<TARGET_FILE:Vector>)

add_executable(vector_test ft_containers_test/vector_test.cpp)
target_link_libraries(vector_test PUBLIC ft_STL GTest::gtest_main)
add_test(NAME vector_test COMMAND $<TARGET_FILE:vector_test>)

add_executable(
	all_tests
    test/Type_Traits.cpp
    test/Vector.cpp
	test/Reverse_Iterator.cpp)
target_link_libraries(all_tests PUBLIC ft_STL GTest::gtest_main)
add_test(NAME all_tests COMMAND $<TARGET_FILE:all_tests>)

include(GoogleTest)
