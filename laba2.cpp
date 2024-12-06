#include <iostream>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

// Создаю функцию full_nul, которая принимает ссылку на вектор arr и возвращает вектор целых чисел 
//каждый элемент занимает 4 байта; память для arr = 4n байт
vector <int> full_null(vector<int>& arr){ // словарь для каждого уникального элемента добавляется целое знач + частота -> 8+4=12байт (на каждую пару)
    // Создаю пустой словарь num_to_num_amount(ключами будут уникальные элементы из arr, а значениями — количество их вхождений)
    map<int, int> num_to_num_amount;
    // для каждого элемента x из arr:
    for (int& x : arr) { // память дополнительно не выделяется 
        // допустим -1 = null
        if (x != -1) { 
             num_to_num_amount[x] += 1; // если х есть в num_to_num_amount
        }
    }
    //Найти самый часто встречаемый элемент
    //создаю две переменные
    int freq_num = -1;//хранит наиболее часто встречающийся элемент 4 байта
    int max_freq = 0;//хранит максимальную частоту встречаемости 4 байта
    //цикл по словарю
    for (const auto& pair : num_to_num_amount){
        if(pair.second > max_freq){ // проверяю, если значение (частота) текущей пары больше, чем max_freq
            max_freq = pair.second;//если условие выполняется, обновляю max_freq и записываю текущий элемент (pair.first) как freq_num
            freq_num = pair.first;
        }
    }
    // Заменить пропуски на частый элемент
    //цикл по исходному вектору, который проходит по индексам всех элементов в векторе arr 4 байта [idx]
    for(size_t idx = 0; idx < arr.size(); ++ idx){
        if(arr[idx] == -1){
            arr[idx] = freq_num;
        }
    }
    return arr;
}

// tests 
//в каждом тесте использую assert, чтобы проверить, что результат работы функции соответствует ожидаемому результату.

// test case 1
// нет null  4*5=20 байт
void test_no_nulls() {
    vector<int> arr{1, 2, 3, 4, 5};
    vector<int> expected{1, 2, 3, 4, 5};
    assert(full_null(arr) == expected);
    cout << "test_no_null is nice" << endl;
}

// test case 2   вектор arr с 5 элементами и expectrd с 5 элементами - каждый занимает 20 байт
// два одинаковых числа с большей частотностью
void test_equal_frequencies() {
    vector<int> arr{1, 2, -1, 1, 2};
    vector<int> expected{1, 2, 1, 1, 2}; // Любое из 1 или 2 может быть подставлено, но здесь 1 встречается первым
    assert(full_null(arr) == expected);
    cout << "test_equal_frequencies is nice" << endl;
}


// test case 3  вектор arr из 3 элемнтов и expected из 3 элементов 4*3 = 12 байт
//  только null
void test_all_nulls() {
    vector<int> arr{-1, -1, -1};
    vector<int> expected{-1, -1, -1}; // Программа не сможет заменить, так как нет других чисел
    assert(full_null(arr) == expected);
    cout << "test_all_nulls is nice" << endl;
}


// test case 4
// очень длинный массив и все одинаковые числа     4 *10000 = 40000 байт
void test_large_vector(){
    int size = 10000;
    vector<int> arr(size, 5);  //все элементы равны 5
    for (int i = 0; i < size; i += 10) {
        arr[i] = -1;  // заменю каждый 10-й элемент на -1
    }
    vector<int> expected(size, 5);  
    assert(full_null(arr) == expected);
    std::cout << "test_large_vector is nice" << std:: endl;
}

//test case 5
//один элемент   4 байта 
void test_one_element() {
    vector<int> arr{10}; 
    vector<int> expected{10};

    assert(full_null(arr) == expected);
    
    
    cout << "test_one_element is nice" << endl;
}

//запускаю все тесты 
int main(){
    test_no_nulls();
    test_equal_frequencies();
    test_all_nulls();
    test_large_vector();
    test_one_element();

    return 0;
}


