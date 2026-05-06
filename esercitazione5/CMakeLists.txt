cmake_minimum_required(VERSION 3.20)
project(esercitazione5)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

set(SRC_test_sorts timecounter.cpp misura_tempi.cpp)


add_executable(misura_tempi ${SRC_test_sorts})

add_executable(test_bubblesort test_bubblesort.cpp)
add_test(NAME bubblesort COMMAND test_bubblesort)

add_executable(test_insertionsort test_insertionsort.cpp)
add_test(NAME insertionsort COMMAND test_insertionsort)

add_executable(test_selectionsort test_selectionsort.cpp)
add_test(NAME selectionsort COMMAND test_selectionsort)

add_executable(test_mergesort test_mergesort.cpp)
add_test(NAME mergesort COMMAND test_mergesort)

add_executable(test_quicksort test_quicksort.cpp)
add_test(NAME quicksort COMMAND test_quicksort)

add_executable(test_my_insertion_sort test_my_insertion_sort.cpp)
add_test(NAME my_insertion_sort COMMAND test_my_insertion_sort)

add_executable(test_my_sort test_my_sort.cpp)
add_test(NAME my_sort COMMAND test_my_sort)

enable_testing()