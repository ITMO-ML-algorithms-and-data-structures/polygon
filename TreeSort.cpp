#include <iostream>
#include <vector>
#include <string> 
#include <fstream>
#include <chrono>

struct TreeNode {
    int value; //4 байт
    TreeNode* left; //8 байт
    TreeNode* right; //8 байт

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
}; //всего в дереве n элементов, то есть оно занимает N*(4+8+8) = 20N байт

TreeNode* insert(TreeNode* root, int value) { //вставка за O(logN)
    if (root == nullptr) {
        return new TreeNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void inOrderTraversal(TreeNode* root, std::vector<int>& sortedArray) { //обход за O(n)
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left, sortedArray);
    sortedArray.push_back(root->value);
    inOrderTraversal(root->right, sortedArray);
}

void treeSort(std::vector<int>& arr) {
    TreeNode* root = nullptr;

    for (int value : arr) {
        root = insert(root, value);
    }

    arr.clear();
    inOrderTraversal(root, arr);
} //итого вставка каждого элемента (N штук) за O(logN), то есть получаем O(NlogN)

int main() {
    std::ifstream data_set("dataset.txt");

    std::string element; // 32 байта
    std::vector<int> array; // 24 байта

    while (getline(data_set, element, ';')) {
        array.push_back(stoi(element));
    } //+4*n байт в vector, где n - количество элементов в нем

    std::cout << "Original array: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    treeSort(array);

    auto stop = std::chrono::high_resolution_clock::now();

    std::cout << "Sorted array: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    auto duration = std::chrono::duration_cast <std::chrono::microseconds>(stop - start);
    data_set.close();

    std::cout << duration.count() << " microseconds";
}