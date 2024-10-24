#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <cassert>


std::vector<int> shuffle_array(std::string path) {
    std::ifstream file(path); // O(1)
    std::vector<int> array; // O(1)

    // читаем файл
    int number; // O(1)
    while (file >> number) { // O(n)
        array.push_back(number); // O(1)
    }
    file.close();

    // инициализация генератора
    std::random_device rd; // O(1)
    std::mt19937 gen(rd());  // O(1) - генератором псевдослучайных чисел по методу Mersenne twister (числа до 32 битов)

    // идем с конца, чтобы уже перемещенное элемент повторно не трогать
    for (int i = array.size() - 1; i > 0; --i) { // O(N) - цикл по массиву
        // Генерация случайного индекса от 0 до i - 1
        std::uniform_int_distribution<> dist(0, i - 1); // O(1)
        // меняем местами наш элмент и элмент под случайным идексом
        std::swap(array[i], array[dist(gen)]); // O(1)
    }

    // сложность алгорится O(n)
    return array;
}


using namespace std;
void TestLabelEnc() {
    std::vector<int> test_1 {1, 2, 3, 4, 5, 6};
    std::vector<int> test_2 {52};
    std::vector<int> test_3_1{2, 1};
    std::vector<int> test_3_2 {2, 1};
    std::vector<int> test_4 {3, 3, 3, 3, 3, 3};
    std::vector<int> test_5 {5, 4, 3, 2, 1};
    std::vector<int> test_6 {1, 2, 2, 3, 3, 3};
    std::vector<int> test_7 {6,88,66,29,41,30,98,59,36,0,15,3,94,23,94,1,23,85,40,86,55,33,4,35,93,2,27,17,44,71,92,45,22,55,49,82,33,18,95,81,1,53,43,47,32,71,17,94,65,79,33,18,18,37,84,37,73,62,71,46,66,66,81,83,6,8,16,59,3,84,92,85,72,97,25,99,64,33,19,24,92,67,3,75,5,67,17,18,42,2,55,86,29,12,2,10,17,0,12,5,84,79,33,66,6,57,100,27,25,28,57,66,100,100,52,6,22,56,35,54,61,99,65,93,34,17,7,81,94,28,3,54,5,99,31,73,88,41,42,46,83,34,66,6,3,82,55,96,6,81,44,11,36,73,42,48,14,19,5,72,67,6,11,2,19,40,60,81,27,45,28,15,30,63,13,54,100,6,94,95,53,43,84,73,86,6,16,56,14,40,62,83,24,87,4,13,35,99,24,45,25,33,26,35,19,65,23,30,22,67,41,53,16,21,13,45,12,97,12,11,93,98,23,11,7,78,39,13,43,15,82,62,94,36,54,5,2,57,58,60,63,73,45,81,11,100,56,5,11,63,92,37,18,41,18,11,37,3,58,44,94,11,39,96,59,62,91,10,11,66,6,33,68,1,62,37,75,18,34,15,56,73,80,50,80,82,35,58,40,6,37,46,30,50,68,38,96,95,35,68,71,84,7,53,50,13,43,97,86,84,94,52,49,79,10,2,60,72,75,14,64,26,58,41,59,2,85,38,8,42,79,25,8,51,52,61,16,94,93,75,26,3,1,11,71,35,25,34,10,78,73,18,0,95,68,71,93,32,28,45,16,73,42,86,3,98,39,45,53,87,65,4,67,11,14,45,9,62,88,28,18,9,37,79,17,28,17,14,62,1,84,31,61,63,30,99,81,0,4,62,100,84,29,32,3,20,32,26,77,38,58,81,48,38,12,29,14,44,85,19,62,36,45,89,73,62,12,40,77,81,39,72,93,62,17,31,45,1,12,0,6,62,10,89,82,39,19,64,29,1,59,35,36,88,29,42,95,13,51,76,72,69,77,53,79,1,21,22,9,79,37,77,10,98,22,9,26,22,36,61,57,50,78,12,21,42,81,44,71,3,15,82,30,34,80,6,13,40,15,32,16,58,28,34,81,40,4,22,44,53,56,76,20,11,79,29,4,72,16,13,76,13,82,62,56,5,74,59,94,59,95,10,32,74,92,60,79,45,8,50,0,41,83,67,41,37,82,53,76,45,88,98,55,54,14,26,100,25,55,68,98,36,35,31,6,95,39,96,6,52,2,36,87,67,83,3,2,31,75,63,4,34,9,32,18,72,38,55,89,76,28,88,89,89,74,56,66,67,60,75,42,52,69,47,12,45,17,27,44,75,45,25,65,59,91,36,58,73,2,63,8,63,100,76,60,75,46,65,49,5,64,12,12,48,86,57,20,79,86,4,63,74,91,86,25,84,50,5,51,98,97,62,46,42,13,58,17,93,94,83,10,63,42,68,85,47,15,76,3,50,41,14,69,67,14,71,4,63,12,96,71,39,24,25,51,33,67,12,73,99,46,82,41,33,73,82,99,75,22,1,9,37,56,27,18,15,35,11,62,95,45,51,72,25,95,69,31,69,49,35,34,22,41,65,34,2,23,7,96,10,24,11,96,34,71,35,41,24,54,97,48,53,54,23,28,17,40,22,45,80,28,25,19,21,97,62,14,96,0,53,82,57,48,32,28,41,23,16,91,53,42,27,28,82,29,28,100,72,54,21,34,73,71,1,64,98,29,28,1,25,82,60,16,26,66,77,72,56,67,66,8,62,54,63,16,62,67,32,96,83,74,69,31,61,88,49,13,3,23,83,27,25,56,92,56,41,89,41,35,46,55,6,22,54,2,14,54,63,11,42,25,49,37,54,51,30,83,59,40,93,10,40,36,81,64,67,1,58,40,1,20,67,92,76,2,65,18,99,82,32,54,25,89,76,19,19,84,29,29,51,34,62,91,15,8,70,48,86,11,16,25,41,36,78,9,66,100,41,45,94,44,39,77,84,97,78,21,34,61,51,26,89,13,78,28,36,100,11,24,93,78,71,84,100,28,66,38,35,42,86,95,13,3,55,48,7,36,57,39,19,37,45,58,17,64,40,75,5,64,5,15,94,52,50,2,96,88,11,96,82,86,44,52,58,99,30,82,17,22,44,23,89,32,37,99,85,32,25,39,2,42,55,89,20,74,78,7,4,2,43,1,34,67,60,31,88,58,0,48,64,82,71,61,30,87,40,56,2,41,43,91,66,96,42,98,100,41,13,57,33,58,1,2,95,85,40,84,91,51,15,29,55,32,34,77,50,14,30,6,40,94,49,70,79,8,16,0,51,66,70,51,100,86,100,11,10,34,17,93,28,41,48,100,62,44,77,26,86,1,54,20,84,2,80,40,96,21,42,6,98,23,63,6,95,39,24,47,51,89,24,83,86,76,2,57,14,52,67,87,46,82,40,22,32,64,41,23,61,23,66,77,85,23,50,42,87,16,15,12,52,71,47,57,13,34,48,6,25,35,48,21,21,51,23,26,79,94,61,62,76,40,4,82,67,54,29,89,93,44,29,43,85,48,79,18,91,31,27,16,1,56,72,93,7,33,14,80,50,79,42,54,39,94,57,32,39,33,48,16,16,43,89,41,22,92,27,78,22,73,42,30,4,18,54,83,41,83,57,44,65,55,62,36,9,11,98,0,23,15,15,10,52,84,32,94,81,74,54,56,33,96,18,11,32,45,57,97,75,97,54,37,13,42,43,4,41,30,92,75,68,45,37,0,2,73,60,26,67,80,32,24,45,91,73,17,57,69,87,0,94,26,14,78,18,63,77,61,13,75,66,9,6,97,35,35,64,36,68,69,37,85,17,32,33,55,28,9,87,53,33,51,8,5,51,30,63,83,68,59,88,85,0,70,25,66,84,51,19,67,99,56,33,45,23,3,87,82,2,81,20,30,55,61,87,65,13,63,52,0,45,27,87,42,84,45,35,15,92,52,92,63,2,38,95,67,92,75,41,21,68,21,54,3,58,24,70,52,75,14,16,82,85,73,67,60,89,46,11,16,17,65,48,9,92,87,25,24,76,32,92,62,11,80,27,61,45,34,15,48,35,11,54,50,85,27,37,31,73,84,59,57,60,80,98,96,46,35,83,67,89,95,50,6,76,46,55,79,50,74,1,41,22,21,24,79,19,23,6,92,79,3,39,98,42,4,24,38,81,37,13,74,63,12,33,35,69,35,96,84,73,51,18,56,51,92,31,60,83,9,5,68,44,82,25,63,79,48,61,95,12,86,54,62,3,97,58,3,64,46,11,52,86,82,45,93,4,42,43,16,70,8,89,41,48,46,58,81,13,43,98,18,42,27,88,91,54,43,18,96,47,27,40,62,95,73,68,0,32,40,22,23,34,94,50,76,32,22,2,88,89,6,31,14,8,35,47,41,88,17,99,41,62,56,65,47,58,75,51,54,50,74,2,27,93,59,10,8,35,86,84,27,45,37,98,67,74,27,99,58,19,68,82,11,65,74,39,28,99,44,40,1,89,86,92,57,55,72,50,81,34,100,58,59,2,12,80,37,42,39,73,41,22,10,54,65,44,87,64,22,11,3,12,23,71,74,64,7,24,13,57,44,28,83,93,34,99,96,65,63,21,27,3,87,58,12,21,1,40,87,50,66,58,35,3,65,57,64,7,42,62,91,56,3,25,82,93,11,74,53,21,42,55,74,24,10,35,39,17,22,97,24,25,36,0,32,39,96,69,7,77,41,87,47,88,25,95,9,47,71,99,48,31,61,43,24,82,86,34,95,53,44,33,97,65,26,56,41,31,57,23,14,77,60,41,9,17,77,8,11,48,37,10,41,12,26,24,46,65,59,96,46,80,67,6,64,59,67,99,42,85,7,55,13,14,96,8,56,17,80,39,85,6,15,23,66,70,31,98,10,95,13,23,68,18,30,68,24,30,71,8,68,80,94,93,14,35,59,97,59,92,7,47,3,10,33,8,40,71,44,42,46,45,17,47,71,6,17,76,5,11,9,0,9,71,88,91,84,57,47,36,28,52,75,63,15,60,26,56,79,19,7,89,84,45,58,34,94,51,73,49,44,15,94,51,23,95,74,47,75,34,79,64,20,23,82,64,1,50,86,37,100,65,15,56,5,47,80,65,42,38,16,95,36,22,13,74,33,32,91,94,17,73,24,69,0,73,20,76,3,86,17,19,66,63,87,77,34,40,34,1,49,7,17,78,66,78,0,89,76,58,10,69,34,37,61,70,43,85,64,1,6,38,29,55,30,41,62,78,16,96,75,20,46,23,27,56,51,25,78,56,68,46,80,45,51,53,75,58,51,64,21,36,83,3,42,44,78,2,11,27,50,60,31,67,28,65,32,32,14,70,100,39,98,27,4,73,13,21,50,6,56,30,97,42,9,31,75,61,18,61,2,47,55,94,32,54,79,82,94,19,3,55,6,94,31,22,45,24,89,80,8,11,74,46,35,86,38,55,27,23,9,48,14,87,51,27,68,99,33,39,49,64,22,88,63,45,39,46,89,24,5,76,17,49,60,2,15,22,31,31,58,63,19,63,16,95,16,64,73,36,86,44,81,65,49,49,20,100,6,12,36,61,92,17,41,91,9,81,50,88,64,0,40,48,47,76,20,7,8,26,85,63,39,92,2,16,82,5,0,18,31,49,62,36,20,30,37,33,67,65,78,53,86,50,63,23,61,40,75,86,41,84,17,29,17,63,70,14,95,52,28,27,32,64,2,26,7,2,50,55,20,58,21,23,57,37,46,4,72,46,78,68,89,98,14,71,95,26,22,19,61,54,65,44,42,49,16,62,27,33,25,66,87,21,92,46,24,4,8,0,85,56,47,19,86,99,14,19,95,84,5,25,38,24,70,80,85,96,94,53,11,96,77,76,100,8,10,55,14,82,16,57,31,94,21,80,34,2,70,12,44,55,92,86,73,36,74,8,49,67,85,46,52,79,86,20,97,97,28,91,53,79,3,82,63,43,61,3,38,27,4,74,39,51,45,32,60,62,45,95,67,6,63,6,57,82,14,75,68,17,9,32,68,61,55,0,5,56,42,35,37,46,92,50,27,40,5,45,100,53,3,17,15,40,3,20,64,70,55,23,27,27,76,5,64,12,2,37,3,6,4,56,36,35,91,21,88,41,96,88,54,23,13,30,65,59,41,84,82,0,29,94,84,63,11,72,12,52,40,72,4,42,3,19,52,45,29,82,96,95,53,32,69,61,73,76,72,60,17,54,73,56,51,59,75,75,50,41,58,54,53,2,89,32,10,24,20,67,1,46,55,20,34,32,1,0,47,9,15,21,15,40,96,77,24,5,100,48,0,48,55,4,86,88,69,65,71,38,85,28,30,55,43,10,43,17,19,53,53,86,82,71,3,66,46,63,36,7,50,36,89,38,93,50,57,50,89,60,53,62,17,23,28,91,18,73,13,31,24,92,91,9,7,14,96,6,53,100,97,40,17,78,77,98,28,2,91,8,17,99,53,7,54,65,29,29,41,69,16,33,43,18,47,84,33,25,49,1,4,27,67,8,31,53,79,93,98,38,76,36,55,29,37,51,22,57,83,59,69,59,43,100,74,44,56,15,21,30,25,89,5,82,59,42,3,0,40,43,12,49,57,20,68,54,39,28,67,1,70,91,71,51,42,33,100,66,35,3,10,43,22,20,42,36,35,23,67,35,96,68,29,60,86,18,60,13,46,54,87,37,17,16,91,50,97,62,55,10,75,49,10,60,53,20,4,78,3,4,52,62,21,21,69,55,72,17,0,42,81,84,75,67,28,13,25,97,58,1,10,6,2,45,19,15,28,35,6,99,61,58,71,45,18,39,22,32,51,46,4,79,0,68,53,6,35,34,3,17,19,85,77,60,48,28,83,15,68,28,57,17,88,87,83,31,77,100,52,79,2,1,46,83,10,60,47,41,76,29,1,42,97,73,57,47,68,25,12,11,1,11,50,8,24,28,30,15,56,56,52,72,17,86,46,14,36,91,60,5,8,26,9,38,68,99,89,40,51,23,76,58,89,97,22,98,20,15,61,38,72,0,95,26,26,86,48,29,10,5,12,17,24,96,37,74,48,26,63,32,89,42,62,15,42,32,5,54,31,45,4,10,61,2,6,42,2,83,84,65,64,18,25,20,35,53,26,62,95,99,49,8,72,27,10,98,20,93,42,56,14,80,49,76,20,60,91,4,14,39,21,21,63,67,74,17,74,76,36,26,68,70,86,94,18,79,72,44,22,60,100,75,36,59,24,34,25,83,3,9,31,4,92,76,15,38,51,79,30,37,3,83,27,33,79,70,7,48,45,66,23,31,20,54,25,58,54,46,18,61,66,75,79,7,9,91,23,29,43,30,49,33,79,44,97,22,80,32,10,49,60,44,8,83,60,100,76,36,93,75,95,85,76,37,42,15,15,43,42,87,33,15,80,30,10,29,28,89,33,77,59,65,95,74,2,38,53,75,73,40,37,78,87,59,78,74,42,10,61,28,12,62,60,33,92,72,73,27,74,63,97,13,3,49,41,14,96,80,17,13,56,35,52,58,1,71,85,61,53,67,27,87,82,83,89,41,39,57,91,36,95,38,11,19,65,25,88,28,65,29,86,10,5,89,41,22,13,60,14,96,15,52,3,40,71,65,25,12,4,82,17,41,42,96,62,51,52,11,44,0,69,33,48,72,55,42,59,48,75,71,77,72,2,88,9,70,97,3,71,0,9,0,68,61,5,30,1,52,23,67,39,34,48,63,81,47,52,42,69,36,82,15,57,52,71,4,74,5,77,14,38,27,50,88,60,62,7,86,73,79,0,39,5,8,81,9,12,40,58,5,66,16,38,59,95,58,1,4,81,5,48,87,36,29,70,5,21,65,0,76,63,9,95,60,7,60,44,57,58,15,42,76,19,54,39,96,51,45,46,22,19,42,34,35,92,53,70,4,77,77,94,12,67,49,30,71,15,49,15,92,30,40,68,18,44,43,52,11,59,80,92,70,45,77,65,0,41,85,39,41,70,29,21,1,6,8,48,30,59,44,66,60,39,52,59,100,25,43,11,53,58,28,60,66,2,8,29,23,11,77,65,67,33,66,10,74,45,26,56,81,81,60,73,64,12,69,57,53,45,95,44,91,87,41,12,38,55,78,54,56,70,85,84,33,59,11,0,63,15,51,79,46,69,20,27,13,32,49,41,62,53,6,3,54,16,9,23,41,36,69,83,30,25,54,5,42,71,85,6,50,25,63,51,32,60,34,84,78,35,24,44,63,63,26,16,17,8,46,68,6,92,29,0,44,95,71,93,44,62,0,92,40,47,19,74,47,38,63,25,17,94,40,27,31,31,49,24,24,24,66,47,5,39,33,4,6,22,21,39,78,65,5,12,34,4,44,100,36,66,25,34,55,36,61,38,22,42,98,50,49,59,48,96,80,43,52,4,39,35,25,83,56,91,35,46,36,14,98,39,2,100,93,30,23,52,96,54,45,3,22,19,6,5,94,21,80,31,48,65,48,51,46,48,9,31,93,5,64,21,41,22,12,100,62,50,57,60,7,23,92,98,48,22,24,30,86,15,85,0,70,71,20,10,43,11,16,26,6,91,53,2,25,13,80,89,18,79,69,13,97,37,80,51,88,15,14,60,16,66,77,38,14,6,31,78,6,94,65,7,21,26,76,87,7,99,65,55,57,25,38,23,16,11,9,25,33,61,41,45,59,4,59,96,33,76,82,96,51,39,7,99,10,97,25,19,75,69,19,81,73,39,11,34,2,6,34,21,42,8,66,92,0,5,51,91,20,76,27,88,72,28,8,97,55,8,39,92,79,42,77,32,73,81,81,16,45,36,53,15,65,36,74,36,80,29,32,8,57,58,63,28,41,25,71,93,76,37,36,5,69,82,29,53,34,67,43,92,66,35,39,75,7,82,12,29,89,82,5,53,83,54,51,76,91,62,81,64,35,41,44,56,57,82,65,49,98,85,1,26,28,4,33,17,8,52,49,95,44,8,79,31,55,63,63,89,52,4,88,77,56,52,61,39,29,99,63,87,41,91,1,76,45,66,82,46,69,86,52,97,38,89,100,37,87,68,59,66,5,6,38,25,71,12,55,29,55,54,5,83,17,87,94,39,28,80,16,21,11,41,76,14,38,81,24,5,71,65,72,92,12,71,52,64,64,81,37,58,34,6,67,83,52,98,37,12,20,93,28,24,1,71,69,20,49,55,24,60,45,60,4,59,22,3,9,78,14,70,100,79,21,75,63,19,43,45,8,40,71,48,27,41,67,29,88,33,95,46,23,10,91,79,80,21,42,49,63,13,55,19,78,91,69,10,55,59,98,54,77,37,30,86,46,87,0,69,15,22,95,19,9,41,56,69,30,24,92,79,36,11,18,12,54,81,73,57,5,76,43,9,13,96,56,89,52,28,35,27,83,5,42,77,81,69,27,8,30,0,33,39,16,58,28,22,7,47,32,65,31,98,25,91,50,41,29,23,38,100,69,74,19,83,79,76,2,27,89,40,20,89,63,13,53,82,47,30,45,54,97,60,11,70,19,67,28,74,0,91,76,35,59,56,51,29,31,77,9,92,7,1,67,60,87,66,15,100,62,52,65,100,71,78,55,98,48,65,68,12,37,91,70,48,84,23,68,3,20,5,44,38,91,6,75,96,49,68,21,52,12,11,32,44,34,73,53,0,68,27,87,95,50,27,71,99,99,57,0,47,25,7,70,48,32,89,50,60,20,0,14,32,46,85,28,83,71,67,29,31,85,92,83,45,6,92,99,45,5,42,41,73,58,37,34,34,5,14,4,20,96,70,62,30,41,12,83,70,29,6,18,99,30,9,32,48,88,19,59,28,38,24,1,67,83,58,32,14,29,40,100,21,34,18,56,74,19,19,47,71,30,100,14,62,48,71,11,83,98,1,29,4,67,74,49,79,7,71,44,82,15,14,60,31,33,46,92,10,39,72,98,91,12,75,61,6,86,100,26,80,100,100,95,2,26,2,4,34,70,62,14,92,76,7,15,85,12,65,29,40,92,91,19,81,81,22,38,56,58,99,76,99,9,22,62,0,92,75,71,31,74,73,40,46,21,27,78,74,26,55,95,64,27,89,38,6,5,52,74,4,84,99,6,2,34,78,74,31,15,36,99,84,72,14,37,5,13,51,54,68,55,60,63,65,54,41,47,61,44,36,36,71,85,87,93,15,18,77,79,19,15,85,89,71,77,63,25,6,33,3,44,8,82,15,40,89,53,92,47,29,78,45,44,26,15,68,10,1,44,21,30,61,37,28,78,45,65,35,23,79,99,2,74,92,84,35,51,63,63,75,72,32,30,22,96,67,17,48,86,83,97,44,72,46,13,56,17,10,13,42,47,67,49,40,97,91,41,34,58,20,32,61,100,98,73,24,14,75,73,92,99,76,15,3,93,26,40,18,15,35,61,65,20,4,99,68,75,65,35,45,75,37,4,71,13,32,57,85,67,71,81,93,2,49,33,85,11,62,91,9,82,65,4,37,0,79,0,13,12,29,5,42,72,75,61,48,22,85,34,71,12,96,10,66,65,57,80,33,31,16,36,39,54,35,63,66,92,41,32,64,0,10,86,17,31,78,60,92,1,70,9,52,82,18,76,80,33,24,21,8,12,11,51,81,38,13,89,89,4,7,15,46,28,24,44,86,3,57,53,51,44,75,92,56,82,10,78,14,46,37,83,69,76,47,24,50,48,25,16,44,92,98,62,79,96,18,8,77,51,79,94,78,10,67,58,0,75,13,7,39,86,28,89,64,86,82,62,73,49,84,11,61,86,63,14,15,87,61,39,3,0,100,25,69,33,40,47,99,23,12,19,3,78,98,99,8,49,22,74,71,39,48,35,60,60,75,36,87,63,3,73,15,18,65,76,20,24,60,42,53,74,25,20,71,23,30,18,98,46,7,45,50,8,89,42,4,70,68,77,97,54,94,98,38,39,50,40,3,19,10,21,28,89,29,98,18,53,75,80,82,25,38,88,75,100,23,49,14,34,18,72,54,63,72,43,91,57,55,91,68,31,91,91,31,95,75,62,62,92,41,35,35,27,47,57,75,58,32,89,55,39,33,49,98,53,94,52,44,77,96,60,74,41,32,7,64,57,74,60,100,62,60,61,65,40,78,71,0,87,24,25,13,78,85,99,19,45,45,16,33,36,71,46,37,56,81,29,11,6,63,28,8,81,69,93,27,64,33,56,37,55,8,46,56,36,42,99,16,53,77,83,69,74,62,9,36,48,36,85,87,72,88,70,67,74,33,61,34,60,82,30,100,81,3,45,32,79,43,91,81,78,52,100,3,20,44,50,73,7,47,3,23,85,34,46,2,60,64,74,33,18,88,40,10,79,38,8,89,89,42,82,27,56,24,59,4,44,43,12,46,88,33,27,68,2,47,33,63,88,36,46,57,37,99,67,68,2,32,100,60,11,15,83,0,7,25,77,10,86,40,38,60,1,77,60,46,98,6,73,13,89,86,39,27,28,26,59,20,93,35,49,9,81,94,70,53,26,69,75,7,74,4,30,14,51,24,14,39,33,45,82,89,68,0,86,89,87,20,25,62,42,4,99,17,21,34,17,77,1,88,48,5,31,31,20,86,85,94,94,51,19,81,98,62,45,28,38,97,79,81,49,57,49,72,70,75,43,97,30,6,23,78,58,25,82,8,41,87,74,45,42,57,96,58,3,28,13,87,22,9,64,80,36,3,76,70,83,76,29,36,18,96,64,6,26,42,31,89,89,25,84,50,36,15,80,63,25,87,54,26,43,51,45,52,80,16,7,58,41,60,43,95,22,82,86,41,72,51,68,89,97,67,11,12,44,38,1,62,82,33,61,38,13,27,27,13,23,93,46,83,79,81,30,46,88,100,9,11,58,56,14,61,75,3,13,86,11,36,11,55,20,17,53,51,20,32,93,84,21,84,16,0,67,85,10,86,25,11,84,0,84,18,93,96,48,2,14,86,63,68,62,58,23,74,1,23,58,75,91,63,40,3,20,45,67,47,30,69,26,99,39,17,61,82,98,26,5,0,0,42,20,56,92,52,1,42,17,52,85,14,61,42,91,1,8,35,10,84,17,91,42,36,55,44,13,42,3,33,25,7,24,4,34,37,66,94,43,58,63,88,3,64,14,26,22,10,93,1,81,17,35,61,68,49,42,76,75,20,0,28,33,26,9,66,100,35,18,75,50,29,86,35,66,4,67,66,32,77,57,73,73,86,8,58,21,12,39,41,96,83,52,82,97,0,52,53,19,35,67,15,66,76,39,13,80,38,98,1,50,23,36,40,64,63,71,3,19,83,23,41,67,94,69,70,44,83,75,4,8,33,34,84,22,11,17,100,28,22,38,39,65,93,17,16,16,73,68,71,95,91,24,11,56,24,9,65,29,38,4,92,7,94,34,30,65,71,63,1,16,6,93,72,39,15,82,43,76,88,18,24,10,75,25,12,70,13,82,74,100,93,50,38,40,47,85,86,42,95,52,100,93,57,96,28,93,6,89,62,93,99,83,51,94,38,13,39,96,79,93,11,87,98,89,75,84,94,59,23,46,30,29,44,16,28,79,22,77,33,66,34,93,5,5,7,37,60,70,26,32,13,80,67,83,59,39,99,38,98,41,8,49,50,76,72,78,75,61,88,83,22,79,48,38,51,12,67,58,57,72,16,69,80,96,49,2,50,21,4,58,36,56,15,33,12,12,11,69,25,55,1,36,25,74,86,2,55,88,79,37,52,5,24,62,38,43,89,76,46,63,97,74,87,3,43,76,97,59,24,54,26,34,3,44,13,25,15,73,88,78,99,83,72,16,22,94,93,45,21,14,61,47,43,20,89,73,32,50,71,38,72,24,99,20,40,77,46,66,45,15,34,79,55,3,40,27,7,65,18,46,59,19,45,69,17,63,87,66,99,46,58,19,34,63,81,40,72,19,71,89,55,66,13,49,54,25,2,32,50,91,75,54,52,49,6,57,44,57,46,41,11,21,23,88,88,47,2,64,81,58,49,75,15,66,18,12,54,41,7,43,28,97,3,5,54,71,26,16,98,51,98,28,92,36,19,31,41,1,26,99,96,3,45,74,60,28,61,15,70,94,96,45,96,2,22,25,36,12,91,33,8,22,60,19,1,34,45,82,99,18,81,28,17,13,70,75,6,82,12,61,50,9,82,4,8,80,64,91,98,12,81,48,82,12,94,36,27,36,76,50,27,3,50,36,34,79,75,15,70,81,75,60,45,96,46,58,99,19,87,51,59,92,94,25,74,2,27,49,95,2,59,36,53,20,59,94,51,53,36,55,24,7,80,85,42,30,37,64,88,42,69,72,56,81,80,19,67,55,29,69,32,43,43,59,63,61,33,78,14,88,14,39,40,35,61,8,48,78,2,9,0,36,92,66,45,6,41,39,86,30,77,86,73,54,84,36,1,6,9,55,21,23,87,85,43,33,83,18,81,34,68,73,79,82,73,82,16,8,68,58,58,14,3,72,76,92,50,83,23,0,61,37,69,83,58,48,2,37,2,23,88,80,46,37,50,4,93,45,26,39,97,41,21,53,44,41,14,0,8,97,29,25,57,70,49,87,56,24,65,93,52,3,44,100,35,75,50,46,94,81,19,6,62,74,45,55,91,33,26,55,32,82,72,49,52,46,16,2,61,1,34,1,98,13,79,70,53,25,63,70,27,37,55,89,88,71,40,0,60,84,37,73,40,62,85,17,12,8,63,80,69,77,4,59,38,32,42,100,5,77,59,4,10,53,7,22,79,64,68,29,24,5,42,51,96,28,56,53,75,75,14,61,19,88,89,19,85,6,15,48,7,4,42,7,39,31,45,86,64,35,96,23,64,54,66,45,61,57,64,5,85,98,85,70,54,34,19,38,48,17,7,100,89,4,5,37,88,1,5,55,23,100,23,85,99,99,66,13,77,51,32,28,19,40,95,61,5,19,48,41,97,88,69,16,14,64,93,9,35,37,35,28,29,35,13,63,36,91,23,84,40,27,9,46,51,85,15,83,22,33,48,69,91,25,38,84,70,82,63,23,25,83,49,88,30,39,17,85,47,27,2,41,97,29,69,85,5,5,64,32,98,22,34,37,85,95,50,12,6,16,76,3,59,12,61,58,94,94,70,17,87,47,62,69,84,87,59,26,63,0,42,10,20,78,4,76,4,7,50,42,66,9,29,98,57,26,93,91,23,68,42,4,42,100,49,26,32,85,59,26,61,87,51,55,83,53,86,50,35,13,64,78,40,56,34,57,58,82,44,15,82,66,3,30,51,83,70,72,52,32,18,24,81,42,83,58,61,9,97,75,1,95,83,26,84,63,18,6,85,86,58,81,27,53,100,39,58,4,30,59,57,51,78,67,1,20,64,73,92,49,63,21,60,10,42,80,58,61,15,72,92,68,35,0,46,0,18,78,3,78,63,99,13,20,7,0,87,98,65,24,36,11,7,37,92,81,48,56,86,75,22,66,17,2,86,83,55,44,20,94,89,32,24,37,54,50,85,26,55,17,58,24,57,64,48,70,35,63,13,83,13,77,0,71,0,27,67,69,77,76,11,13,29,18,72,88,31,3,41,78,28,12,71,69,68,56,5,8,15,47,5,89,68,70,85,15,94,11,10,72,78,92,12,1,79,43,86,80,92,33,12,1,9,16,10,29,30,7,71,73,80,18,68,43,81,77,10,43,42,50,12,8,45,16,66,41,79,84,4,92,68,26,88,71,97,100,52,48,6,9,72,77,49,63,89,32,62,44,49,36,58,99,1,41,75,31,84,28,81,64,30,43,44,57,87,3,72,75,84,68,67,96,22,33,32,17,35,15,38,84,7,56,67,98,31,30,48,29,5,50,77,65,16,73,86,48,61,9,99,84,24,64,24,55,67,36,53,17,82,77,14,7,83,44,69,86,9,18,98,51,87,99,81,29,28,12,33,91,78,57,47,52,91,15,43,36,58,27,27,81,86,21,5,15,13,50,18,77,76,77,76,55,61,26,73,74,73,95,65,86,1,24,49,98,48,32,67,53,38,17,6,11,69,23,71,70,2,87,93,13,59,99,48,39,32,49,94,61,21,71,89,77,86,100,66,19,72,41,51,40,92,79,1,1,29,55,70,72,32,87,88,0,1,4,32,52,13,74,0,37,96,46,22,25,6,63,63,16,65,68,50,15,35,37,26,73,71,55,41,76,88,64,3,9,27,31,80,14,44,70,7,7,84,54,19,44,74,96,83,26,13,48,49,7,54,24,25,3,67,54,21,98,17,31,80,57,20,77,60,23,18,52,15,3,3,78,31,11,16,3,5,55,31,13,6,95,58,5,51,65,76,60,16,6,83,23,53,14,21,56,18,69,48,53,78,21,80,31,94,82,48,58,19,40,79,74,5,72,38,87,75,40,100,39,32,67,10,77,83,33,75,84,33,86,19,43,69,57,65,74,87,59,28,40,12,60,57,31,12,87,30,93,47,18,41,96,20,7,4,4,9,3,5,78,39,74,25,17,7,32,11,10,80,43,64,83,100,18,42,74,100,29,94,81,41,14,82,8,28,20,82,46,37,95,44,15,34,68,30,7,62,84,18,65,7,67,64,53,13,40,41,98,99,27,0,23,21,12,34,52,20,66,41,7,96,82,55,20,21,48,0,47,50,20,97,73,9,63,74,54,53,46,50,24,3,4,87,91,41,12,95,54,2,69,2,29,20,8,65,59,44,67,33,89,92,70,40,9,45,13,97,43,52,80,55,26,51,96,0,22,7,74,77,80,22,86,16,7,61,12,40,39,14,20,66,88,67,70,23,99,17,73,36,63,54,5,8,54,37,36,82,76,95,50,29,30,23,52,64,57,12,43,91,61,60,55,33,97,74,76,11,5,99,31,54,72,32,16,53,70,12,29,78,53,38,15,48,16,75,91,68,86,20,21,28,15,16,72,63,2,0,52,51,78,15,81,89,81,72,1,24,2,27,37,49,34,6,96,55,7,56,27,64,63,3,48,26,89,26,63,75,77,34,46,32,61,96,2,80,29,94,76,14,36,46,99,86,12,86,95,58,55,64,36,12,47,10,10,7,83,74,13,11,11,59,63,30,6,43,38,56,68,64,28,49,71,39,78,29,83,42,48,66,66,42,46,69,70,32,2,66,4,9,15,9,39,0,82,86,88,5,10,21,25,18,38,88,19,21,61,100,67,33,56,4,86,51,54,32,94,58,29,93,28,66,43,44,71,100,63,21,21,15,27,57,91,31,35,72,62,11,73,96,97,28,28,5,38,9,30,28,63,64,98,23,6,63,94,77,100,63,65,37,37,46,47,55,3,66,84,15,33,39,99,71,5,96,94,60,52,47,71,33,36,17,58,88,6,89,18,74,61,29,49,98,71,12,83,98,82,1,0,74,77,35,99,100,19,3,93,26,26,10,4,96,15,4,87,55,23,41,43,78,99,70,11,44,33,65,71,93,84,89,57,65,36,12,70,51,43,35,17,64,2,3,79,43,7,2,41,40,16,15,82,42,41,36,56,33,6,85,95,76,57,57,61,42,13,61,28,47,31,20,53,36,33,94,83,23,94,9,9,9,15,96,85,88,8,19,46,31,92,56,33,27,61,18,37,28,48,6,71,15,37,44,86,44,44,12,67,98,56,86,74,31,31,32,82,38,42,27,37,40,75,94,34,39,38,1,44,65,14,60,21,1,45,70,71,17,89,19,25,51,30,86,84,59,72,48,30,69,57,96,43,15,74,81,3,97,82,88,46,30,3,42,38,18,22,44,40,62,69,32,22,94,31,79,76,59,9,19,98,47,84,62,77,27,36,98,22,34,25,46,64,12,69,39,97,98,70,56,78,19,0,69,49,81,99,16,79,30,91,63,75,60,14,51,60,57,85,40,15,15,69,98,75,88,66,46,15,66,23,43,47,81,97,36,73,91,41,78,13,69,20,53,53,5,67,65,73,53,81,51,76,27,80,6,30,59,76,95,26,92,30,45,29,84,85,15,65,1,26,46,4,23,5,26,25,57,13,78,21,20,79,11,99,49,69,65,28,82,13,35,74,39,1,5,31,66,95,8,6,52,85,0,27,9,25,37,82,94,91,45,18,10,80,74,22,96,14,23,37,56,30,25,10,80,58,22,44,70,27,81,26,14,36,56,6,63,68,9,44,36,34,30,84,79,31,71,25,72,54,58,50,60,76,42,98,46,92,30,61,65,26,85,14,97,19,93,43,6,62,16,75,52,3,95,69,43,33,77,52,69,5,40,28,11,86,20,9,96,3,50,72,35,22,80,77,45,25,17,24,21,13,71,96,5,56,4,8,70,71,14,87,75,27,11,78,93,10,23,54,19,93,62,60,13,61,53,51,73,10,33,5,37,14,27,57,24,89,77,48,25,83,70,96,32,30,20,4,27,46,2,54,0,88,6,71,17,42,43,78,3,46,98,19,77,76,20,60,16,51,12,81,62,72,58,30,92,93,33,61,47,25,91,31,46,72,72,97,10,100,6,58,16,55,89,43,41,93,68,62,10,33,99,35,62,9,10,98,95,46,87,99,75,83,31,82,83,33,45,37,29,59,30,10,18,91,9,47,38,18,97,82,52,6,35,22,68,93,77,57,81,19,74,38,0,93,89,64,8,22,11,47,81,57,94,0,8,75,37,11,10,7,59,10,4,39,57,10,38,24,88,60,66,88,42,92,70,13,52,79,76,81,1,57,26,27,74,68,37,15,42,88,56,29,16,28,46,100,1,36,27,98,70,12,27,53,88,3,23,12,57,13,61,56,84,38,76,68,16,41,48,23,24,95,73,86,93,37,73,47,51,95,3,87,81,98,100,88,54,89,87,82,30,65,94,56,50,5,84,33,12,2,67,85,76,44,73,8,50,32,56,2,49,68,5,25,95,81,26,4,0,43,32,88,85,50,21,76,63,34,0,81,94,35,38,84,99,62,63,0,45,78,87,11,33,73,88,20,57,46,28,77,43,97,69,53,89,23,13,71,65,6,30,41,25,91,69,55,64,79,15,77,37,50,92,44,33,35,48,57,85,18,19,15,42,98,8,14,33,74,21,32,67,60,21,86,20,14,20,70,17,60,55,61,68,45,47,92,28,81,47,10,88,59,99,42,53,42,81,50,72,48,20,88,56,16,3,12,73,37,11,21,48,20,50,58,70,22,28,74,49,18,89,73,62,9,49,86,63,76,44,74,68,50,74,76,63,81,56,49,72,23,48,76,78,38,55,25,0,53,39,42,26,67,98,96,100,7,25,58,21,7,74,34,16,93,94,4,24,17,94,95,61,6,84,4,76,82,34,60,15,81,45,45,27,45,74,57,8,16,84,18,68,65,97,10,69,23,86,83,42,3,49,77,2,97,64,55,3,3,74,84,36,95,16,13,51,10,35,95,21,76,24,0,39,99,93,5,2,44,26,94,7,37,73,66,92,100,57,88,2,30,85,94,96,78,80,43,83,92,88,92,7,41,18,94,13,12,89,18,5,92,50,69,59,98,14,93,84,31,60,8,81,81,37,79,11,53,88,32,45,39,66,5,63,28,50,52,44,45,48,74,20,12,15,10,79,17,65,86,49,19,35,60,71,64,72,52,19,97,22,88,44,41,74,43,2,11,83,5,75,42,3,36,41,28,10,35,34,24,24,44,60,96,70,6,95,57,50,66,75,95,87,47,32,11,0,34,44,97,14,75,71,15,40,22,81,24,16,55,68,17,16,9,38,21,64,88,58,45,23,98,61,58,25,46,71,55,5,38,77,87,33,1,21,62,28,48,79,64,81,70,11,74,77,4,99,37,16,71,50,16,16,25,98,99,59,30,40,96,21,8,58,15,78,53,48,52,71,80,4,46,54,15,62,51,59,46,97,21,12,27,80,8,30,14,28,83,43,87,51,44,53,63,36,24,51,68,88,46,8,19,49,76,17,95,70,74,63,40,8,29,42,1,11,42,94,100,6,50,49,22,11,3,17,53,24,28,16,85,68,63,37,52,55,18,72,83,65,68,43,16,10,99,7,14,71,58,43,48,41,27,100,60,57,76,34,24,49,61,38,32,38,91,63,66,59,60,43,42,56,41,59,58,32,32,73,10,50,67,66,54,32,28,85,71,21,66,53,5,39,57,32,93,89,22,88,17,43,63,85,42,52,87,28,32,17,40,35,39,72,77,64,98,30,16,56,49,7,69,44,53,50,19,91,55,74,74,73,60,57,0,49,42,44,51,62,63,82,71,66,83,66,85,91,50,70,58,25,87,37,79,66,6,65,68,28,74,20,15,40,61,37,60,49,80,97,99,48,9,58,86,98,57,6,70,29,69,22,1,49,84,33,8,56,31,100,6,37,27,27,91,30,87,70,28,53,81,80,43,3,65,16,75,71,61,60,68,18,6,61,67,88,20,32,27,49,1,66,91,91,76,97,93,24,79,21,28,98,82,43,82,55,82,22,0,1,74,76,17,84,56,82,30,27,5,16,81,60,59,64,26,38,55,14,4,11,27,9,26,43,12,5,56,19,79,47,24,87,72,60,51,7,54,28,99,16,36,65,91,9,68,35,45,47,71,37,86,36,13,69,10,29,34,56,19,97,15,66,57,40,25,22,80,92,50,27,73,74,65,37,62,9,31,100,12,79,26,100,81,2,72,45,10,95,65,10,67,1,9,36,53,87,2,10,88,34,38,58,63,82,73,22,37,100,81,28,68,61,66,23,66,76,45,39,53,61,54,76,18,25,6,31,77,15,94,28,76,82,98,95,72,100,60,51,22,32,37,83,59,0,30,12,22,54,0,74,93,85,39,30,39,60,93,71,89,87,67,62,7,96,51,67,73,53,40,70,75,80,34,39,58,34,67,25,23,72,53,55,22,87,25,61,60,29,76,88,64,41,91,9,76,48,75,99,15,67,42,72,67,18,100,36,76,37,37,84,54,14,50,83,100,40,79,56,58,64,23,19,47,19,55,7,13,32,64,65,93,23,23,18,25,73,29,50,96,43,48,8,14,80,17,70,75,41,65,52,69,39,99,52,69,6,70,32,65,18,78,50,15,55,41,73,80,46,43,4,18,71,44,75,91,48,40,3,58,44,77,17,65,32,6,16,3,53,28,49,67,80,39,95,19,50,61,89,95,55,87,20,4,16,46,67,12,100,99,84,48,49,65,85,25,48,32,24,57,81,52,80,96,92,62,22,32,5,63,21,45,14,96,79,94,88,96,35,52,16,15,86,1,14,15,33,35,17,98,50,9,31,13,51,29,33,0,64,61,96,67,79,25,26,74,49,56,63,64,41,30,63,62,2,15,70,49,88,59,99,4,93,62,47,85,33,76,0,5,18,10,3,70,12,25,9,39,46,40,18,85,33,89,40,49,49,81,7,75,35,39,85,88,49,47,31,58,25,17,50,39,70,37,78,31,66,19,13,76,3,13,18,22,40,11,70,94,4,65,18,47,18,26,64,91,22,67,4,0,26,70,39,81,67,78,46,23,94,13,70,57,54,62,5,60,77,48,70,46,56,8,14,55,9,4,72,62,70,51,16,36,61,56,34,4,75,80,10,75,52,22,96,77,29,76,52,0,6,63,14,58,0,35,47,62,32,61,26,66,94,12,13,51,29,9,29,59,78,95,28,76,37,18,54,38,63,60,15,8,89,71,52,13,8,85,40,87,67,47,50,74,80,46,41,85,14,86,97,25,99,43,34,53,82,29,36,59,91,78,51,18,85,88,20,53,28,26,78,43,63,75,31,16,30,39,17,54,100,70,60,4,56,59,53,40,47,23,15,92,37,98,1,34,53,34,18,68,71,78,47,81,92,24,58,64,32,14,1,1,58,4,41,71,30,39,22,36,82,4,71,92,26,30,63,1,44,26,98,65,8,48,42,71,65,35,36,41,68,53,28,79,82,14,72,100,62,50,86,28,24,70,88,38,23,51,50,85,15,60,71,7,43,92,98,1,34,48,88,38,93,13,65,96,13,94,47,69,22,9,29,54,28,52,87,56,82,23,96,86,38,95,44,67,80,56,28,48,1,40,3,35,62,51,11,93,17,46,19,54,36,99,26,96,33,53,19,42,30,21,84,40,6,76,40,96,10,24,88,75,36,22,38,22,76,58,81,52,1,84,51,49,73,70,0,83,3,1,16,32,26,9,78,16,31,43,71,44,12,87,4,62,28,56,99,46,5,4,33,50,57,61,9,82,8,34,33,58,80,85,4,54,66,86,71,93,91,67,96,39,80,48,46,80,21,46,13,52,72,22,41,87,57,24,70,69,70,80,19,71,22,9,81,12,71,10,29,98,7,98,54,70,47,87,46,6,84,59,2,65,82,87,57,66,43,100,21,43,15,31,92,96,22,3,70,81,48,17,6,81,40,78,12,19,93,77,69,36,59,1,20,58,27,23,79,97,100,91,50,45,42,42,84,97,74,86,23,8,86,91,33,10,25,71,52,52,67,91,2,81,2,63,4,3,58,65,94,85,63,10,52,20,83,60,87,85,54,45,61,49,60,36,26,37,66,69,10,96,9,75,27,32,21,79,76,67,17,52,7,68,14,79,76,93,68,46,6,30,77,11,54,29,53,25,7,33,99,3,98,72,75,40,42,62,50,0,74,64,51,68,66,97,39,100,29,14,88,44,96,31,7,60,99,21,63,47,83,4,96,87,66,75,33,94,60,27,88,96,53,63,22,33,44,88,75,24,52,45,98,7,9,17,41,0,19,10,56,69,53,59,61,80,77,47,31,55,87,60,82,79,82,63,100,71,0,28,45,51,22,69,45,13,11,58,7,2,73,0,68,1,38,17,6,71,82,39,75,70,79,99,80,31,50,20,37,79,11,53,56,41,62,48,39,71,31,23,29,43,9,13,75,80,17,74,62,59,0,52,5,68,27,7,71,63,87,40,17,81,13,70,13,88,31,43,93,7,92,6,15,86,32,35,8,71,80,5,7,82,32,29,40,2,87,68,57,10,78,36,99,84,7,27,40,38,31,22,99,69,53,26,63,64,15,37,80,62,37,78,11,91,77,3,11,55,41,79,99,100,47,89,31,37,91,80,44,83,67,83,97,2,38,6,45,81,34,70,20,75,89,13,49,61,19,84,95,95,0,38,5,53,2,62,27,41,74,13,51,94,80,34,92,66,82,11,7,30,17,52,72,48,92,33,73,53,16,44,98,100,48,49,17,8,41,36,98,76,8,26,91,85,57,53,97,22,62,41,42,58,77,78,12,6,81,72,9,13,63,23,25,89,98,71,60,43,42,5,45,20,87,24,67,59,23,22,61,0,21,32,63,1,17,15,49,1,48,2,86,38,17,42,9,100,53,61,5,40,43,34,3,96,74,12,48,77,49,87,35,54,3,86,43,51,6,53,95,88,1,12,43,27,57,9,85,63,83,19,21,19,89,48,22,65,26,62,47,59,78,61,29,67,49,74,3,33,43,68,36,15,33,85,10,35,75,75,60,13,68,51,31,41,48,15,38,1,98,93,71,5,17,61,5,17,85,18,95,81,3,82,10,8,69,97,38,72,81,99,6,41,94,24,38,41,53,0,13,25,47,62,70,18,14,89,35,29,39,31,91,51,35,31,48,3,65,100,57,27,31,23,9,22,1,39,9,25,4,34,0,55,18,50,89,70,9,6,11,2,2,100,23,88,3,92,51,63,39,43,88,23,14,82,23,100,58,34,25,8,75,10,35,98,64,39,30,88,29,30,25,18,61,51,89,88,46,76,45,49,97,34,34,79,46,37,49,41,27,42,16,59,11,41,70,81,42,85,63,52,29,73,24,27,6,92,13,85,75,12,57,94,89,78,80,43,46,89,70,87,22,48,13,2,88,85,60,72,64,80,12,56,15,38,24,10,86,72,27,53,35,32,78,37,74,100,14,59,39,42,42,27,29,58,92,91,48,6,72,22,79,9,59,25,30,29,82,16,57,71,73,87,62,52,29,12,78,14,85,48,5,40,8,32,62,32,3,29,18,66,60,93,17,87,38,11,17,64,16,100,96,42,86,65,9,77,50,25,93,5,3,42,56,93,30,37,66,57,34,32,25,11,64,45,44,22,45,32,14,4,98,14,27,45,28,16,59,36,41,27,12,38,25,10,29,33,31,25,26,75,16,65,89,93,37,20,5,45,95,91,11,44,40,70,26,77,89,83,35,21,86,73,47,62,5,55,11,83,95,3,4,59,34,61,21,6,91,26,94,78,49,17,49,30,47,99,91,87,58,74,30,25,12,94,6,93,73,33,36,94,51,67,29,27,4,78,51,48,2,67,27,48,51,91,53,42,95,85,1,96,93,83,28,9,8,59,12,88,34,54,33,31,19,58,26,41,77,15,57,57,31,13,94,15,34,23,12,77,3,70,75,65,7,48,0,47,11,46,38,38,77,27,63,72,3,13,22,64,42,54,27,52,17,95,11,79,87,47,94,19,2,37,2,53,1,9,48,41,92,16,60,80};
    std::vector<int> test_empty {};
    assert(shuffle_array("test_dir/test.txt") != test_1);
    assert(shuffle_array("test_dir/test_2.txt") == test_2);
    assert(shuffle_array("test_dir/test_3.txt") == test_3_1 || shuffle_array("test_dir/test_3.txt") == test_3_2);
    assert(shuffle_array("test_dir/test_4.txt") == test_4);
    assert(shuffle_array("test_dir/test_5.txt") != test_5);
    assert(shuffle_array("test_dir/test_6.txt") != test_6);
    assert(shuffle_array("test_dir/test_7.txt") != test_7);
    assert(shuffle_array("test_dir/test_empty.txt") == test_empty);
    cout << "Ok" << endl;
}

int main() {
    TestLabelEnc();
    return 0;
}