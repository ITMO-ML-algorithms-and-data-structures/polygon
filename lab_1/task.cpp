#include <iostream>
#include <unordered_map>


int main() 
{
    // Создаем массив
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;
    int array[size] {0};   

    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < size; ++i) 
        std::cin >> array[i];


    std::unordered_map<int, int> frequency;
    // Подсчитываем частоту встречаемости каждого числа
    for (int i = 0; i < size; ++i) 
    {
        frequency[array[i]]++;
    }

    // Суммируем числа, встречающиеся не менее двух раз
    int sum = 0;
    for (auto [number, count] : frequency) 
    {
        if (count >= 2) 
            sum += number;
    }

    // Вывод результата
    std::cout << "Сумма чисел, встречающихся не менее двух раз: " << sum << std::endl;

    return 0;
}
