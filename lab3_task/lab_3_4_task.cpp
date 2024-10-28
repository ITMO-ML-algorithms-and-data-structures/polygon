#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

void minMaxScaler(const std::vector<double>& arr, std::vector<double>& scaledArr) {
    double minVal = std::numeric_limits<double>::max();
    double maxVal = std::numeric_limits<double>::lowest();

    // ������ ������: ������� min � max
    for (double num : arr) {
        if (num < minVal) minVal = num;
        if (num > maxVal) maxVal = num;
    }

    // ������ ������: ������������ ��������
    for (double num : arr) {
        double scaledValue = (num - minVal) / (maxVal - minVal);
        scaledArr.push_back(scaledValue);
    }
}

int main() {
    // ������ ������� ������
    int size = 4;
    std::vector<double> arr = { 1, 100, 1000001, 2 };

    std::vector<double> scaledArr;
    minMaxScaler(arr, scaledArr);

    // ����� ����������
    std::cout << std::fixed << std::setprecision(1) << "[";
    for (size_t i = 0; i < scaledArr.size(); ++i) {
        std::cout << std::scientific << scaledArr[i];
        if (i != scaledArr.size() - 1) std::cout << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
