#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

vector<int> shake(vector<int> arr, int size) {
  srand(time(NULL));

  // O(n)
  for (int i = size - 1; i > 0; i--) {
    int j = rand() % (i + 1); // O(1)
    swap(arr[i], arr[j]);     // O(1)
  }

  return arr;
}

bool Testing(string filename) {
  ifstream file(filename);

  int size = 0;
  file >> size;

  vector<int> arr = {};
  int item = 0;
  for (int i = 0; i < size; i++) {
    file >> item;
    arr.push_back(item);
  }
  vector<int> shaked = shake(arr, size);

  for (int i = 0; i < size; i++) {
    cout << shaked[i] << " ";
  }

  sort(arr.begin(), arr.end());
  sort(shaked.begin(), shaked.end());

  return arr == shaked;
}

int main() {
  assert(Testing("test1.txt"));

  cout << "\n\n";

  assert(Testing("test2.txt"));

  cout << "\n\n";

  assert(Testing("test3.txt"));

  cout << "\n\n";

  assert(Testing("test4.txt"));
}