// Найти индекс, с которого начинается последовательность, являющаяся палиндромом
// Input: plip
// Output: 3

#include <iostream>

// Функция, которая определяет является ли последовательность палиндромом или нет.
bool palindrome(std::string subsequence, int left, int right) {
    while (left < right) { // пока наши левыые и правые индексы не встретятся будем их сравниватт
        if (subsequence[left] != subsequence[right]) { // если индексы не равны, то это не палиндром
            return false;
        }
        left++; // двигаем левый индекс вперед
        right--; // двигаем правый индекс назад


    }
    return true; // последовательность палиндром ура
}
// функция для поиска индекса с которого начинается палиндром
int findindex(std::string subsequence) {
    int N = subsequence.length();
    // будем идти по всей строке
    // проходим по всем символам строки и проверяем является ли наша строка палиндромом.
    for (int i = 0; i < N; ++i) {
        if (palindrome(subsequence, i, N - 1)) {
            return i; // если является - возвращаем индекс с которого это началось
        }
    }

    return -1; // не является возвращаем -1
}

int main() {

    std::string subsequence; // создаем переменную, куда будем записывать нашу последовательность

    std::cin >> subsequence; // записываем в неё нашу последовательность

    int index = findindex(subsequence);  // вызываем нашу функцию и записываем ее результат в index

    std::cout << index; // выводим

    return 0;
}