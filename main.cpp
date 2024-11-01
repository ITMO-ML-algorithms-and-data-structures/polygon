#include <iostream>
#include <vector>
#include <unordered_map>  // O(1)

// Илья, Евгений, София

void print_vector(std::string prefix, const std::vector<int> &vec) {
    std::cout << prefix;
    for (auto val : vec) {
        std::cout << " " << val;
    }
    std::cout << std::endl;
}


int test1(const std::vector<std::string> arr) {
    // Если по ссылке (есть "&" амперсанта) - значит входной массив в другой (вызываемой) функции изменится
    // Если копия (нет амперсанты) - значит входной массив в другой (вызываемой) функции не будет изменятся
    return 0;
}

// O(1), O(N), O(N^2), O(log(N))

std::vector<int> label_encoder(const std::string arr[], const int size) {
    // Выходные данные
    std::vector<int> out(size, 0); // O(N)
    
    // Хэш-таблица для хранания соответствий: слово -> кодированное значение
    std::unordered_map<std::string, int> word_maping;

    int counter = 0; // O(1 + 1 + 1) = O(1)
    for (int i = 0; i < size; i++) {  // O(N)
        std::string word = arr[i];  // O(N) * O(1 + 1 + 1)

        if (word_maping.find(word) == word_maping.end()) {  // O(1 + 1 + 1)
            // [1, 2, 3, -1000000]
            // Если есть -> то вернет одно из значени 1 или 2 или 3
            // Если нет -> то вернут указатель на конец элемента (-100000)
            word_maping[word] = counter;  // word_maping.size()  // O(1 + 1)
            counter++;  // O(1 + 1)
        }

        out[i] = word_maping[word];  // O(1 + 1 + 1)
    }

    return out;
}

int main() {
    // std::vector<std::string> arr = {"Red", "Green", "Yellow", "Yellow"};
    // test1(arr);

    // Блок, в котором мы создали данные для тестирования
    const std::string arr[] = {"Red", "Green", "Yellow", "Yellow"};
    const int size = 4;

    // Блок, в котом мы пытаемся понять задачу
    // Case 1 -> пустой массив
    // [] -> []
    // Case 2 -> простой кейс на понимание
    // ["Red", "Green", "Yellow", "Yellow"] -> [0, 1, 2, 2]
    // ["Red", "Green", "Yellow", "Yellow", "Red"] -> [0, 1, 2, 2, 0]

    // Решение задачи - вызов функции
    std::vector<int> out = label_encoder(arr, size);

    // Вывод результата
    print_vector("Encoded vector: ", out);

    return 0;
}