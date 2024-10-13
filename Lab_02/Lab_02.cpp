
#include <iostream>
#include <string>
#include <unordered_map>
#include <conio.h> // библиотека, необходимая для работы оператора _getch();
#include <cassert>

std::string get_freq(std::vector<std::string> words) {
    // На вход 
    if (words.size() == 0)
        return "";

    std::unordered_map<std::string, int> freqs;
    for (std::string word : words)
        ++freqs[word];

    int i = 0;
    std::string result = "[";
    for (std::string word : words) {
        result += std::to_string(freqs[word]);
        result += ((++i < words.size()) ? "," : "]");
    }
    return result;
}


int main()
{
    std::string result;
    //ТЕСТ 1
    std::vector<std::string> words = { "orange", "yellow", "orange", "red", "blue", "blue" }; //заполнение списка
    result = get_freq(words);
    assert(result == "[2,1,2,1,2,2]");

    //ТЕСТ 2: проверка пустых значений входного списка
    std::vector<std::string> empty_words = { " "," "," " };
    result = get_freq(empty_words);
    assert(result == "[3,3,3]");
    
    // ТЕСТ 3: проверка пустого списка
    std::vector<std::string> empty = {};
    result = get_freq(empty);
    assert(result == "");

    // ТЕСТ 4: проверка длинного слова
    std::string longStr = std::string(100, 'a');
    std::vector<std::string> long_words = {longStr, longStr};
    result = get_freq(long_words);
    assert(result == "[2,2]");

    //ТЕСТ 5: данные из dataset
    std::string word;
    words.erase(words.begin(), words.end());
    while (std::cin >> word)
        words.push_back(word);

    result = get_freq(words);
    if(result == "")
        std::cout << "Таблица пуста.";
    else
        std::cout << result;

    _getch(); // задержка консоли; (функция получает символ из консоли без отображения) 
}
