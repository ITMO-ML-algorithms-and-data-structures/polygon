#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono; 

struct Node 
{ 
	int key; 
	struct Node *left, *right; 
}; 

// Создание нового узла
struct Node *newNode(int item) 
{ 
	struct Node *temp = new Node; 
	temp -> key = item; 
	temp -> left = temp -> right = NULL; 
	return temp; 
} 

// Сохранение отсортированных элементов в массив
void storeSorted(Node* root, vector<int>& arr, int& i) 
{
	if (root != NULL)
	{
		storeSorted(root -> left, arr, i);
		arr[i++] = root -> key;
		storeSorted(root -> right, arr, i);
	}
}

// Вставка элемента в дерево
Node* insert(Node* node, int key)
{
	if (node == NULL) return newNode(key);

	if (key < node -> key)
		node -> left = insert(node -> left, key);
	else if (key > node->key)
		node -> right = insert(node -> right, key);

	return node;
} 

void treeSort(vector<int>& arr)
{ 
	struct Node *root = NULL;

	// Построение дерева
	root = insert(root, arr[0]);
	for (int i = 1; i < arr.size(); i++)
		root = insert(root, arr[i]);

	// Сохранение отсортированных элементов
	int i = 0;
	storeSorted(root, arr, i);
}

int main() 
{ 
	ifstream inputFile("C:/Users/mosko/PycharmProjects/h/f.txt");

    if (!inputFile) {
        cerr << "Ошибка: не удалось открыть файл!" << endl;
		return 1;
    }
    
    vector<int> arr;
    int value;

	// Считывание данных из файла
    while (inputFile >> value) {
        arr.push_back(value);
    }
    
    inputFile.close();

	// Проверка, что вектор не пуст
    if (arr.empty()) {
        cerr << "Ошибка: файл пуст!" << endl;
        return 1;
    }

	int n = arr.size();

	auto start = high_resolution_clock::now();

	treeSort(arr); // Сортировка

	auto end = high_resolution_clock::now();

	duration<double> duration_sec = end - start;

	// Вывод времени выполнения
	cout << "\nВремя выполнения: " << duration_sec.count() << " секунд" << endl;

	return 0;
}