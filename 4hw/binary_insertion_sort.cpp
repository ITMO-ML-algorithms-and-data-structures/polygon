#include "binary_insertion_sort.h"

size_t binary_search(const std::vector<long long> &v, size_t left, size_t right, long long key) {
    if (left >= right)
        return key >= v[left] ? left + 1 : left;

    size_t mid = (left + right) / 2;

    if (key == v[mid]) return mid + 1;
    if (key > v[mid]) return binary_search(v, mid + 1, right, key);
    return binary_search(v, left, mid == 0 ? mid : mid - 1, key);
}

void binary_insertion_sort(std::vector<long long> &v) {
    for (size_t i = 1; i < v.size(); ++i) {
        // i - индекс элемента, который̆ нужно вставить
        // O(n) - время

        long long key = v[i];
        // вставляемый элемент

        size_t j = i - 1;
        // j - индекс последнего элемента отсортированного подмассива

        size_t l = binary_search(v, 0, j, key);
        // loc - индекс на котором должен стоять вставляемый элемент в отсортированном подмассиве
        // O(log i) - время, i - длина отсортированного подмассива

        while (j >= l) {
            // сдвигаем элементы большие вставляемого вправо
            // O(i - l) - время
            v[j + 1] = v[j];
            if (j == 0) break;
            --j;
        }

        l == 0 ? v[0] = key : v[j + 1] = key;
        // вставляем вставляемый элемент
    }
    // время:
    // перебор * (бинарный поиск + сдвиг)
    // в отличие от стандартной сортировки:
    // перебор * (сравнение + сдвиг)

    // худший случай O(n^2)
    // средний случай O(n^2)
    // лучший случай O(n * log n)

    // память O(1)
}

std::pair<std::string, double> execute_binary_insertion_sort(const std::string &input) {
    std::vector<long long> v;

    std::istringstream input_ss(input);
    long long tmp;
    while (input_ss >> tmp) v.push_back(tmp);

    const size_t start = clock();
    binary_insertion_sort(v);
    const size_t end = clock();

    std::ostringstream output_ss;
    for (const long long &e: v) output_ss << e << ' ';

    return {output_ss.str(), (double) (end - start) / CLOCKS_PER_SEC};
}