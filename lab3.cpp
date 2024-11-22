#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

std::vector<std::pair<char, int>> reducer(std::string fullLine){ //функция подсчёта количества одинаковых символов последовательности

    std::vector<std::pair <char, int>> counter;
    counter.push_back({fullLine[0], 1});

    for (int i = 1; i < fullLine.size(); i++){ //O(N)
        
        if (fullLine[i] == counter[counter.size()-1].first){//O(1+1+1), если следующий символ повторяется, то увеличиваем счётчик

            counter[counter.size()-1].second ++;

        }

        else{ //если следующий символ отличается, то вводим новый символ со знчением повтроений 1

            counter.push_back({fullLine[i], 1});

        }

    }

    return counter;

}

int main(){

    std::string word = "aaabbaaaaccbbd";//O(1+1+1)
    auto result = reducer(word);//O(1+1+1)

    for (int i = 0; i < result.size(); i++) { //O(N), печатаем вектор
        std::cout << result[i].first << result[i].second;
    }

    return 0;

}