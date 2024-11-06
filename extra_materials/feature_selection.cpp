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
    std::vector<int>& fichi,const std::vector<int>& nums, std::vector<int>& combination) {
    // если список удаляемых фич пуст (комбинация) или наоборот из всех фич, смысла проверять нет
    if (!combination.empty() && nums.size() != combination.size()) {
        // создаем датасет и удаляем нужные столбцы
        //O(n * m), где m - кол-во столбцов для удаления
        // память 8 * (n * d) байт, где d-кол-во строк
        arma::mat drop_dataset = drop_columns(dataset, combination);

        //считаем метрику, искомый столбец второй с конца, айди последний
        float score = evaluate_dataset(drop_dataset,
            drop_dataset.n_rows - 2,
            drop_dataset.n_rows - 1); // вроде O(n^2 * d) где d кол-во строк данных

        // проверяем подходит ли под условия задачи O(1)
        if (-0.1 * best_score <= score - best_score && score - best_score <= best_score * 0.1
            && fichi.size() <= combination.size()) {
            result_score = score;
            fichi = combination;
        }
    }
    // создаем рекурсивно все возможные комбинации столбцов для удаления разной длин
    // сложность O(n^n), нормальный перебор был бы 2^n(число сочетаний)
    for (int i = 0; i < nums.size(); ++i) {
        if (std::find(combination.begin(), combination.end(), i) != combination.end()) {
            continue;
        }
        combination.push_back(nums[i]);
        generate_combi_and_train(dataset,result_score, best_score, fichi, nums, combination);
        combination.pop_back();
        }
} // итоговая сложность функции по времени O(n^n * n^2 * d), где n-кол-во фич датасета, а d-кол-во строк
//итоговая сложность функции по памяти 8 * (n * m) байт для подсчета метрики, в остальном используются ссылки на главную ф-цию


int feature_selection() {
    // path to *.csv file
    // Будьте осторожны с путем. Сейчас вы в папке, но файл находится на уровень выше
    const char* path = "../data/WineQT.csv";

    // Код, которым можно считать набор данных, который дальше требуется анализировать
    //память o(n * d)
    arma::mat dataset;
    if (!mlpack::data::Load(path, dataset)) { // O(n)
        // not fatal and not transpose (если false, false, mlpack::data::FileType::AutoDetect)
        throw std::runtime_error("Could not read *.csv!");
    }

    std::vector<int> nums; //создаем индексы всех столбцов для перебора
    for (int i = 0; i < dataset.n_rows - 7; i++) { //O(n)
        nums.push_back(i);
    }

    //создаем вектор для хранения комбинаций столбцов
    std::vector<int> combination;

    //считаем лучший результат
    float best_score = evaluate_dataset(dataset, 11, 12); //вроде O(n^2 * d) где d кол-во строк данных
    // задаем значение result_score = 10 т.к он потом уменьшится
    float result_score = 10;
    //создаем вектор в котором будем хранить лучшую комбинацию
    std::vector<int> fichi;
    //запускаем перебор всех комбинаций
    //сложность подсчитана в самой функции
    generate_combi_and_train(dataset, result_score, best_score,fichi, nums, combination);

    //выводим  ответ
    std::cout << "best score: " << best_score << std::endl;
    std::cout << "result score: " << result_score << std::endl;
    std::vector<int> features;
    std::cout << "features: " << std::endl;
    // т.к на выходе у нас фичи которые мы удалили, меняем их на те которые оставляем
    for (int i = 0; i < dataset.n_rows - 2; i++) { // O(n)
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

//тут чисто код для для проверки правильности перебора,удаления столбцов, подсчета метрики
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
// итоговая сложность алгоритма если взять самый сложный вычислительным момент = O(n^n * n^2 * d)
// память в пике 2 * 8 * n * m, где m-кол-во строк в датасете













