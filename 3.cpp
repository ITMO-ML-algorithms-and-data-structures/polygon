#include <iostream>
#include <vector>

void fillGaps(std::vector<int>& arr) {
    int n = arr.size();  // O(1)
    
    for (int i = 0; i < n; ++i) {  
        if (arr[i] == -1) {  // O(1)
            int left = i - 1;  // O(1)
            int right = i + 1;  // O(1)
            
            // Ищем ближайшее значение слева
            while (left >= 0 && arr[left] == -1) {  // O(n) в худшем случае
                left--;  // O(1)
            }
            
            // Ищем ближайшее значение справа
            while (right < n && arr[right] == -1) {  // O(n) в худшем случае
                right++;  // O(1)
            }
            
            // Если оба соседа найдены, вычисляем среднее
            if (left >= 0 && right < n) {  // O(1)
                arr[i] = (arr[left] + arr[right]) / 2;  // O(1)
            }
        }
    }
}
// таким образом О(n^2)
void testFillGaps() {
    // Тест 1
    std::vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(-1);
    arr1.push_back(10);
    arr1.push_back(4);
    fillGaps(arr1);
    std::cout << "Test 1: ";
    for (int num : arr1) {
        std::cout << num << " ";
    }
    std::cout << "\n"; // Ожидаемый результат: 1 5 10 4

    // Тест 2: Массив без пропусков
    std::vector<int> arr2;
    arr2.push_back(5);
    arr2.push_back(10);
    arr2.push_back(15);
    arr2.push_back(20);
    fillGaps(arr2);
    std::cout << "Test 2: ";
    for (int num : arr2) {
        std::cout << num << " ";
    }
    std::cout << "\n"; // Ожидаемый результат: 5 10 15 20 

    // Тест 3: Массив с пропуском в начале
    std::vector<int> arr3;
    arr3.push_back(-1);
    arr3.push_back(2);
    arr3.push_back(3);
    fillGaps(arr3);
    std::cout << "Test 3: ";
    for (int num : arr3) {
        std::cout << num << " ";
    }
    std::cout << "\n"; // Ожидаемый результат: 2 2 3

    // Тест 4: Массив с пропуском в конце
    std::vector<int> arr4;
    arr4.push_back(1);
    arr4.push_back(2);
    arr4.push_back(-1);
    fillGaps(arr4);
    std::cout << "Test 4: ";
    for (int num : arr4) {
        std::cout << num << " ";
    }
    std::cout << "\n"; // Ожидаемый результат: 1 2 2

    // Тест 5: Массив с несколькими пропусками
    std::vector<int> arr5;
    arr5.push_back(1);
    arr5.push_back(-1);
    arr5.push_back(-1);
    arr5.push_back(4);
    fillGaps(arr5);
    std::cout << "Test 5: ";
    for (int num : arr5) {
        std::cout << num << " ";
    }
    std::cout << "\n"; // Ожидаемый результат: 1 2 3 4

    // Тест 6: Пустой массив
    std::vector<int> arr6;
    fillGaps(arr6);
    std::cout << "Test 6: ";
    for (int num : arr6) {
        std::cout << num << " ";
    }
    std::cout << "\n"; // Ожидаемый результат: (пустой массив)

    // Тест 7: Массив с одним элементом
    std::vector<int> arr7;
    arr7.push_back(100);
    fillGaps(arr7);
    std::cout << "Test 7: ";
    for (int num : arr7) {
        std::cout << num << " ";
    }
    std::cout << "\n"; // Ожидаемый результат: 100
}

int main() {
    
    testFillGaps();
    return 0;
}
