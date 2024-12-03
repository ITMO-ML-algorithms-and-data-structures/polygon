set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-builtin")

add_executable(test_comb_sort test_comb_sort.cpp)
add_executable(test_heap_sort test_heap_sort.cpp)
add_executable(test_bucket_sort test_bucket_sort.cpp)

target_include_directories(test_comb_sort PUBLIC ${CUNIT_INCLUDE_DIRS})
target_include_directories(test_heap_sort PUBLIC ${CUNIT_INCLUDE_DIRS})
target_include_directories(test_bucket_sort PUBLIC ${CUNIT_INCLUDE_DIRS})

target_link_libraries(test_comb_sort sorting_algorithms ${CUNIT_LIBRARIES} -static-libstdc++ -static-libgcc -lmingw32)
target_link_libraries(test_heap_sort sorting_algorithms ${CUNIT_LIBRARIES} -static-libstdc++ -static-libgcc -lmingw32)
target_link_libraries(test_bucket_sort sorting_algorithms ${CUNIT_LIBRARIES} -static-libstdc++ -static-libgcc -lmingw32)


