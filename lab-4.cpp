#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <chrono>
#include <random>

using namespace std;

// Функция для нахождения минимального количества множеств для покрытия
// Множества передаю по ссылке как константу (нельзя менять в теле функции)
vector<set<int>> minimum_sets_to_cover(const vector<set<int>>& sets, const set<int>& universe) {
    int n = sets.size();
    vector<set<int>> best_combination;
    int min_size = n + 1; // Инициализируем минимальный размер большим значением

    // Комбинаторно проверяем все возможные комбинации подмножеств
    // Их 2^n = 1 << n
    // 1 - включен, 0 - не включен
    for (int mask = 1; mask < (1 << n); ++mask) {
        set<int> union_set;
        vector<set<int>> current_combination;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) { // Если i-й элемент включен в комбинацию
                union_set.insert(sets[i].begin(), sets[i].end());
                current_combination.push_back(sets[i]);
            }
        }

        // Проверяем, покрывает ли объединение множество universe
        if (universe.size() == union_set.size() && includes(union_set.begin(), union_set.end(), universe.begin(), universe.end())) {
            if (current_combination.size() < min_size) {
                min_size = current_combination.size();
                best_combination = current_combination;
            }
        }
    }

    return best_combination;

    // Итого по памяти: 4 + 4*M*N + 4 + 4 + 4*M + 4*N*M + 4 = 4*4 + 2*4*M*N + 4*M = 8MN + 4M + 16 байт
    // Максимальное N=25, M=50 => 8*25*50 + 4*50 + 16 = 10216 байт

    // Итого (асимптотика): O((2^N)*(N*M + M)) = O((2^N)*M(N+1)) = O((2^N)*N*M) = O((2^N)*(N^2)) > O(2^N) - условие выполнено
}

// Функция для тестирования
void run_tests() {
    cout << "Running tests" << endl;

    // Тест 1. Пример из условия
    vector<set<int>> sets1 = {{1, 2}, {2, 3}, {3, 4}};
    set<int> universe1 = {1, 2, 3};

    auto start1 = chrono::high_resolution_clock::now();
    auto result1 = minimum_sets_to_cover(sets1, universe1);
    auto end1 = chrono::high_resolution_clock::now();

    assert((result1 == vector<set<int>>{{1, 2}, {2, 3}}));
    cout << "Test 1 passed in " << chrono::duration_cast<chrono::microseconds>(end1 - start1).count() << " microseconds." << endl;


    // Тест 2. Пустое множество
    vector<set<int>> sets2 = {{}};
    set<int> universe2 = {1, 2, 5};

    auto start2 = chrono::high_resolution_clock::now();
    auto result2 = minimum_sets_to_cover(sets2, universe2);
    auto end2 = chrono::high_resolution_clock::now();

    assert((result2 == vector<set<int>>{}));
    cout << "Test 2 passed in " << chrono::duration_cast<chrono::microseconds>(end2 - start2).count() << " microseconds." << endl;


    // Тест 3. Одноэлементное множество
    vector<set<int>> sets3 = {{1}, {2}, {3}, {4}, {5}};
    set<int> universe3 = {1, 3, 5};

    auto start3 = chrono::high_resolution_clock::now();
    auto result3 = minimum_sets_to_cover(sets3, universe3);
    auto end3 = chrono::high_resolution_clock::now();

    assert((result3 == vector<set<int>>{{1}, {3}, {5}}));
    cout << "Test 3 passed in " << chrono::duration_cast<chrono::microseconds>(end3 - start3).count() << " microseconds." << endl;


    // Тест 4. 2 варианта (а нужен минимальный)
    vector<set<int>> sets4 = {{1, 2}, {3}, {5}, {1, 3, 5}, {5}};
    set<int> universe4 = {1, 3, 5};

    auto start4 = chrono::high_resolution_clock::now();
    auto result4 = minimum_sets_to_cover(sets4, universe4);
    auto end4 = chrono::high_resolution_clock::now();

    assert((result4 == vector<set<int>>{{1, 3, 5}}));
    cout << "Test 4 passed in " << chrono::duration_cast<chrono::microseconds>(end4 - start4).count() << " microseconds." << endl;


    // Тест 5. Пустой вывод
    vector<set<int>> sets5 = {{1}, {3, 5}};
    set<int> universe5 = {2, 4, 6};

    auto start5 = chrono::high_resolution_clock::now();
    auto result5 = minimum_sets_to_cover(sets5, universe5);
    auto end5 = chrono::high_resolution_clock::now();

    assert((result5 == vector<set<int>>{}));
    cout << "Test 5 passed in " << chrono::duration_cast<chrono::microseconds>(end5 - start5).count() << " microseconds." << endl;


    // Тест 6. Пустое множество
    vector<set<int>> sets6 = {{1}, {3, 5}};
    set<int> universe6 = {};

    auto start6 = chrono::high_resolution_clock::now();
    auto result6 = minimum_sets_to_cover(sets6, universe6);
    auto end6 = chrono::high_resolution_clock::now();

    assert((result6 == vector<set<int>>{}));
    cout << "Test 6 passed in " << chrono::duration_cast<chrono::microseconds>(end6 - start6).count() << " microseconds." << endl;

    cout << "All tests have been passed" << endl;
}

// Функция для генерации подмножеств и измерения времени выполнения
void measure_performance() {
    cout << "Measuring efficiency" << endl;

    const int universe_size = 25;
    set<int> universe;

    // Заполняем множество universe числами от 1 до 25
    for (int i = 1; i <= universe_size; ++i) {
        universe.insert(i);
    }

    // Размеры подмножеств для тестирования
    vector<int> sizes = {1, 5, 10, 15, 20, 25};

    for (int size : sizes) {
        vector<set<int>> sets;

        // Генерация подмножеств
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, universe_size);

        for (int i = 0; i < size; ++i) {
            set<int> subset;
            int subset_size = dis(gen) % (universe_size / 2) + 1; // Размер подмножества от 1 до 12

            while (subset.size() < subset_size) {
                subset.insert(dis(gen)); // Добавляем случайные элементы из universe
            }

            sets.push_back(subset);
        }

        auto start = chrono::high_resolution_clock::now();
        vector<set<int>> result = minimum_sets_to_cover(sets, universe);
        auto end = chrono::high_resolution_clock::now();

        double elapsed_time = chrono::duration_cast<chrono::microseconds>(end - start).count();

        cout << "Size: " << size << ", Time: " << elapsed_time / 1e6 << " seconds" << endl;

        // Выводим ответ
        cout << "Result: ";
        if (!result.empty()) {
            cout << "{ ";
            for (const auto& s : result) {
                cout << "{ ";
                for (const auto& elem : s) {
                    cout << elem << " ";
                }
                cout << "} ";
            }
            cout << "}" << endl;
        } else {
            cout << "No solutions" << endl;
        }
    }
    cout << "End" << endl;
}

int main() {
    run_tests();
    cout << endl;
    measure_performance();
    return 0;
}
