#include <iostream>
#include <vector>


using namespace std;


int test_passed = 0;
int test_failed = 0;


int sum(vector<int> list){
    int sum = 0;
    for(int i = 0; i < list.size(); i++){
        sum += list[i];
    }
    return sum;
}//O(N)



void recurs(vector<int>& list, int& K, vector<vector<int>>& result, vector<int> new_list, int start, vector<int>& ind){
    if(new_list.size() == K){
        if(sum(new_list) == 0){
            result.push_back(ind);
            // cout << result[0][0] << ' ' << result[0][1] << "  ";
            
            // cout << new_list[0] << ' ' << new_list[1] << "  ";
            // cout << ind[0] << ' ' << ind[1];
            // cout << '\n';
        return;
        }
    }
    for(int i = start; i < list.size(); i++){
        ind.push_back(i);
        new_list.push_back(list[i]);
        recurs(list, K, result, new_list, i + 1, ind);
        new_list.pop_back();
        ind.pop_back();
    }    
} // O(N^K)



vector<vector<int>> find_list(vector<int> list, int K){ //{1, 2, 3, 4}
    vector<vector<int>> result = {};
    vector<int> new_list;
    vector<int> ind;
    if(K > list.size()){
        cout << '0';
        return {{}};
    }
    recurs(list, K, result, new_list, 0, ind);
    if(result.size() == 0){
        cout << "0";
        return {{}};
    }
    return result;
}//O(1)


void assertEqual(vector<vector<int>> finded_lists, vector<vector<int>> expected_list, const std::string& testName) {
    if (finded_lists == expected_list) {
        std::cout << "[PASSED]" << testName << "\n";
        test_passed++;
    } else {
        std::cout << "[NOT PASSED]" << testName << "\n";
        test_failed++;
    }
}



void report(){
    std::cout << "\nPassed tests: " << test_passed << "\n";
    std::cout << "\nFailed tests: " << test_failed << "\n";
} 



void print_vector(vector<vector<int>> list){ // чисто для удобства добавил
    int len = list.size();
    for(int i = 0; i < len; i++){
        for(int k = 0; k < 2; k++){
            cout << list[i][k];
        }
        cout << "\n";
                
    }
}


int main(){
    vector<vector<int>> list = find_list({1, -1, 2, -2}, 2);
    // cout << list[0][0];
    // print_vector(arr);
    assertEqual(find_list({1, -1, 2, -2}, 2), {{0, 1}, {2, 3}}, "Test 1");
    assertEqual(find_list({1, -1, 2, -3}, 3), {{0, 2, 3}}, "Test 2");
    assertEqual(find_list({1, 1, 1, 1}, 2), {{}}, "Test 3");
    assertEqual(find_list({2, 2, 2, 2}, 5), {{}}, "Test 4");
    report();

    return 0;
}

//arr=[1, -1, 2, -2], K=2
// [0, 1], [2, 3]

// [0, 2, 3]

// [0, 2], [0, 3], [1, 2], [1, 3]
//arr=[1, -1, 2, -3], K=3

//arr=[1,1,-1,-1], K=2


