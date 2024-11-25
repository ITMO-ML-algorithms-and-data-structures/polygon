find_package(GTest REQUIRED)

add_executable(test_array_clustering
    test_array_clustering.cpp
)

target_link_libraries(test_array_clustering
    array_clustering
    GTest::GTest
    GTest::Main
)

add_test(NAME test_array_clustering COMMAND test_array_clustering)
