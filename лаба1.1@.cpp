#include <iostream>
#include <unordered_map>
#include <cassert>

int Dublicate(short int* arr1, short int* arr2, int size){ // функция, которая ищет дубликаты и не добавляет их в новый
                                               // массив( возвращает длину второго массива)
    bool found; // +1 байт
    short int size2 = 0; // +2 байта
    for (short int i = 0; i < size; i++) {
        found = false;
        for (short int j = 0; j < i; j++) { // 2m
            if ((arr1[i]) == (arr1[j])) {
                found = true;
                break;
            }
        }
        if (!found) {
            arr2[size2] = arr1[i];
            size2 += 1;
        }
    }
    return size2;
}
void testDublicate() {              // функция для теста 

    short int input_1[] = { 1,1,2,2,3,3,4,4,5,5 };
    short int output_1[10];
    short int result = Dublicate(input_1, output_1, 10);
    assert((result == 5));

    short int input_2[] = {52,52,52,52,52 };
    short int output_2[5];
    result = Dublicate(input_2, output_2, 5);
    assert((result == 1));

    short int input_3[] = { 1,4,8,8,4,20,11,9 };
    short int output_3[8];
    result = Dublicate(input_3, output_3, 8);
    assert((result == 6));

    std:: cout << "Тесты пройдены" << std::endl;
    }



int main() {
    setlocale(LC_ALL, "Russian");
    short int size, size2, i; // 2+2+2
    std::cout << "введите количество элементов массива от 0 до 10000 : ";
    std::cin >> size;
    size2 = 0;
    short int* arr1 = new short int[size];
    short int* arr2 = new short int[size];
    if (size < 10000) { // заполнение начального массива, учитывая ограничения
        if (size > 0) {
            for (i = 0; i < size; i++) {
                std::cout << "\nвведите элемент массива, значение которого больше 0 и меньше 100: ";
                std::cin >> arr1[i]; // 2n
                if (arr1[i] > 100) {
                    std::cout << "ваш элемент не входит в область допустимых значений";
                    i--;
                }
                else if (arr1[i] < 1) {
                    std::cout << "ваш элемент не входит в область допустимых значений";
                    i--;
                }

            }

            size2 = Dublicate(arr1, arr2, size);

            testDublicate(); // запуск тестов

            std::cout << "массив без повторения значений: ";
            std::cout << "[";
            for (short int j = 0; j < size2; j++) {
                if (j!= size - 1){
                    std::cout << arr2[j] << ", ";
                }
                else std::cout << arr2[j];
            }
            std::cout << "]";
            delete[] arr1, arr2; // очищение памяти
            return 0;
        }
    }
} // всего: 1 + 2 + 2m + 2 + 2 + 2 + 2n = 9 + 2m + 2n байт