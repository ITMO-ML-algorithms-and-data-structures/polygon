#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

vector<vector<int>> findZero(const vector<int>& arr) {
    vector<vector<int>> result;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    if (arr[i] + arr[j] + arr[k] + arr[l]  == 0) {
                        result.push_back({i, j, k, l, });
                        
                    }
                }
            }
        }
    }
    // 6*4 = 24 байта так как 6 int(i,j,k,m,l,n)
    return result;
}

void Resprint(const vector<vector<int>>& result) {
    if (result.empty()) {
        cout << "zero answers";
        return;
    }
    for (const auto& subarray : result) {
        cout << '[';
        for (int index : subarray) {
            cout << index << " ";
        }
        cout << "]\n";
    }
    // уверен, что для переменной subarray тоже потребуется память, но она будет очень мала, так как она ссылается на result
}

int main() {
    vector<int> arr;
    ifstream file("ppp.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
    }
    file.close();
    // массив arr будет занимать N*4 байта
    //для result  K*4 байта, в нашем случае 4*5=20 байт
    Resprint(findZero(arr));
    return 0;
}