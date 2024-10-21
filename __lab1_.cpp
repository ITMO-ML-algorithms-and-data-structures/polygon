#include <iostream>
#include <vector>
#include <unordered_map>

// ������� �������� �� ��������
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    // ���-�� ��������� � ���� ��������
    int n;
    std::cin >> n;

    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    // ������� ���-�� ���������
    std::unordered_map<int, int> countMap;

    for (int num : numbers) {
        if (isPrime(num)) {
            countMap[num]++;
        }
    }

    // ������� ��� ������� �����, ������� ����������� ������ ���-�� ���
    for (const auto& pair : countMap) {
        if (pair.second % 2 == 0) {
            std::cout << pair.first << " ";
        }
    }

    return 0;
}
