#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    
    int value, numbers_count;
    vector <int> numbers;
    set<vector <int>> output;

    cin >> value >> numbers_count;

    for (int i = 0; i < numbers_count; ++i) {

        int num;
        cin >> num;

        numbers.push_back(num);
    }

   
    for (int i = 0; i < numbers_count; ++i) {

        int curr_sum = 0;
        vector <int> array_for_push;

        for (int j = i; j < numbers_count; ++j) {

            int curr_elem = numbers[j];
            curr_sum += curr_elem;
            array_for_push.push_back(numbers[j]);

            if (curr_sum == value) {
                sort(array_for_push.begin(), array_for_push.end());
                output.insert(array_for_push);
            }
        }
    }

    for (vector <int> sub_array: output) {
        for (int elem : sub_array) {

            cout << elem << ' ';

        }
        cout << '\n';
    }

    return 0;
}
