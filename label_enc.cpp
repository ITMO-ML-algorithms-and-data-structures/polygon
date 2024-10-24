#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <string>
#include <sstream>


// Функция для кодирования меток (слов) в числа, которая принимает путь к файлу в качестве аргумента и возвращает вектор целых чисел
std::vector<int> label_encoder(std::string path) {
    std::ifstream file(path);

    std::string line; // 32 байт
    int unique_index = 0; // 4 байта
    std::unordered_map<std::string, int> label_map; // n * (32 + 4) байт
    std::vector<int> label; //  24 байт + size * 4 байт

    // Чтение файла
    if (getline(file, line)) {
        std::istringstream stream(line);  // Создание потока для разбора строки
        std::string word;                 // 32 байта

        // Чтение слов из строки и их кодирование
        while (stream >> word) {
            if (not label_map.contains(word)) {
                label_map[word] = unique_index + 1;
                unique_index++;
            }
            // Добавление закодированного значения слова в вектор
            label.push_back(label_map[word]);
        }
    }

    file.close();
    return label;
}

int main() {
    // Вызов функции label_encoder
    std::vector<int> label = label_encoder("test_dir/test_4.txt");

    // Вывод закодированных меток на экран
    for (int i = 0; i < label.size(); i++) {
        std::cout << label[i] << ", ";
    }

    return 0;
}
