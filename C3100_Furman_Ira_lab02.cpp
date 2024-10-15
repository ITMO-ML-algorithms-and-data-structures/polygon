#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>



void test_freqmap(std::vector<std::string>& inputArray){                          // задаем функцию для подсчета частоты элементов в массиве строк 
        std::unordered_map<std::string, int> frequencyMap;                        // создаем хеш-таблицу для хранения повторений каждого слова
    for (std::string& word : inputArray) {                                        // подсчет количества повторений для каждого элемента
        frequencyMap[word]++;
    }
    for (std::string& word : inputArray) {                                        // заменяем каждое значение массива количеством его повторений
        word = std::to_string(frequencyMap[word]);                                //преобразуем количество повторений в строку
    }

    for (const std::string& word : inputArray) {                                  //выводим измененный массив
        std::cout << word << " ";
    }
}
int main()
{
    //задаем тестовые массивы строк
    std::vector<std::string> inputArray = {"apple", "banana", "pineapple", "orange", "banana", "apple"};      //размер массива - 24 байта + 6(объем массива)
    std::vector<std::string> inputArray2 = {"apple", "banana", "apple"};                                      //24 байта + 3
    std::vector<std::string> inputArray3 = {" ", " ", " ", " ", " ", " "};                                    //24 байта + 6
    std::vector<std::string> inputArray4 = {"banana", "banana", "banana", "banana", "banana"};                //24 байта + 5
    //при максимальном количестве повторений слова - размер массива 24 + 127
    //вызываем функцию для каждого заданного массива
    test_freqmap(inputArray);
    test_freqmap(inputArray2);
    test_freqmap(inputArray3);
    test_freqmap(inputArray4);
    std::cout<< inputArray3.capacity();                                                                       //функция для определения выделенной памяти                                                          

    return 0;
}
