#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <bitset>
#include <limits>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Функция для проверки, покрывает ли текущее подмножество множеств множество A
bool covers(const unordered_set<int>& union_set, const unordered_set<int>& universe) {
    for (const int& elem : universe) {
        if (union_set.find(elem) == union_set.end()) {
            return false;
        }
    }
    return true;
}

pair<vector<set<int>>, int> set_cover(const vector<set<int>>& sets, const set<int>& universe) {
    size_t N = sets.size();
    size_t min_set_count = N + 1;
    vector<size_t> best_combination_indices;
    unordered_set<int> universe_set(universe.begin(), universe.end());

    size_t total_combinations = 1ULL << N;
    auto start_time = steady_clock::now();


    for (size_t i = 1; i < total_combinations; ++i) {
        // Проверка времени выполнения
        if (duration_cast<seconds>(steady_clock::now() - start_time).count() > 0.001) {
            throw runtime_error("Время выполнения превысило 0.001c");
        }

        unordered_set<int> union_set;
        vector<size_t> current_indices;


        for (size_t j = 0; j < N; ++j) {
            if (i & (1ULL << j)) {
                union_set.insert(sets[j].begin(), sets[j].end());
                current_indices.push_back(j);
            }
        }

        // Проверяем, покрывает ли объединение множество A
        if (covers(union_set, universe_set)) {
            if (current_indices.size() < min_set_count) {
                min_set_count = current_indices.size();
                best_combination_indices = current_indices;
            }
            // Если нашли минимальное возможное покрытие
            if (min_set_count == 1) {
                break;
            }
        }
    }

    // Формируем результат
    vector<set<int>> result_sets;
    for (size_t idx : best_combination_indices) {
        result_sets.push_back(sets[idx]);
    }

    return make_pair(result_sets, min_set_count);
}

// Функция для вывода множеств
void print_sets(const vector<set<int>>& sets) {
    cout << "{";
    for (size_t i = 0; i < sets.size(); ++i) {
        cout << "{";
        auto it = sets[i].begin();
        while (it != sets[i].end()) {
            cout << *it;
            ++it;
            if (it != sets[i].end()) cout << ", ";
        }
        cout << "}";
        if (i != sets.size() - 1) cout << ", ";
    }
    cout << "}";
}

int main() {
    // Тестовые примеры
    vector<tuple<vector<set<int>>, set<int>, vector<set<int>>>> test_cases = {
        // Пример 1
        {
            {{1, 2}, {2, 3}, {3, 4}}, // sets B
            {1, 2, 3},                // universe A
            {{1, 2}, {2, 3}}          // expected output
        },
        // Дополнительный пример
        {
            {{1, 2}, {3}, {2, 4}, {3, 4}}, // sets B
            {1, 2, 3, 4},                  // universe A
            {{1, 2}, {3, 4}}               // expected output
        },
      {
          {{1, 2}, {3}, {4}, {3, 4}, {4, 5}}, // sets B
          {1, 2, 3, 4, 5},                  // universe A
          {{1, 2}, {3}, {4, 5}}               // expected output
        }
    };

    for (size_t idx = 0; idx < test_cases.size(); ++idx) {
        const auto& [sets, universe, expected] = test_cases[idx];

        try {
            auto [result_sets, min_set_count] = set_cover(sets, universe);

            cout << "Тестовый пример " << idx + 1 << ":\n";
            cout << "Множества B: ";
            print_sets(sets);
            cout << "\nМножество A: {";
            for (auto it = universe.begin(); it != universe.end(); ++it) {
                cout << *it;
                auto next_it = it;
                ++next_it;
                if (next_it != universe.end()) cout << ", ";
            }
            cout << "}\n";
            cout << "Минимальное количество множеств: " << min_set_count << "\n";
            cout << "Полученное покрытие: ";
            print_sets(result_sets);
            cout << "\nОжидаемое покрытие: ";
            print_sets(expected);
            cout << "\n--------------------------------------------------\n";
        } catch (const exception& e) {
            cout << "Ошибка: " << e.what() << "\n";
        }
    }

    return 0;
}
