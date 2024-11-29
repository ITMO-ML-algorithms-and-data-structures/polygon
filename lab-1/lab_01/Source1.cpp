#include <iostream> 
#include <string> 
#include <vector> 
#include <unordered_map> 

std::vector<int> word_values(const std::vector<std::string>& arr, int size)
{
    std::unordered_map<std::string, int> values;
    for (int i = 0; i < size; i++)
    {
        values[arr[i]]++;
    }
    // создаём массив для количества элементов 
    std::vector<int> new_array(size);
    for (int i = 0; i < size; i++)
    {
        // добавляем в массив значения из хэш-таблицы 
        new_array[i] = values[arr[i]];
    }
    return new_array;
}

void test1()
{
    std::vector<std::string> arr = { "Orange", "Red", "Green", "Orange" };
    int size = 4;
    std::vector<int> ans = word_values(arr, size);

    if (ans == std::vector<int>{2, 1, 1, 2})
    {
        std::cout << "Test 1 passed" << std::endl;
    }
    else
    {
        std::cout << "Test 1 failed" << " ";
        for (int i = 0; i < size; i++)
        {
            std::cout << ans[i] << " ";
        }
    }
}

void test2()
{
    std::vector<std::string> arr = { "Apple", "Banana", "Apple", "Cherry", "Banana" };
    int size = 5;
    std::vector<int> ans = word_values(arr, size);

    if (ans == std::vector<int>{2, 2, 2, 1, 2})
    {
        std::cout << "Test 2 passed" << std::endl;
    }
    else
    {
        std::cout << "Test 2 failed" << " ";
        for (int i = 0; i < size; i++)
        {
            std::cout << ans[i] << " ";
        }
    }
}

void test3()
{
    std::vector<std::string> arr = { "Dog", "Cat", "Fish" };
    int size = 3;
    std::vector<int> ans = word_values(arr, size);

    if (ans == std::vector<int>{1, 1, 1})
    {
        std::cout << "Test 3 passed" << std::endl;
    }
    else
    {
        std::cout << "Test 3 failed" << " ";
        for (int i = 0; i < size; i++)
        {
            std::cout << ans[i] << " ";
        }
    }
}

void test4()
{
    std::vector<std::string> arr = {};
    int size = 0;
    std::vector<int> ans = word_values(arr, size);

    if (ans == std::vector<int>{})
    {
        std::cout << "Test 4 passed" << std::endl;
    }
    else
    {
        std::cout << "Test 4 failed" << " ";
        for (int i = 0; i < size; i++)
        {
            std::cout << ans[i] << " ";
        }
    }
}

void test5()
{
    std::vector<std::string> arr = { "Hello", "Hello", "Hello" };
    int size = 3;
    std::vector<int> ans = word_values(arr, size);

    if (ans == std::vector<int>{3, 3, 3})
    {
        std::cout << "Test 5 passed" << std::endl;
    }
    else
    {
        std::cout << "Test 5 failed" << " ";
        for (int i = 0; i < size; i++)
        {
            std::cout << ans[i] << " ";
        }
    }
}

void test6()
{
    std::vector<std::string> arr = { "A", "B", "A", "C", "B", "A" };
    int size = 6;
    std::vector<int> ans = word_values(arr, size);

    if (ans == std::vector<int>{3, 2, 3, 1, 2, 3})
    {
        std::cout << "Test 6 passed" << std::endl;
    }
    else
    {
        std::cout << "Test 6 failed" << " ";
        for (int i = 0; i < size; i++)
        {
            std::cout << ans[i] << " ";
        }
    }
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}