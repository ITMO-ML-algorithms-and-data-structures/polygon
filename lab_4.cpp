#include <algorithm>
#include <random>
#include <vector>
#include <iostream>
#include <fstream>
#include <set>
#include <string>

using namespace std;

// Тип данных элементов множеств
#define set_element int

int MAX_SIZE = 25;

int sumMask(int mask) {
    int sum = 0;
    for (int bit = 0; bit < MAX_SIZE; bit++) {
        if ((mask >> bit) & 1) sum++;
    }
    return sum;
}


vector<vector<set_element>> applyMask(vector<vector<set_element>> given_sets, int mask) {
    vector<vector<set_element>> maskSets(0);

    // Асимтотика N
    for (int bit = 0; bit < given_sets.size(); bit++)
        if ((mask >> bit) & 1) {
            maskSets.push_back(given_sets[bit]);
        }
    return maskSets;
}


vector<set_element> setUnionOfSets(vector<vector<set_element>> given_sets) {
    vector<set_element> result(0);

    // Асимтотика N * MAX_SET_SIZE = 50 * N
    for (auto set_i : given_sets) {
        set_union(
                result.begin(), result.end(),
                set_i.begin(), set_i.end(),
                back_inserter(result)
        );
    }
    return result;
}

bool isCoverage(vector<vector<set_element>> given_sets, int mask, vector<set_element> target_set) {
    vector<set_element> coverage;
    vector<vector<set_element>> maskSets = applyMask(given_sets, mask);
    vector<set_element> unionSet = setUnionOfSets(maskSets);

    set_union(
            unionSet.begin(), unionSet.end(),
            target_set.begin(), target_set.end(),
            back_inserter(coverage)
            );
    if (unionSet.size() != coverage.size()) return false;
    for (int i = 0; i < unionSet.size(); i++){
        if (unionSet[i] != coverage[i]) return false;
    }
    return true;
}

vector<vector<set_element>> MinimumCoverage(vector<vector<set_element>> given_sets, vector<set_element> target_set) {
    // Если целевое множество пустое то возвращается пустое
    if (!target_set.size()) return {};

    // Маска из всех единиц
    int full_mask = (1 << given_sets.size()) - 1;

    // Инициализация ответа (изначально это все множества + первое, дальше уменьшаем длину)
    vector<vector<set_element>> answer = applyMask(given_sets, full_mask);
    answer.push_back(given_sets[0]);

    // Проверка существования покрытия
    bool coverageExists = false;

    // Проверка ВСЕХ бинарных масок (ассимтотика 2^N)
    for (int mask = 1; mask <= full_mask; mask++) {
        if (isCoverage(given_sets, mask, target_set) && sumMask(mask) < answer.size()) {
            answer = applyMask(given_sets, mask);
            coverageExists = true;
        }
    }

    if (coverageExists) return answer;
    return {};
}


int main() {
    // Чтение из файла формата:
    // N - количество множеств в массиве
    // n, a_1, a_2, ..., a_n - числа в i-ом множестве
    //
    // n, t_1, t_2, ..., t_n - числа в целевом множестве

    int N, n;
    vector<vector<set_element>> given_sets;


    ifstream in("/Users/danil/PLUSPLUS/polygon/tests/lab_4_folder/executable.txt");
    if (!in.is_open()) return 0;

    in >> N;
    for (int i = 0; i < N; i++) {
        in >> n;
        given_sets.push_back(vector<set_element>(n));
        for (int j = 0; j < n; j++) in >> given_sets[i][j];
    }
    in >> n;
    vector<set_element> target_set(n);
    for (int j = 0; j < n; j++) in >> target_set[j];

    auto answer = MinimumCoverage(given_sets, target_set);

    for (auto set_i : answer) {
        for (auto element : set_i) cout << element << ' ';
        cout << '\n';
    }
    in.close();

    return 0;
}