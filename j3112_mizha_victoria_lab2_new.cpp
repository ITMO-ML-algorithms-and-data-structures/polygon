#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>

int main() {
    std::ifstream file("/Users/vitamija/Desktop/dataset.csv");
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
        return 1;
    }

    
    
    std::vector<std::string> znacheniya; // Начальный заголовок вектора ~24 байта + 24N на string
    std::string word; // Инициализирует пустую строку, которая занимает ~32 байта на заголовок и указатели

    
    
    while (file >> word) { // ~10-20 байт на каждое слово
        znacheniya.push_back(word); // Вектор выделяет память с запасом (~1.5-2x текущего размера), для 1000 строк ~13.5 КБ
    }
    file.close(); // Освобождает буферы потока (~8 КБ)

    
    
    std::unordered_map<std::string, int> count; // Начальный размер ~56 байт + N(4 + 24) байт на string, int


    for (const std::string &str : znacheniya) {
        count[str]++; // Создает запись в словаре: ~46 байт на каждую уникальную строку
    }

    

    for (std::string &str : znacheniya) {
        str = std::to_string(count[str]); // Перезаписывает строку: средний размер для числа ~2-3 байта
    }

    
    for (const std::string &str : znacheniya) {
        std::cout << str << " ";
    }

    return 0;
}

