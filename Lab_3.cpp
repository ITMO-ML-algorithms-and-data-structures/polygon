#include <iostream>
#include <unordered_map>
#include <vector>

int main(){

    //создание хэш-таблицы для хранения кол-ва повторений слов
    std::unordered_map<std::string, int> frequancyMap; //время - O(1); память - O(n), где n - кол-во уникальных строк + n*4 байта + длина каждой строки + 3 * 1 байт (нуль-терминатор)

    //создание вектора строк
    std::vector<std::string> inputArray = {"Orange", "Red", "Green", "Orange"}; //время - О(1); память - О(1)
    
    //размер вектора 
    std::cout << inputArray.size() << std::endl; //время - О(1) + О(1) + О(1); память - 4 байта
     
    //время - O(n)
    //считаем повторения слов
    for (const std::string& word : inputArray){ //время - O(1)
        frequancyMap[word]++;
    }

    //время - O(n)
    //заменяем слова на число их повторений 
    for (std::string& word : inputArray){ //время - O(1)
        word = std::to_string(frequancyMap[word]);
    }

    //время - O(n)
    //выводим кол-во повторений каждого слова
    for (const std::string& count : inputArray){ //время - - O(1)
        std::cout << count << " "; //время - O(1) + O(1) + O(1)
    }

    return 0;

}

//подсчет памяти:
//3 + 3*4 + 6 + 3 + 5 + 3 + 4 = 36 байт

//время - O(n)