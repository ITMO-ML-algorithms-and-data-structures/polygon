#include <iostream>
#include <vector>
#include <unordered_map>                                                          //не занимают памяти
#include <string>



void test_freqmap(std::vector<std::string>& inputArray){                          // задаем функцию для подсчета частоты элементов в массиве строк 
        std::unordered_map<std::string, int> frequencyMap;                        // создаем хеш-таблицу для хранения повторений каждого слова
    for (std::string& word : inputArray) {                                        // подсчет количества повторений для каждого элемента
        frequencyMap[word]++;                                                     //8N
    }
    for (std::string& word : inputArray) {                                        // заменяем каждое значение массива количеством его повторений
        word = std::to_string(frequencyMap[word]);                                //преобразуем количество повторений в строку// + 4 байта
    }

    for (const std::string& word : inputArray) {                                  //выводим измененный массив
        std::cout << word << " ";
    }
}
//8N+4
int main()
{
    //задаем тестовые массивы строк
    std::vector<std::string> inputArray = {"apple", "banana", "pineapple", "orange", "banana", "apple"};      
    std::vector<std::string> inputArray2 = {"apple", "banana", "apple"};                                      
    std::vector<std::string> inputArray3 = {" ", " ", " ", " ", " ", " "};                                    
    std::vector<std::string> inputArray4 = {"banana", "banana", "banana", "banana", "banana"};                
    
    //вызываем функцию для каждого заданного массива
    test_freqmap(inputArray);
    test_freqmap(inputArray2);
    test_freqmap(inputArray3);
    test_freqmap(inputArray4); 
                                                       
    
    return 0;
}

//память при максимальном размере: 8*127 + 4 = 1020