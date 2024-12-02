#include <iostream>
#include <vector>
using namespace std;

// Рекурсивная функция для поэтапной генерации всех комбинаций размера K из индексов от 0 до N-1
// Сложность:  N! / K!(N-K)!, что приближено к N^K, особенно на малых значениях
void generateCombinations(int N, int K, int start, vector<int>& current_combination, vector<vector<int> >& combinations) {
    // Если текущая комбинация нужного размера, добавляем ее в список
    if (current_combination.size() == K) {
        combinations.push_back(current_combination);
        return;
    }

    // Итерируемся по индексам от 'start' до N - (K - текущий размер) + 1
    for (int i = start; i <= N - (K - current_combination.size()); ++i) {
        // Добавляем текущий индекс в комбинацию
        current_combination.push_back(i);
        // Рекурсивно строим комбинации из следующих индексов
        generateCombinations(N, K, i + 1, current_combination, combinations);
        // Возвращаемся назад, удаляя последний индекс, чтобы попробовать другие комбинации
        current_combination.pop_back();
    }
}

int main() {
    // Читаем размер массива N и размер комбинаций K
    int N, K;
    cin >> N >> K;

    // Читаем массив целых чисел
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    // Вектор для хранения всех возможных комбинаций индексов
    vector<vector<int> > combinations;
    // Временный вектор для построения текущей комбинации
    vector<int> current_combination;

    // Генерируем все комбинации индексов размера K
    // Сложность: O(N choose K)
    generateCombinations(N, K, 0, current_combination, combinations);

    // Вектор для хранения комбинаций, сумма элементов которых равна нулю
    vector<vector<int> > result;

    // Для каждой комбинации вычисляем сумму и проверяем, равна ли она нулю
    // Общая сложность: O(N choose K * K)
    for (const auto& indices : combinations) {
        int sum = 0;
        // Вычисляем сумму элементов по данным индексам
        // Сложность на комбинацию: O(K)
        for (int idx : indices) {
            sum += arr[idx];
        }
        // Если сумма равна нулю, добавляем комбинацию в результат
        if (sum == 0) {
            result.push_back(indices);
        }
    }

    // Выводим комбинации, сумма которых равна нулю
    // Сложность: O(число подходящих комбинаций * K)
    for (const auto& indices : result) {
        cout << "[";
        for (size_t i = 0; i < indices.size(); ++i) {
            cout << indices[i];
            if (i < indices.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
    }

    return 0;
}