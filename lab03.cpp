//удалить дублирующие значения из входного массива size=4 arr=[1,2,3,1] -> arr=[1,2,3]
#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>

std::vector<long long int> delete_duplicates(const std::vector<long long int> &arr, long long int &size) {
    std::set<long long int> unique_elements;  // память: O(n) в худшем случае
    std::vector<long long int> ans; // память: O(n) в худшем случае
    for (auto i = 0; i<size; i++) { // сложность: O(n) проход по входному массиву
        unique_elements.insert(arr[i]); // сложность: O(logm) m - кол-во уникальных на момент вставки. Худший случай O(n)
    }
    for (auto value : unique_elements) { // сложность: O(m) где m - количество уникальных элементов
        ans.push_back(value); // сложность: O(1)
    }
    return ans;
}
// Память: O(n)
// Сложность: O(nlogn)

void test() {
    //1 test base
    std::vector<long long int> arr = {1,2,3,1};
    long long int size = 4;
    std::vector<long long int> ans = delete_duplicates(arr,size);
    if (ans == std::vector<long long int>{1,2,3}) {
        std::cout << "Test 1 passed!" << std::endl;
    } else {
        std::cout << "Test 1 failed!";
    }

    //2 test identical elements
    arr = {1,1,1,1,1,1};
    size = 6;
    ans = delete_duplicates(arr,size);
    if (ans == std::vector<long long int>{1}) {
        std::cout << "Test 2 passed!" << std::endl;
    } else {
        std::cout << "Test 2 failed!";
    }

    //3 test empty array
    arr = {};
    size = 0;
    ans = delete_duplicates(arr,size);
    if (ans == std::vector<long long int>{}) {
        std::cout << "Test 3 passed!" << std::endl;
    } else {
        std::cout << "Test 3 failed!";
    }

    //4 test several elements are repeated several times
    arr = {1,2,3,4,7,8,4,4,2,9,1,1,1,0};
    size = 14;
    ans = delete_duplicates(arr,size);
    if (ans == std::vector<long long int>{0,1,2,3,4,7,8,9}) {
        std::cout << "Test 4 passed!" << std::endl;
    } else {
        std::cout << "Test 4 failed!";
    }

    //5 test negative numbers
    arr = {1,-1,2,-2,3,-3,-6,6};
    size = 8;
    ans = delete_duplicates(arr,size);
    if (ans == std::vector<long long int>{-6,-3,-2,-1,1,2,3,6}) {
        std::cout << "Test 5 passed!" << std::endl;
    } else {
        std::cout << "Test 5 failed!";
    }
}


int main() {
    std::cout<<"Tests\n"; // O(1)
    std::vector<long long int> numbers; //O(1) инициализация вектора
    std::ifstream inputFile("set_datatest"); //O(1) инициализация файла
    std::string line; //O(1) инициализация строки
    if (!inputFile.is_open()) { //O(1)
        std::cerr << "Error!" << std::endl; //O(1)
        return 1; // O(1)
    }
    while (std::getline(inputFile, line)) { //O(m) m - количество строк в файле
        std::istringstream iss(line); //O(1)
        long long int number; //O(1)
        while (iss >> number) { //O(n) n - количество чисел в файле
            numbers.push_back(number); //O(1)
            std::cout<<number<<" "; //O(1)
        }
    }
    std::cout<<'\n'; //O(1)
    inputFile.close(); //O(1)
    long long int numbers_size=numbers.size(); //O(1)
    std::vector<long long int> answer2 = delete_duplicates(numbers,numbers_size); //O(nlogn)
    for (auto i = 0;i<answer2.size();i++) { //O(k) k - количество уникальных элементов
        std::cout<<answer2[i]<<" "; //O(1)
    }
    std::cout<<'\n'; //O(1)
    test(); //O(p*nlogn) p - количество тестов
    return 0; //O(1)
}
