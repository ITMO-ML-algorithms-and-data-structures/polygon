#include <cassert>
#include <iostream>
#include <vector>

#include "algorithms.h"
using namespace std;

// Узел бинарного дерева
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Вставка элемента в бинарное дерево
TreeNode* insert(TreeNode* root, int value) {
    if (!root) {
        return new TreeNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Обход дерева и запись элементов в вектор
void inOrderTraversal(TreeNode* root, vector<int>& sortedArray) {
    if (root) {
        inOrderTraversal(root->left, sortedArray);
        sortedArray.push_back(root->value);
        inOrderTraversal(root->right, sortedArray);
    }
}

// Освобождение памяти дерева
void deleteTree(TreeNode* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

// Алгоритм TreeSort
void treeSort(vector<int>& arr) {
    TreeNode* root = nullptr;

    // Построение бинарного дерева поиска
    for (int value : arr) {
        root = insert(root, value);
    }

    // Очистка входного массива и запись отсортированных элементов
    arr.clear();
    inOrderTraversal(root, arr);

    deleteTree(root);
}

void treeSortTests() {
    // Test 1: Пустой массив
    vector<int> test1 = {};
    treeSort(test1);
    assert(isSorted(test1) && "Test 1 Failed!");

    // Test 2: Массив с одним элементом
    vector<int> test2 = {42};
    treeSort(test2);
    assert(isSorted(test2) && "Test 2 Failed!");

    // Test 3: Отсортированный массив
    vector<int> test3 = {1, 2, 3, 4, 5};
    treeSort(test3);
    assert(isSorted(test3) && "Test 3 Failed!");

    // Test 4: Массив, отсортированный в обратном порядке
    vector<int> test4 = {5, 4, 3, 2, 1};
    treeSort(test4);
    assert(isSorted(test4) && "Test 4 Failed!");

    // Test 5: Массив с дублирующимися числами
    vector<int> test5 = {3, 3, 3, 3, 3};
    treeSort(test5);
    assert(isSorted(test5) && "Test 5 Failed!");

    // Test 6: Массив с отрицательными числами
    vector<int> test6 = {-3, -1, -4, -1, -5, -9, -2, -6, -5, -3, -5};
    treeSort(test6);
    assert(isSorted(test6) && "Test 6 Failed!");

    // Лучший случай: Сбалансированный ввод
    vector<int> bestCase = {3, 1, 4, 2, 5};
    treeSort(bestCase);
    assert(isSorted(bestCase) && "Best case test failed!");

    // Средний случай: Случайные элементы
    vector<int> averageCase = {10, 7, 2, 1, 6, 3, 8, 5, 4, 9};
    treeSort(averageCase);
    assert(isSorted(averageCase) && "Average case test failed!");

    // Худший случай: Отсортированный массив (вырождение в линейный список)
    vector<int> worstCaseAsc = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    treeSort(worstCaseAsc);
    assert(isSorted(worstCaseAsc) && "Worst case ascending test failed!");

    // Худший случай: Обратный порядок (вырождение в линейный список)
    vector<int> worstCaseDesc = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    treeSort(worstCaseDesc);
    assert(isSorted(worstCaseDesc) && "Worst case descending test failed!");

    cout << "All tests for tree sort passed!" << endl;
}
