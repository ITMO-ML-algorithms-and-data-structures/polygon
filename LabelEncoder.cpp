#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <fstream>



void label_encoder(const std::string& path) {
    // Мы ссылаемся на объекты в памяти, поэтому бесплатно
    
    std::string str; // 32

    std::unordered_map<std::string, int> label_map; // 56 байт

    // Задаем вектор для закодированных значений
    std::vector<int> encoded_labels; // 24 байт

    // Объявляем индекс для кодирования каждой метки данных
    short int index = 1; // 2 байта (По условию уникальных значений < 100)

    // Открываем файл из path
    std::ifstream File(path);

    if (getline(File, str)) {
        // Создаем поток для чтения данных
        std::istringstream inputs(str);

        std::string word; // 32 байта

        // Считываем данные и проверяем, есть ли они в label_map 
        // если его нет, то добавляем пару (word, index)
        while (inputs >> word){
            if (label_map.find(word) == label_map.end()){
                label_map[word] = index; // (avg + 2) * n байт

                ++index;
            }
            std::cout << label_map[word];
        }
    }    
}

int main() {
    // N - кол-во исходных данных, avg - средняя длина строки, n - кол-во уник. знач

    // Передаем в label_encoder() путь к входному файлу
    label_encoder("input.txt");

    // На выходе имеем (24 + N * avg) + 56 + 24 + 2 + ((avg + 2) * n) + (24 + 2 * n) байт 
    
    return 0;
}
