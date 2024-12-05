#include <bits/stdc++.h>
using namespace std;

#include <iostream>



//rascheska sort
vector <int> comb(vector<int> data) {
    double factor = 1.2473309; // фактор уменьшения
    int step = data.size() - 1; // шаг сортировки
    // Последняя итерация цикла, когда step==1 эквивалентна одному проходу сортировки пузырьком
    while (step >= 1) {
        for (int i = 0; i + step < data.size(); i++) {
            if (data[i] > data[i + step]) {
                std::swap(data[i], data[i + step]);
            }
        }
        step /= factor;
    }
    return data;
}


// "tree" struct
struct Node 
{ 
	int key; 
	struct Node *left, *right; 
};

// A utility function to create a new BST Node 
struct Node *newNode(int item) 
{ 
	struct Node *temp = new Node; 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// Stores inorder traversal of the BST 
void storeSorted(Node *root, int arr[], int &i) 
{ 
	if (root != NULL) 
	{ 
		storeSorted(root->left, arr, i); 
		arr[i++] = root->key; 
		storeSorted(root->right, arr, i); 
	} 
} 

//Insert new node for recur
Node* insert(Node* node, int key) 
{ 
	/* If the tree is empty, return a new Node */
	if (node == NULL) return newNode(key); 

	/* Otherwise, recur down the tree */
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 

	/* return the (unchanged) Node pointer */
	return node; 
} 

// Tree Sort 
void treeSort(int arr[], int n) 
{ 
    //create struct
	struct Node *root = NULL; 

	root = insert(root, arr[0]); 
	for (int i=1; i<n; i++) 
		root = insert(root, arr[i]); 

	// Store inorder traversal of the BST 
	int i = 0; 
	storeSorted(root, arr, i); 
} 

//cocktailSort
void cocktailSort(int arr[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        //flag for swap
        swapped = false;

        // left -> right (bubble sort simplify)
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // If no swap occurred, the array is already sorted
        if (!swapped)
            break;
        
        //Update index end
        --end;

        // left->right (reversed bubble sort)
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // Update index start
        ++start;
    }
}

int main() {
    //rascheska Sort
    vector <int> unsort={1,2,4,2,8,9,1,3};
    vector <int> news=comb(unsort);
    
    //result
    for (int elem:news){
      cout << elem << " ";
    }
    cout << endl;
    
    //tree Sort
    int arr[] = {5, 4, 7, 2, 11}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	treeSort(arr, n); 
	
    //result
	for (int i=0; i<n; i++){
	    cout << arr[i] << " "; 
	}
	cout << endl;
    
    //cocktail Sort  
    cocktailSort(arr, n);

    for (int elem:arr){
        cout << elem << " ";
    }


    
  }

