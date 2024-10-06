#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Функция для проверки, является ли число простым
bool isPrime(int num) 
{
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) 
    {
        if (num % i == 0) return false;
    }
    return true;
}

int main() 
{
    int n;

    cout << "Enter the number of array elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) 
    {
    cin >> arr[i];
    }

    unordered_map<int, int> countMap;

    // Подсчет количества вхождений каждого числа
    for (int num : arr) 
    {
        countMap[num]++;
    }

    int primeCount = 0;

    // Подсчет простых чисел, которые повторяются дважды
    for (const auto& pair : countMap) 
    {
        if (isPrime(pair.first) && pair.second == 2) 
        {
            primeCount++;
        }
    }

    cout << "The number of prime numbers, which repeat two times: " << primeCount << endl;

    return 0;
}
