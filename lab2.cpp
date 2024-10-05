#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
// худший случай: максимальные значения всех элементов повторяются максимальное количество раз
std::vector<int> word_values(const std::vector<std::string> &arr, int size)
{
    std::unordered_map<std::string, int> values;
    // int 2**15; string 2**100 => для N уникальных строк = (2**15 + 2**100) * N - в худшем случае
    // int 2**2; string 2**5 => для N уникальных строк = (2**2 + 2**5)*N = 36 * N- в лучшем случае
    for (int i = 0; i < size; i++)
    {
        // увеличиваем значение в хэш таблице для строк
        values[arr[i]]++;
    }
    // создаём массив для количества элементов
    std::vector<int> new_array(size);
    // для N элементов 4*N - в лучшем случае
    // для N элементов (2**15)*N - в худшем случае
    for (int i = 0; i < size; i++)
    {
        // добавляем в массив значения из хэш-таблицы
        new_array[i] = values[arr[i]];
    }
    // для N элементов памяти:
    // лучший случай: 36 * N + 4 * N
    // худший случай: (2**15 + 2**100) * N + (2**15)*N = (2**16 + 2**100) * N
    return new_array;
}

void test1() // повторяющиеся слова
{
    std::vector<std::string> arr = {"Orange", "Red", "Green", "Orange"};
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

void test2() // несколько слов повторяются
{
    std::vector<std::string> arr = {"Apple", "Banana", "Apple", "Cherry", "Banana"};
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

void test3() // уникальные слова
{
    std::vector<std::string> arr = {"Dog", "Cat", "Fish"};
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

void test4() // пустой массив
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

void test5() // все слова одинаковые
{
    std::vector<std::string> arr = {"hello", "hello", "hello"};
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

void test6() // одно слово повторяется 2 раза, другое - 3
{
    std::vector<std::string> arr = {"A", "B", "A", "C", "B", "A"};
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