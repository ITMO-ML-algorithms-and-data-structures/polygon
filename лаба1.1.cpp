#include <iostream>
#include <vector>
#include <set>

std::vector<int> Dublicate(const std::vector<int>& vec) {
                // Используем множество для хранения уникальных элементов
                std::set<int> unique_elements(vec.begin(), vec.end());

                // Память, использованная для вектора
                size_t vector_memory = vec.size() * sizeof(int);

                // Память, использованная для множества
                size_t set_memory = unique_elements.size() * sizeof(int);

                // Общие размеры
                std::cout << "Size of vector: " << vector_memory << " bytes" << std::endl;
                std::cout << "Size of set: " << set_memory << " bytes" << std::endl;
                std::cout << "All size: " << set_memory + vector_memory << " bytes" << std::endl;

                // Конвертируем множество обратно в вектор
                return std::vector<int>(unique_elements.begin(), unique_elements.end());
            }

void testDublicate() {              // функция для теста 

    std::vector <int> TestStr1 = { 1,1,2,2,3,3,4,4,5,5 };
    std::vector <int> result1 = { 1,2,3,4,5 };
    if (result1 == Dublicate(TestStr1)) {
        std::cout << "Тест пройден" << std::endl;
    }
    else {
        std::cout << "Тест провален" << std::endl;
    }


    std::vector <int> TestStr2 = { 52,52,52,52,52 };
    std::vector <int> result2 = { 52 };
    if (result2 == Dublicate(TestStr2)) {
        std::cout << "Тест пройден" << std::endl;
    }
    else {
        std::cout << "Тест провален" << std::endl;
    }

    std::vector <int> TestStr3 = {};
    std::vector <int> result3 = {};
    if (result3 == Dublicate(TestStr3)) {
        std::cout << "Тест пройден" << std::endl;
    }
    else {
        std::cout << "Тест провален" << std::endl;
    }

}



int main() {
    setlocale(LC_ALL, "Russian");
    testDublicate(); // запуск тестов
    return 0;
        }
