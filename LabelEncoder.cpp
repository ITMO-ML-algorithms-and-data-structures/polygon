#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <fstream>
#include <vector>



std::vector<int> label_encoder(const std::string& path, const int& length) {
    // Мы ссылаемся на объекты в памяти, поэтому бесплатно

    // Создаем хэш-таблицу
    std::unordered_map<std::string, int> label_map; // 56 байт

    // Объявляем индекс для кодирования каждой метки данных
    short int index = 1; // 2 байта (По условию уникальных значений < 100)

    std::string str; // 32 байта

    // Открываем файл из path
    std::ifstream File(path);

    // Создаем вектор и резервируем для него место
    // для отсутсвия реаллокаций
    std::vector<int> returnVector;
    returnVector.reserve(length);

    // Считываем значения из файла в строку и проверяем все ли ок
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

            returnVector.push_back(label_map[word]);

        }
    } else {
        std::cout << "Something went wrong! Check path." << '\n';
    }

    return returnVector;
}

void test(const std::vector<int>& vec, const std::vector<int>& expectedAns){
    if (vec == expectedAns){
        std::cout << "Everything is OK" << "\n";
    } else {
        std::cout << "Wrong answer!" << "\n";
    }
}

int main() {
    // N - кол-во исходных данных, avg - средняя длина строки, n - кол-во уник. знач

    std::vector<int> expectedAns = {1, 2, 3, 1, 4, 2, 3, 5, 5, 6, 1, 7, 8, 9, 10, 11, 
                                1, 1, 4, 2, 6, 7, 11, 1, 1, 12, 13, 14, 15, 16, 
                                17, 18, 1, 2, 5, 2, 1, 6, 8};

    // Передаем в label_encoder() путь к входному файлу
    std::vector<int> Ans = label_encoder("test.txt", expectedAns.size());

    // Тестируем наш код 
    test(Ans,expectedAns);

    // На выходе имеем 32 + 56 + 2 + 32 + (avg + 2) * n байт 
    
    return 0;
}
