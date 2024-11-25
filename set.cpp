#include <iostream>
#include <vector>
#include <stdexcept>
#include <set>
#include <limits>
#include <cassert>
#include <chrono>

class ProductIterator {
public:
    ProductIterator(std::vector<int> elements, int repeat)
        : elements(elements), repeat(repeat), indices(repeat, 0) {}
    bool is_done(){ 
        return done;
    }
    std::vector<int> next() { //n*4 byte
        // Получить следующую комбинацию

        if (is_done()) {
            // Кинуть ошибку, если пользователь попытается вызвать next в случае,
            // когда все комбинации сгенерированны
            throw std::out_of_range("No more combinations");
        }

        // Сгенерировать текущую комбинацию индексов
        std::vector<int> current_combination(repeat);  // O(N) n * 4 byte
        for (int i = 0; i < repeat; ++i) {  // O(N)
            current_combination[i] = elements[indices[i]];
        }

        // Инкрементировать следующий индекс, внутри функции описание
        increment_indices();  // O(N)
        return current_combination;
    }
private:
    std::vector<int> elements;  // Элементы на вход, в нашем случае это [0, 1] //n*4 byte
    int repeat;  // Сколько повторений, в нашем случае это 2^(repeat) 4 byte
    
    // текущее состояние для индексов, его на каждой итерации меняем и по нему ориентируемся, что вернуть
    std::vector<int> indices; //n*4 byte
    bool done = false;  // флаг завершения генерации комбинаций // 1 byte

    void increment_indices() {
        // Изменить индексы, тут лучше на примере. По началу [0, 0, 0, 0, 0] - все нули
        // Потом инкрементируем первый элемент с конца, который N, у нас на вход [0, 1] - то есть 2, по этому сравниваем с ним
        // Если внутри индекса 1 - то мы его зануляем, если внутри индекса 0 - то мы его инкрементируем и больше ничего не делаем
        // Вторая итерация - [0, 0, 0, 0, 1]. Третья итерация - [0, 0, 0, 1, 0]
        for (int i = repeat - 1; i >= 0; --i) {  // O(N / 2) = O(N)
            if (indices[i] + 1 < elements.size()) {
                indices[i]++;  // Тут инкрементируем и больше не идем
                return;
            }
            indices[i] = 0; // Вот здесь вот зануляем
        }

        // Если не нашлось того значения, которое надо инкрементировать, считаем что все комбинации сгенерированы
        done = true;
    }
};


std::set<int> invertToVec(std::vector<std::vector<int>> sets){ //переводим множество векторов в единый вектор
    int n = sets.size(); // 4 byte
    std::set<int> res{}; // n * 4 byte
    for (std::vector<int> vec: sets){
        for (int num: vec){
            res.insert(num);
        }
    }
    return res;
}


bool isCover(std::vector<std::vector<int>> sets, std::vector<int> univers){ //проверка на покрытие
    std::set<int> un_sets = invertToVec(sets); //n * 4 byte
    for (int a_elt: univers) {
        if (un_sets.find(a_elt) == un_sets.end()) {
            return false;
        }
    }
    return true;
}


std::vector<std::vector<int>> cover(std::vector<std::vector<int>>& sets,  std::vector<int>& univers){
    int metric = std::numeric_limits<int>::max(); //4 byte
    const int start_metric = metric; //4 byte
    int N = sets.size(); //4 byte
    std::vector<std::vector<int>> result{{}}; //n*4 byte
    ProductIterator masks_iter({0, 1}, N);
    while (!masks_iter.is_done()) {  // O(2^N)
        std::vector<std::vector<int>> comb = {}; //n*4 byte
        // Получаем следующую маску
        std::vector<int> mask = masks_iter.next();  // O(2*N) = O(N)  //n*4 byte
        for (int i = 0; i < N; i++){
            if (mask[i] == 1){  //на основе маски добавляем определенные комбинации множеств
                comb.push_back(sets[i]);
            }
        }

        int size = comb.size(); //4 byte
        if (isCover(comb, univers) && size < metric){ //находим покрытие, с наименьшим кол-вом множеств
            metric = size;
            result = comb;
        }
    }
    if (metric == start_metric || sets.size() == 0 || univers.size() == 0){ //ошибка
        std::cout << "Cover is impossible\n";
        std::vector<std::vector<int>> error{{}};
        return error;
    }
    else{
        return result;
    }
}
//Общая асимптотика: O(2^N), память: 6(n*4) + 21 byte = n*24 + 21 byte

