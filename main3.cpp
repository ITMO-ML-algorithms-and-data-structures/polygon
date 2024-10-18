#include <iostream>
#include <vector>
#include <cassert>
#include <random>
#include <cmath>
#include <unordered_set>


void RandomKSamplerReplace(std::vector<int>& source, int k) {
    int n = source.size();
    assert(n >= k);
    
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // O(n - k)
    for (int i = k; i < n; i++) {
        int j = gen() % (i + 1);
        if (j < k) {
            source[j] = source[i];
        }
    }
    // O(1) - тут массив обрезается
    source.resize(k);
}


void RandomKSampler(std::vector<int>& source, std::vector<int>& result) {
    int n = source.size();
    int k = result.size();
    assert(n >= k);
    
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // O(k)
    for (int i = 0; i < k; i++) {
        result[i] = source[i];
    }
    // O(n - k)
    for (int i = k; i < n; i++) {
        int j = gen() % (i + 1);
        if (j < k) {
            result[j] = source[i];
        }
    }
}


void test() {
    std::random_device rd;
    std::mt19937 gen(rd());
    
    int n = gen() % 1000;
    int k = fmin(gen() % 100, n * 2 / 3);
    std::unordered_set<int> unique;
    std::vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = i + 1;
    }
    RandomKSamplerReplace(res, k);
    
    for (int i = 0; i < res.size(); i++) {
        unique.insert(i);
    }
    
    if ((res.size() != k) || (unique.size() != k)) {
        std::cout << "Failed" << "\n";
    } else {
        std::cout << "OK" << "\n";
    }
}


int main(int argc, const char * argv[]) {
//    Тесты
    test();
    test();
    test();
    
//     O(n) - создание массива
    std::vector<int> arr = {1, 2, 3, 4, 5, 6};
    
//     O(n - k) Первый вариант реализации (самый быстрый, красивый, ...), но с заменой и обрезкой изначального массива
    RandomKSamplerReplace(arr, 3);
    
//     O(n) Второй вариант реализации, но сюда же нужно передавать массив, в который будет происходить запись (чтобы внутри на создавать всякие костыли) - второй массив должен быть размера k
//    std::vector<int> res(3, 0);
//    RandomKSampler(arr, res);
    
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    
    std::cout << std::endl;
    
    return 0;
}

