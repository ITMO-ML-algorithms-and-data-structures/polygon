#include <iostream>

#include "cocktail.cpp"
#include "bucket.cpp"
#include "heapsort.cpp"

int main() 
{
    std::cout << "cocktail sort:" << std::endl;
    test_cocktail_best();
    test_cocktail_common();
    test_cocktail_worst();
    test_cocktail_large_stat();

    std::cout << "bucket sort:" << std::endl;
    test_bucket_best();
    test_bucket_common();
    test_bucket_worst();
    test_bucket_large_stat();

    std::cout << "heap sort:" << std::endl;
    test_heap_best();
    test_heap_common();
    test_heap_worst();
    test_heap_large_stat();
}
