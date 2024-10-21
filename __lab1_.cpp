#include <iostream>
#include <vector>
#include <unordered_map>

// функция проверки на простоту
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    // кол-во элементов и сами элементы
    int n;
    std::cin >> n;

    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    // подсчет кол-ва вхождений
    std::unordered_map<int, int> countMap;

    for (int num : numbers) {
        if (isPrime(num)) {
            countMap[num]++;
        }
    }

    // выводим все простые числа, которые встречаются четное кол-во раз
    for (const auto& pair : countMap) {
        if (pair.second % 2 == 0) {
            std::cout << pair.first << " ";
        }
    }

    return 0;
}
