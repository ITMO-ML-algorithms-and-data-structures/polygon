/*
Как установить mlpack читать тут: https://www.mlpack.org/doc/quickstart/cpp.html

Компиляция программы на mac m1:
g++-14 -O3 -std=c++17 -I/opt/homebrew/include -L/opt/homebrew/lib feature_selection.cpp -o ./main -larmadillo -fopenmp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>

// библиотеки которые необходи установить. Читать тут: https://www.mlpack.org/download.html
#define MLPACK_PRINT_INFO
#define MLPACK_PRINT_WARN
#include <mlpack.hpp>
#include <mlpack/methods/linear_regression/linear_regression.hpp>

// Файл в этой же папке, который я написал для задачи. Пока он обучает модель (черный ящик)
// и возвращает метрику качества (RMSE по умолчанию)
#include "modelling.cpp"


void generate_combi_and_train(arma::mat& dataset,float& result_score,float& best_score,
    std::vector<int>& fichi,const std::vector<int>& nums, std::vector<int>& combination, int start) {
    // если список удаляемых фич пуст (комбинация) или наоборот из всех фич, смысла проверять нет
    if (!combination.empty() && nums.size() != combination.size()) {
            // создаем датасет и удаляем нужные столбцы
            arma::mat drop_dataset = drop_columns(dataset, combination);
            //считаем метрику, искомый столбец второй с конца, айди последний
            float score = evaluate_dataset(drop_columns(dataset, combination), drop_dataset.n_rows - 2,
                drop_dataset.n_rows - 1);
            // проверяем подходит ли под условия задачи
            if (-0.1 * best_score <= score - best_score && score - best_score <= best_score * 0.1
                && fichi.size() <= combination.size()) {
                result_score = score;
                fichi = combination;
            }
            // генерируем все возможные комбинации удаляемых столбцов, чтобы сложность алгоритма была большой
            // можно удалить do_while и код будет в тысячи раз быстрее с тем же самым результатом
        // сложность O(n!)
    }
    // создаем рекурсивно все возможные комбинации столбцов для удаления разной длин
    // сложность O(2^n) (сумма чисел сочетаний)
    for (int i = start; i < nums.size(); ++i) {
        count++;
        combination.push_back(nums[i]);
        generate_combi_and_train(dataset,result_score, best_score, fichi, nums, combination, i + 1);
        combination.pop_back();
        }
}


int feature_selection() {
    // path to *.csv file
    // Будьте осторожны с путем. Сейчас вы в папке, но файл находится на уровень выше
    const char* path = "../data/WineQT.csv";

    // Код, которым можно считать набор данных, который дальше требуется анализировать
    arma::mat dataset;
    if (!mlpack::data::Load(path, dataset)) {
        // not fatal and not transpose (если false, false, mlpack::data::FileType::AutoDetect)
        throw std::runtime_error("Could not read *.csv!");
    }

    std::vector<int> nums; //создаем индексы всех столбцов
    for (int i = 0; i < dataset.n_rows - 2; i++) {
        nums.push_back(i);
    }
    //создаем вектор для хранения комбинаций столбцов
    std::vector<int> combination;
    //считаем лучший результат
    float best_score = evaluate_dataset(dataset, 11, 12);
    float result_score = 10;
    std::vector<int> fichi;
    //запускаем перебор всех комбинаций
    generate_combi_and_train(dataset, result_score, best_score,fichi, nums, combination, 0);

    //выводим все данные
    std::cout << "best score: " << best_score << std::endl;
    std::cout << "result score: " << result_score << std::endl;
    std::vector<int> features;
    std::cout << "features: " << std::endl;
    // т.к на выходе у нас фичи которые мы удалили, меняем их на те которые оставляем
    for (int i = 0; i < dataset.n_rows - 2; i++) {
        if (std::find(fichi.begin(), fichi.end(), i) == fichi.end() ) {
            features.push_back(i);
        }
    }
    //выводим фичи
    for (auto val : features) {
        std::cout << " " << val;
    }
    std::cout << std::endl;
    return 0;
}


void run_tests() {
    feature_selection();
}

//тут чисто код для для проверки правильности перебора и удаления столбцов
void run_tests_for_modelling() {
    const char* path = "../data/WineQT.csv";

    // Код, которым можно считать набор данных, который дальше требуется анализировать
    arma::mat dataset;
    if (!mlpack::data::Load(path, dataset)) {
        // not fatal and not transpose (если false, false, mlpack::data::FileType::AutoDetect)
        throw std::runtime_error("Could not read *.csv!");
    }
    std::vector<int> nums = {0, 2, 3, 4, 5, 6, 7, 8, 9}; // сюда пишем фичи для удаления
    dataset = drop_columns(dataset, nums);
    float score = evaluate_dataset(dataset, dataset.n_rows - 2,
                dataset.n_rows - 1);
    //получаем скор(проверял, все совпадает)
    std::cout << score << std::endl;
}

int main() {
    unsigned int start = clock();
    run_tests();
    std::cout << "ВРЕМЯ РАБОТЫ: "<<(clock() - start) / CLOCKS_PER_SEC << std::endl;
    return 0;
}













