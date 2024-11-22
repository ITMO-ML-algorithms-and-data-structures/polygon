#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>
#include <chrono>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {} // O(1)
};

class BinaryTree {
public:
    BinaryTree() : root(nullptr) {} // O(1)

    void insert(int value) { // O(log n) в среднем, O(n) в худшем случае
        root = insertNode(root, value);
    }

    void inorderTraversal(vector<int>& sortedArray) { // O(n)
        inOrder(root, sortedArray);
    }

private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode* node, int value) { // O(log n) в среднем, O(n) в худшем случае
        if (!node) return new TreeNode(value); // O(1)

        if (value < node->value) {
            node->left = insertNode(node->left, value); // O(log n)
        }
        else {
            node->right = insertNode(node->right, value); // O(log n)
        }
        return node; // O(1)
    }

    void inOrder(TreeNode* node, vector<int>& sortedArray) { // O(n)
        if (node) {
            inOrder(node->left, sortedArray); // O(n)
            sortedArray.push_back(node->value); // O(1)
            inOrder(node->right, sortedArray); // O(n)
        }
    }
};

vector<int> readArrayFromFile(const string& fileName) { // O(n)
    ifstream inFile(fileName);
    assert(inFile.is_open() && "Не удалось открыть файл!");
    vector<int> array;
    int number;

    while (inFile >> number) { // O(n)
        array.push_back(number); // O(1)
    }
    inFile.close(); // O(1)
    return array; // O(1)
}

void treeSort(vector<int>& array) { // O(n log n) в среднем, O(n^2) в худшем
    BinaryTree tree;
    for (int value : array) { // O(n)
        tree.insert(value); // O(log n)
    }

    array.clear(); // O(n)
    tree.inorderTraversal(array); // O(n)
}
/*
    Сложности:
- Вставка узла: O(log n) в среднем, O(n) в худшем случае.
- Обход в порядке возрастания: O(n).
- Чтение из файла: O(n).
- Сортировка (TreeSort): O(n log n) в среднем, O(n?) в худшем случае.

Общая сложность: O(n log n) в среднем, O(n?) в худшем случае.

Память:
- Каждый узел дерева занимает O(1).
- Хранение массива вектором: O(n).
*/
void test() {
    {
        vector<int> arr1 = { 5, 3, 8, 4, 2 };
        treeSort(arr1);
        assert((arr1 == vector<int>{2, 3, 4, 5, 8}));
    }
    {
        vector<int> arr2 = { 1, 2, 3, 4 };
        treeSort(arr2);
        assert((arr2 == vector<int>{1, 2, 3, 4}));
    }
    {
        vector<int> arr3 = { 2, 1 };
        treeSort(arr3);
        assert((arr3 == vector<int>{1, 2}));
    }
    {
        vector<int> arr4 = {};
        treeSort(arr4);
        assert(arr4.empty());
    }
    {
        vector<int> arr5 = { 3, 3, 3 };
        treeSort(arr5);
        assert((arr5 == vector<int>{3, 3, 3}));
    }

}
int main() {
    // Тесты 
    test();
    cout << "All right!" << '\n';
    // Чтение массива из файла
    vector<int> array = readArrayFromFile("1000.txt");

    // Сортировка
    auto start = chrono::high_resolution_clock::now();
    treeSort(array);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << duration.count() / 1e6 << '\n';
    return 0;
}