void time(){ //данные для постройки графика
    std::vector<double> counter;
    std::vector<std::vector<int>> sets{{1, 2},{2, 3},{3, 4},{4, 5},{5, 6},{6, 7},{7, 8},{8, 9},{9, 10},{10, 11},{11, 12}, {12, 13}, {12, 13}, {12, 13}, {12, 13}, {12, 13}, {12, 13}, {12, 13}, {12, 13}, {12, 13}, {12, 13}, {12, 13}}; 
    std::vector<int> univers{1,2};
    for (int i = 5; i <= 20; i++){
        std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now(); //начало подсчета времени
        std::vector<std::vector<int>> temp_set = std::vector<std::vector<int>>(begin(sets), end(sets)- (20-i));
        cover(temp_set, univers);
        std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now(); //конец подсчета времени
        std::chrono::duration<double> duration = end - start;
        counter.push_back(duration.count());
    }
    for (double el: counter){
        std::cout << el << ' ';
    }
}

int main(){
    time();
    std::cout << '\n';
    //базовое задание
    std::vector<std::vector<int>> sets{{1, 2}, {2, 3}, {3, 4}}; 
    std::vector<int> univers{1,2,3};
    std::vector<std::vector<int>> res{{1, 2}, {2, 3}};
    std::vector<std::vector<int>> res1{{1, 2}, {3, 4}};
    assert(cover(sets, univers) == res || cover(sets, univers) == res1);
    std::cout << "Test base passed\n";

    //более сложное задание
    std::vector<std::vector<int>> sets_h{{1, 4}, {2, 3}, {3, 4}, {1, 2}};
    std::vector<int> univers_h{1,2,3,4};
    std::vector<std::vector<int>> res_h{{3, 4}, {1, 2}};
    std::vector<std::vector<int>> res_h1{{1, 4}, {2, 3}};
    assert(cover(sets_h, univers_h) == res_h || cover(sets_h, univers_h) == res_h1);
    std::cout << "Test comp passed\n";

    //нет возможности покрыть
    std::vector<std::vector<int>> sets_im{{1, 2}, {2, 3}, {3, 4}}; 
    std::vector<int> univers_im{1,2,5};
    std::vector<std::vector<int>> res_im{{}};
    assert(cover(sets_im, univers_im) == res_im);
    std::cout << "Test error passed\n";

    //пустое множество
    std::vector<std::vector<int>> sets_emp{{}}; 
    std::vector<int> univers_emp{};
    assert(cover(sets_emp, univers_emp) == res_im);
    assert(cover(sets, univers_emp) == res_im);
    std::cout << "Test empty passed\n";        

    //Проверка на максимальное кол-во элементов
    //генерация 25 множеств и 50 значений
    // std::vector<std::vector<int>> sets_big{};
    // std::vector<int> un_big{};
    // std::vector<int> temp_set{};
    // int check = 0;
    // for (int i = 0; i <= 50; i++){
    //     un_big.push_back(i);
    //     if (check < 2){
    //         temp_set.push_back(i);
    //         check++;
    //     }
    //     else{
    //         sets_big.push_back(temp_set);
    //         temp_set = {};
    //     }
        
    // }
    // assert(cover(sets_big, un_big) == sets_big);
    // std::cout << "Test big passed";

    return 0;
}
