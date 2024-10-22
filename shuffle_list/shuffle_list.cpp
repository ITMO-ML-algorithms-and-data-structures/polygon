#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

vector<int> shuffle(const vector<int>& obj) {
    int size = obj.size();
    vector<int> result = {};
    for (int i = 0; i<size; i++) {
        int item = obj[i];
        int rand_i = rand() % (i+1);
        result.insert(result.begin()+rand_i, item);
    }
    return result;
}

auto print_vector(const vector<int>& obj) {
    for (int a : obj) {
        cout << a << " ";
    }
    cout << endl;
}

//int main() {
//    srand(time(NULL));
//    vector<int> input = {1, 2, 3, 4, 5, 0};
//    print_vector(shuffle(input));
//    return 0;
//}