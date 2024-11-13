#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>

// Функция считывающая датасет
std::vector<int> load_data() {
    std::vector<int> data;
    std::ifstream file("C:\\Users\\R1300-W-1-Stud\\Documents\\ata.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string item;
        while (std::getline(ss, item, '\t')) {
            int item1 = std::stoi(item); // Используем int, так как массив должен быть типа int
            data.push_back(item1);
        }
    }
    return data;
}

// Тесты
int test_passed = 0;
int test_failed = 0;

void assertEqual(bool condition, const std::string& testName) {
    if (condition) {
        std::cout << "[PASSED] " << testName << "\n";
        test_passed++;
    }
    else {
        std::cout << "[NOT PASSED] " << testName << "\n";
        test_failed++;
    }
}

void report() {
    std::cout << "\nTests passed total: " << test_passed << "\n";
    std::cout << "Tests not passed total: " << test_failed << "\n";
}
// Функция тестирования
void test(std::vector<int>& arr) {
    // Тест 1: Проверка размера массива
    assertEqual(arr.size() <= 1e6, "Test input data by condition (size <= 1e6)");




    report();
}



class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    TreeNode* root;

    BinarySearchTree() : root(nullptr) {}

    // Вставка элемента в дерево
    void insert(int value) {
        root = insertRec(root, value);
    }

    // Инфиксный обход дерева (сортировка)
    void inorderTraversal(std::vector<int>& sortedArr) {
        inorderRec(root, sortedArr);
    }

private:
    // Рекурсивная функция для вставки элемента
    TreeNode* insertRec(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->value) {
            node->left = insertRec(node->left, value);
        } else {
            node->right = insertRec(node->right, value);
        }

        return node;
    }

    // Рекурсивная функция для инфиксного обхода
    void inorderRec(TreeNode* node, std::vector<int>& sortedArr) {
        if (node == nullptr) {
            return;
        }

        inorderRec(node->left, sortedArr);
        sortedArr.push_back(node->value);
        inorderRec(node->right, sortedArr);
    }
};

void treeSort(std::vector<int>& arr) {
    BinarySearchTree bst;

    // Вставляем все элементы в дерево
    for (int val : arr) {
        bst.insert(val);
    }

    // Получаем отсортированные элементы с помощью инфиксного обхода
    std::vector<int> sortedArr;
    bst.inorderTraversal(sortedArr);

    // Копируем отсортированные элементы обратно в исходный массив
    arr = sortedArr;
}

int main() {
    std::vector<int> arr =load_data();

    // Выполняем сортировку
    treeSort(arr);

    // Выводим отсортированный массив
    for (int val : arr) {
        std::cout << val << " ";
    }
    return 0;
}


