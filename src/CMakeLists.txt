add_library(sorting_algorithms
        comb_sort.cpp
        heap_sort.cpp
        bucket_sort.cpp
)

target_include_directories(sorting_algorithms PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
