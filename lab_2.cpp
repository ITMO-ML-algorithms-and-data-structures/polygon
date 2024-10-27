#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//функция для assert
bool allDupl(vector<int> vec) {                                  
    for (int i = 1; i < vec.size(); i++) {
        if (vec[0] != vec[i]) {
            return false;
        }
    }
    return true;
}

//Функция для удаления дубликатов из вектора
void removeDuplicates(vector<int>& vec) {
    //Проверяем, что входной вектор не пустой
    assert(!vec.empty() && "Входной вектор не должен быть пустым!");
    assert(vec.size() > 1 && "Вектор с одним элементом");
    assert(vec.size()>1 && !allDupl(vec) && "Входной вектор заполнен одним и тем же значением!");
    
    
    //Создаем временный вектор для хранения уникальных элементов
    vector<int> uniqueVec;
    //Память выделяется под вектор (в начале 0 байт, динамически увеличивается при добавлении элементов)
    
    //Проходим по каждому элементу в исходном векторе
    for (int i = 0; i < vec.size(); i++) {
        //существует ли элемент vec[i] в векторе uniqueVec
        if (find(uniqueVec.begin(), uniqueVec.end(), vec[i]) == uniqueVec.end()) {
            //Если элемент уникален, добавляем его в уникальный вектор
            uniqueVec.push_back(vec[i]);
            //Каждый push_back увеличивает размер на sizeof(int) = 4 байта
        }
    }

    //Очищаем исходный вектор, чтобы удалить старые данные
    vec.clear();

    //Копируем уникальные элементы обратно в исходный вектор
    for (int i = 0; i < uniqueVec.size(); i++) {
        vec.push_back(uniqueVec[i]);
    }
    

    //На случай если при дублировании массива в vec будет добавлен лишний, либо недобавлен нужный элемент
    assert(uniqueVec.size() == vec.size() && "Ошибка: количество уникальных элементов не совпадает!");
}


int main() 
{
    vector<int> numbers = { 4,1,2,4,23,5,26,2,1,4,2};
    //11 элементов * sizeof(int) = 11 * 4 = 44 байта
    
    setlocale(LC_ALL, "RU");
    cout << "Исходный массив: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    //Удаляем дубликаты из вектора
    removeDuplicates(numbers);

    cout << "Массив без дубликатов: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

//Итого: 44 байта + 24 байта (для uniqueVec: 6 элементов × 4 байта/элемент) = 68 байт


//Тест через фреймворк
#include <gtest/gtest.h>

bool allDupl(std::vector<int> vec);
void removeDuplicates(std::vector<int>& vec);

//Тестовый случай для функции allDupl
TEST(AllDuplTest, AllElementsAreSame) {
    std::vector<int> vec = {1, 1, 1, 1};
    EXPECT_TRUE(allDupl(vec));
}

TEST(AllDuplTest, NotAllElementsAreSame) {
    std::vector<int> vec = {1, 2, 1, 1};
    EXPECT_FALSE(allDupl(vec));
}

//Тестовый случай для функции removeDuplicates
TEST(RemoveDuplicatesTest, BasicFunctionality) {
    std::vector<int> vec = {1, 2, 2, 3, 4, 4, 5};
    removeDuplicates(vec);
    std::vector<int> expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(vec, expected);
}

TEST(RemoveDuplicatesTest, NoDuplicates) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    removeDuplicates(vec);
    std::vector<int> expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(vec, expected);
}

TEST(RemoveDuplicatesTest, AllDuplicates) {
    std::vector<int> vec = {1, 1, 1, 1};
    removeDuplicates(vec);
    std::vector<int> expected = {1};
    EXPECT_EQ(vec, expected);
}

TEST(RemoveDuplicatesTest, EmptyVector) {
    std::vector<int> vec;
    EXPECT_DEATH(removeDuplicates(vec), "Входной вектор не должен быть пустым!");
}

TEST(RemoveDuplicatesTest, SingleElementVector) {
    std::vector<int> vec = {1};
    EXPECT_DEATH(removeDuplicates(vec), "Вектор с одним элементом");
}

TEST(RemoveDuplicatesTest, AllSameElements) {
    std::vector<int> vec = {2, 2, 2, 2};
    EXPECT_DEATH(removeDuplicates(vec), "Входной вектор заполнен одним и тем же значением!");
}

//Основная функция для запуска тестов
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
