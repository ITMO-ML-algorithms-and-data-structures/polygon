#include <iostream>
#include <vector>
#include <algorithm>
#define all(x) (x).begin(), (x).end()
using namespace std;

// PANCAKE SORT
void flip(vector <int>& a, int l, int r){
	for (int i = 0; i <= (r - l) / 2; i++)
		swap(a[l + i], a[r - i]);
}

vector <int> pancakeSort(vector <int> a){
	for (int i = a.size() - 1; i >= 0; i--){
		
		int pos = i;
		for (int j = 0; j < i; j++){
			if (a[j] > a[pos]) pos = j;
		}

		if (pos == i) continue;

		if (pos != 0) flip(a, 0, pos);

		flip(a, 0, i);

	}
	return a;
}

// TREE SORT

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->value) root->left = insert(root->left, value);
  	else root->right = insert(root->right, value);
    
    return root;
}

void treeTour(TreeNode* root, vector<int>& a) {
    if (root != nullptr) {
        treeTour(root->left, a);
        a.push_back(root->value);
        treeTour(root->right, a);
    }
}


vector <int> treeSort(vector <int> a){
	TreeNode* root = nullptr;
    for (int now : a) 
      root = insert(root, now);

    vector<int> b;
    treeTour(root, b);

    return b;
}

// SORT 3

vector <int> countingSort(vector <int> a){
    int mn = *min_element(all(a));
    int mx = *max_element(all(a));

    vector<int> cnt(mx - mn + 1, 0);
    vector<int> b;

    for (int now : a) cnt[now - mn]++;

		for (int i = 0; i < cnt.size(); i++){
			for (int j = 0; j < cnt[i]; j++)
				b.push_back(i + mn);
		}

    return b;
}

// signed main(void){

// 	vector <int> a = {5, 4, 1, 2, 3, 3};
// 	for (auto c : countingSort(a)){
// 		cout << c << " ";
// 	}

// 	return 0;
// }