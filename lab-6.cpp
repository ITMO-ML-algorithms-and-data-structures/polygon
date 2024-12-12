#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int>& height) { // 24 байт + size * 4 байт
    int n = height.size(); // 4 байта
    if (n == 0) return 0;

    // Массивы для хранения максимальных высот слева и справа
    vector<int> leftMax(n, 0), rightMax(n, 0);  // 24 байт + size * 4 байт 24 байт + size * 4 байт

    // Заполняем массив leftMax (максимальные высоты слева)
    // O(n)
    leftMax[0] = height[0];
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    // Заполняем массив rightMax (максимальные высоты справа)
    // O(n)
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    // Вычисляем количество воды, которое может быть задержано на каждой позиции
    // O(n)
    int totalWater = 0; // 4 байта
    for (int i = 0; i < n; i++) {
        // Вода, которую можно задержать, это минимальная высота между leftMax и rightMax минус высота на текущей позиции
        totalWater += max(0, min(leftMax[i], rightMax[i]) - height[i]);
    }

    return totalWater;
}

int main() {
    vector<int> input_sizes = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 100, 200, 300, 400, 500};
    cout << "Input Size, Execution Time (ms)" << endl;

    for (int size : input_sizes) {
        vector<int> height(size);
        for (int i = 0; i < size; ++i) {
            height[i] = rand() % 10; // Генерация случайных высот от 0 до 9
        }

        auto start = chrono::high_resolution_clock::now();
        trap(height);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> exec_time = end - start;
        cout << size << ", " << exec_time.count() << " ms" << endl;

    }

    return 0;
}
