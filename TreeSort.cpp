#include <vector>
#include <iostream>
#include <cassert>
#include <time.h>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;


struct Node {
    int value; // 4 байта
    Node* left; // 8 байта
    Node* right; // 8 байта
    
    // Конструктор для создания нового узла.
    Node(int val): value(val), left(nullptr), right(nullptr) {}
};


// Функция для вставки элемента в дерево
Node* insertIterative(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value); // O(1), 20 байт на узел
    }

    Node* current = root; // 8 байт 
    while (true) { // Цикл обходит дерево до листа
        if (value < current->value){
            if (current->left == nullptr){
                current->left = new Node(value);  // O(1), 20 байт
                break;
            } else {
                current = current->left; // O(1)
            }
        } else {
            if (current->right == nullptr) {
                current->right = new Node(value);  // O(1), 20 байт
                break;
            } else {
                current = current->right; // O(1)
            }
        }
    }
    return root;
    // O(h)
    // Память: 20 байт на каждый новый узел.
}


// Функция для обхода дерева (сортировка дерева)
vector<int> Sorting(Node* root) {
    vector<int> result; //O(n)
    stack<Node*> st; // O(h)  h — высота дерева
    Node* current = root; //8 байт 
 
    while (!st.empty() || current != nullptr) { // пока стек не пуст или есть узлы для обработки
        if (current != nullptr) {
            st.push(current);
            current = current->left; // Переход к левому поддереву
        } else {
            current = st.top();
            st.pop();
            result.push_back(current->value); // Обработка узла
            current = current->right; // Переход к правому поддереву
        }
    }

    return result; // Каждый узел обрабатывается ровно один раз - O(n)
}


// Основная функция TreeSort
vector<int> TreeSort(vector<int>& arr) {
    if (arr.empty()) {
        return {}; // O(1)
    }

    Node* root = nullptr; // 8 байт
    for (int value: arr) { // O(n * h)  // Обход всех элементов массива.
        root = insertIterative(root, value);  // Вставляем элементы в дерево (O(h) для каждого элемента).
    }

    return Sorting(root); // O(n) // Сортируем дерево и возвращаем результат
}


// Вывод массива
void printArray(const std::vector<int>& arr) {
    for (const int& num : arr) { // О(n)
        cout << num << " ";
    }
}


// Тесты на правильность ответов (без проверки на скорость)
void correct_tests() {
    vector<int> excepted = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    vector<int> input_1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    input_1 = TreeSort(input_1);
    assert(input_1 == excepted);

    vector<int> input_2 = {2, 7, 8, 5, 3, 4, 6, 9, 0, 1};
    input_2 = TreeSort(input_2);
    assert(input_2 == excepted);
    
    vector<int> input_3 = {6, 1, 7, 9, 4, 8, 3, 2, 0, 5};
    input_3 = TreeSort(input_3);
    assert(input_3 == excepted);
    
    vector<int> input_4 = {2, 4, 1, 3, 5, 6, 8, 7, 9, 0};
    input_4 = TreeSort(input_4);
    assert(input_4 == excepted);
    cout << "Correctness tests - complete" << std::endl;
}


// Тесты на время (без проверки на правильность ответов)
void time_tests() {
    std::vector<int> test_sizes = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 100000};
    
    for (const int sz : test_sizes) {
        vector<int> random_vec(sz, 0);
        srand(time(0));
        generate(random_vec.begin(), random_vec.end(), rand);
        
        clock_t start = clock();
        TreeSort(random_vec);
        
        cout << "На сортировку массива длины " << sz << " ушло " << double(clock() - start)/CLOCKS_PER_SEC*100 << " мс" << endl;
    }
}


int main() {
    correct_tests();
    time_tests();
    vector<int> arr = {3, 9, 1, 4, 2, 8, 5, 7, 6};
    vector<int> sortedArr = TreeSort(arr);
    printArray(sortedArr);

    return 0;
}
