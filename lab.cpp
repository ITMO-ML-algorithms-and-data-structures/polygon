#include <vector>
#include <iostream>

typedef long long ll;

ll INF = 1000000007;

using namespace std;

pair <ll, ll> getMaxComposition(vector<ll> digits) {
    auto size = digits.size();

    ll max_1 = -INF, max_2 = -INF, min_1 = INF, min_2 = INF;

    // отработатываем вариант, когда размер входного массива меньше 2, выбрасываем нули
    if (size < 2) {
        return {0, 0};
    }

    // ищем два минимальных элемента и два максимальных элемента
    for (int i=0; i<size; i++) {
        if (digits[i] >= max_1) {
            max_2 = max_1;
            max_1 = digits[i];
        } else if (digits[i] >= max_2) {
            max_2 = digits[i];
        }

        if (digits[i] <= min_1) {
            min_2 = min_1;
            min_1 = digits[i];
        } else if (digits[i] <= min_2) {
            min_2 = digits[i];
        }
    }

    // произведение двух отрицательных наименьших чисел может быть больше произведения
    // двух наибольших чисел => надо отработать этот вариант
    if (max_1 * max_2 > min_1 * min_2) {
        return {max_1, max_2};
    } else {
        return {min_1, min_2};
    }
}