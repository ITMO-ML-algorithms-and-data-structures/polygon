#include <iostream>
#include <vector>
#include <fstream>
#include <random>

// функция перемешивания элементов массива, внутри используется алгоритм Фишера-Йетса
std::vector<int> shuffle_array(std::string path) {
    std::ifstream file(path); // O(1)
    std::vector<int> array; // O(1)

    // читаем файл
    int number; // O(1)
    while (file >> number) { // O(n)
        array.push_back(number); // O(1)
    }
    file.close();

    // инициализация генератора
    std::random_device rd; // O(1)
    std::mt19937 gen(rd());  // O(1) - генератором псевдослучайных чисел по методу Mersenne twister

    // идем с конца, чтобы уже перемешенное элемент повторно не трогать
    for (int i = array.size() - 1; i > 0; --i) { // O(N) - цикл по массиву
        // Генерация случайного индекса от 0 до i - 1
        std::uniform_int_distribution<> dist(0, i); // O(1)
        // меняем местами наш элмент и элмент под случайным идексом
        std::swap(array[i], array[dist(gen)]); // O(1)
    }

    // сложность алгорится O(n)
    return array;
}

int main() {
    // несколько раз вызываю функцию, чтобы убедиться в случайности перемещивания
    for (int i = 0; i <= 10; ++i) {
        // Вызов функции shuffle_array
        std::vector<int> arr = shuffle_array("test_dir/test_7.txt");

        // вывод
        for (int i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}
