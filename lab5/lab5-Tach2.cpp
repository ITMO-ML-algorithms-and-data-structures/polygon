#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Insert value into the binary tree
TreeNode* insert(TreeNode* root, int value) {
    if (!root) return new TreeNode(value);
    if (value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

// In-order traversal to get sorted values
void inOrderTraversal(TreeNode* root, vector<int>& sorted) {
    if (root) {
        inOrderTraversal(root->left, sorted);
        sorted.push_back(root->value);
        inOrderTraversal(root->right, sorted);
    }
}

// Perform Tree Sort
void treeSort(vector<int>& arr) {
    TreeNode* root = nullptr;
    for (int val : arr) root = insert(root, val);

    arr.clear();
    inOrderTraversal(root, arr);
}

int main() {
    string filePath = "D:\\program\\C++program\\lab5algo\\polygon\\lab5\\togomori.txt";
    vector<int> arr;

    // Reading input file
    ifstream inputFile(filePath);
    if (!inputFile) {
        cerr << "Error: Unable to open file " << filePath << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
    }
    inputFile.close();

    // Applying Tree Sort
    treeSort(arr);

    // Displaying results in the terminal
    cout << "Tree Sort Result: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
