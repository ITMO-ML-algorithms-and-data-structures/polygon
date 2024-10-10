#include <iostream>
#include <map>
using namespace std;

int is_isomorf(string word1, string word2) // + 64 байта 
{
    
    std::map<string, string> first_word_isomorf; // + 48 байт
    std::map<string, string> second_word_isomorf; // + 48 байт
    string letter1; // + 32 байта
    string letter2; // + 32 байта
    bool answer = 1; // +1 байт

    for (short int i = 0; i < word1.length(); i++) 
    // + 2 байта во время выполнения цикла 
    {
        letter1 = word1[i] + string();
        letter2 = word2[i] + string();
        bool statement = first_word_isomorf[letter1] == "" && second_word_isomorf[letter2] == ""; // +1 байт
        if (statement == 1) {
            first_word_isomorf[letter1] = letter2;
            // словарь имеет динамическую память и вычисляется по формуле:(sizeof(A) + sizeof(B) + ELEMENT_OVERHEAD) * N + CONTAINER_OVERHEAD
            second_word_isomorf[letter2] = letter1;
            // словарь имеет динамическую память и вычисляется по формуле:(sizeof(A) + sizeof(B) + ELEMENT_OVERHEAD) * N + CONTAINER_OVERHEAD
        }
        else 
        { 
            if (first_word_isomorf[letter1] != letter2 || second_word_isomorf[letter2] != letter1)
            {
            answer = 0;
            break;
            }
        }
    }
    return answer;
    // суммарная память: 48 * 2 + 32*4 + 1 + 2 * (sizeof(A) + sizeof(B) + ELEMENT_OVERHEAD) * N + CONTAINER_OVERHEAD
}