#include <iostream> 
#include <random>
#include <vector>
using namespace std;

int main() {
    int elements_of_null;
    int ans_max;
    int current_max;

    int size_of_arr;
    cout << "здесь НУЖно написать размер аррая ";
    cin >> size_of_arr;
    vector<int> arr(size_of_arr);  //прилось сделать вектор,так как размер должен быть любым  
    // шаблон рандом чисел: чеееек
    random_device rd;  // источник
    mt19937 gen(rd());
    
    //(array):
    uniform_int_distribution<> dist_chicla_of_arr(1, 10);
    for (int i = 0; i < size_of_arr; i++){
        arr[i] = dist_chicla_of_arr(gen);
    }
    
    //(null):
    cout << "сколько null нужно напиши: от 1 до " << (size_of_arr - 1) << ": ";
    cin >> elements_of_null;
    uniform_int_distribution<> dist_index_arr(0, size_of_arr - 1);   // одинаковая вероятность для индексво
    for (int i = 0; i < elements_of_null; i++) {
        int index_random = dist_index_arr(gen);
        arr[index_random] = -1;
    }
    

    cout << "\nваш сгенерированны массив, месье: \n";
    for (int i = 0; i < size_of_arr; i++) {   //показываем арр челу
        if (arr[i] == -1) {
            cout << "null ";
        }
        else {
            cout << arr[i] << " ";
        }
    }
    
    // find часто встречающее
    for (int i = 0; i < size_of_arr; i++) {
        int how_much;
        how_much = 0;
        if (arr[i] == -1) {
            continue;
        }

        for (int j = i; j < size_of_arr; j++){
            if (arr[i] == arr[j]) {
                how_much++;
            }
        }

        if (how_much > current_max) {
            current_max = how_much;
            ans_max = arr[i];
        }

    }
    // replacе  gooooo
    for (int i = 0; i < size_of_arr; i++) {
        if (arr[i] == -1) {
            arr[i] = ans_max;
        }
    }

    // 
    cout << "\nanswer cooked: \n";
    for (int i = 0; i < size_of_arr; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}