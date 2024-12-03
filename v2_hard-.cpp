#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool prime(int num){ //функция на проверку простоты числа
    for (int div = 2; div < round(sqrt(num)) + 1; div++)
        if (num % div == 0){
            return 0;
    }
    return 1;
}

int main() {
    int n, mi;
    cin >> n; //тк не было формата входных данных, допустим, что n - длинна массива
    int m[n];
    for (int i = 0; i < n; i++){
        cin >> mi; //ввод самого массива
        m[i] = mi;
    }
    vector<pair<int, int>> ans; //ans - вектор пар, где первый элемент найденое простое число, а второй кол-во его повторений
    for (int j = 0; j < n; j++){ //ищем простое число
        if (prime(m[j])){
            bool flag_repeat = 0;
            for (int k = 0; k < ans.size(); k++){ //смотрим есть ли найденное простое число в ans
                if (ans[k].first == m[j]){
                    flag_repeat = 1;
                    ans[k].second++;
                    break;
                }
            }
            if (!flag_repeat){ //если не было, то добовляем
                ans.push_back(make_pair(m[j], 1));
            }
        }
    }
    for (int i = 0;i < ans.size(); i++){
        if (ans[i].second % 2 == 0){ //выводим все простые числа, которые повторялись чётное кол-во раз
           cout << ans[i].first << " ";
        }
    }
    return 0;
}
