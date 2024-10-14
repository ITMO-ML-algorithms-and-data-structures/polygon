#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <cassert>
using namespace std;

// Задача: написать функцию, реализовывающую логику CountVectorizer


// сама функция: INPUT <- массив строк; OUTPUT -> массив из массивов с нулями и единицами
std::vector<std::vector<int>> countVectorizer(const std::vector<std::string>& inputArray, int arr_size){
    std::unordered_map<std::string, int> UsedWordsMap; // хэш-таблица (ключ - уникальный элемент, значение - его номер)
    int uniq_words_count = 0; // N = 4 байта----- переменная для кол-ва уникальных значений = их номера в итоговом списке
    for (const auto& text : inputArray) { 
        std::istringstream for_one_el(text); // определяем входной строковый поток
        std::string word; // N = 16 + m байт (m - длина слова)
        while (for_one_el >> word) { // идём по потоку до пробелов (пока строка)
            if (UsedWordsMap.find(word) == UsedWordsMap.end()){ 
                UsedWordsMap[word] = uniq_words_count++; // если это новый уник. элемент, делаем его ключом и присваиваем номер
            }
        }
        // N: Память под хэш-таблицу UnorderedMap = n * (16 + m + 4); (n - кол-во уник слов)
    }

    // новый массив из массивов из нулей (под ответ)
    std::vector<std::vector<int>> AnswerArray(arr_size, std::vector<int>(uniq_words_count, 0));
    // N память под AnswerArray = arr_size * n * 4 байт (0/1 - int = 4 байта)
    for (int i = 0; i < arr_size; ++i) { 
        std::istringstream for_one_el(inputArray[i]); // N: около того же что и на строку (16 + m)
        std::string word; // N = 16 + m байт (но память в стэке)
        while (for_one_el >> word) { // снова обрабатываем поток по слову (поток - каждая новая строка)
            AnswerArray[i][UsedWordsMap[word]] = 1; // ставим 1 по номеру строки и номеру слова из хэш-табл
        }
    }
    return AnswerArray;}
    /* N подсчёт (bytes) памяти под функцию (итог):
    A = n * (20 + m) -  память под хэш-таблицу UnorderedMap
    B = arr_size * n * 4 - память под AnswerArray
    C = arr_size * (16 + m) - память под std::string word
    D = 2 * (16 + m) - ПРИМЕРНАЯ память под istringstream* (очень сомнительно)
    n * (20 + m) + arr_size * n * 4 + arr_size * (16 + m) ...(+ 2 * (16 + m))
    для примера inputArray:
    3 * (20 + 6) + 4 * 3 * 4 + 4 * 22  = 78 + 48 + 88 = 214 байт (или 258 с istringstream)*/
    

int main(){ // тут тесты
    std::vector<std::string> inputArray = {"orange apple", "orange", "apple", "banana"};
    std::vector<std::string> inputArray1 = {"   ", "28  two", "one two"};
    std::vector<std::string> inputArray2 = {"pen   pineapple", "apple !", " !  pen"};
    std::vector<std::vector<int>> RightAnswer = {{1, 1, 0}, {1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    std::vector<std::vector<int>> RightAnswer1 = {{0, 0, 0}, {1, 1, 0}, {0, 1, 1}};
    std::vector<std::vector<int>> RightAnswer2 = {{1, 1, 0, 0}, {0, 0, 1, 1}, {1, 0, 0, 1}};

    /*std::vector<std::vector<int>> answer = countVectorizer(inputArray, arr_size);}
          for (const auto& smth : answer) { 
              for (int count : smth) {
                  std::cout << count << " ";
              }
              std::cout << std::endl;}*/

    assert(countVectorizer(inputArray, inputArray.size()) == RightAnswer);
    assert(countVectorizer(inputArray1, inputArray1.size()) == RightAnswer1);
    assert(countVectorizer(inputArray2, inputArray2.size()) == RightAnswer2);
    std:: cout << "yappi";
    return 0;
}
