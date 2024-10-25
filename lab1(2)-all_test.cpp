#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <algorithm>


//Тесты
int test_passed = 0;
int test_failed = 0;

void assertEqual(bool condition, const std::string& testName) {
    if (condition) {
        std::cout << "[PASSED]" << testName << "\n";
        test_passed++;
    }
    else {
        std::cout << "[NOT PASSED]" << testName << "\n";
        test_failed++;
    }
}

void report() {
    std::cout << "\nTotal tests passed: " << test_passed << "\n";
    std::cout << "\nTotal tests not passed: " << test_failed << "\n";
}


void test(std::vector<std::string> arr, std::unordered_set<std::string> unique_words) {
    assertEqual((arr.size() <= 10e4), "check number of lines");
    
    for (const auto& str : arr) {
        assertEqual((str.size() <= 10e2), "checking the len of string");
    }
    
    assertEqual((unique_words.size() >= 100), "checking for number of unique");
    report();
}



//Функция подготавливающая файл, убирает лишние пробелы ,чтоб при разделение на оtдельные слова не образовывались пустые строки
std::string prepare(std::string& line) {
    int n = line.size();
    std::string new_line = "";
    for (int i = 0; i < n; i++) {
        if (line[i] == ' ') {
            new_line += line[i];
            i++;
            while (i != n) {
                if (line[i] == ' ') {
                    i++;
                }
                else {
                    new_line += line[i];
                    break;
                }
            }
        }
        else {
            new_line += line[i];
        }
    }
    return new_line;
}


//Считывание данных из сформированного датасета
std::vector<std::string> load_data() {
    std::vector<std::string> data;
    
    std::ifstream file("C:\\Users\\admin\\polygon\\dataset1.csv");
    std::string line;

    while (std::getline(file, line)) {//всего одна строка во всем файле 
        std::istringstream ss(line);
        std::string item;
        
        while (std::getline(ss, item, ',')) {
            item = prepare(item);
            data.push_back(item);
        }
    }

    return data;
}
//функция находящая индекс элемента в set по его значению.
int find_index(const std::unordered_set<std::string>& my_set, const std::string& value) {// Вес в нашем примере: будет еще выделена память ?
    auto it = my_set.begin();//размер поступающей строки (кол-во символов) + до 1е2 (тк строка поступит из set)
    for (int i = 0; it != my_set.end(); ++i) {
        if (*it == value) {
            return i;
        }
        ++it;
    }
    return -1;
}
int main() {
    //std::vector<std::string> arr = { "Hello world !","Hello","world","!" };//На вход 21 байт (кол-во символов ,т.е. О(N)) ,из условия может быть до 1е2*1е4 байт(возможное кол-во строк * возможная длинна каждого слова)
    //std::cout << arr.capacity();4 длина с резервом
    std::vector<std::string> arr = load_data(); // (Если нужно принять данные из сформированного датасета)
    std::vector<std::vector<std::string>> doubl_arr;// двумерный массив для хранения массивов words_in_string (в которых уже разделенные слова)
    std::vector<std::string> words;//для хранения отдельных слов
    for (int i = 0; i != arr.size(); i++) {//+4байта
        std::vector<std::string> words_in_string;
        int pos = 0;//номер позиции пробела в строке; std::cout<<sizeof(pos);//4 байт
        std::string str = arr[i];
        while ((pos = str.find(' ')) != std::string::npos) {
            words_in_string.push_back(str.substr(0, pos)); // добавляем слово до пробела в вектор
            words.push_back(str.substr(0, pos));
            str = str.substr(pos + 1); // обновляем строку
        }
        words.push_back(str); // добавляем последнее слово в вектор
        words_in_string.push_back(str);//после всех добавлений 21 байт (кол-во символов) ,из условия может быть до 1е2*1е4 байт
        doubl_arr.push_back(words_in_string);//после всех добавлений 21 байт (кол-во символов) ,из условия может быть до 1е2*1е4 байт
    }

    std::unordered_set<std::string> set_words(words.begin(), words.end());// 3 элемента, 11 байт ,из условия может быть до 1е2*1е2(кол-во уникальных слов на длинную строки (которая может полностью быть словом))
    for (int j = 0; j < doubl_arr.size(); ++j) { // цикл проходящий по массивам слов входящих в строку +4байта
        std::vector<std::string> results_string(set_words.size(), "0");//3 байта ,может быть до 1е2 байт
        for (int k = 0; k < doubl_arr[j].size(); ++k) { // цикл проходящийся внутри массива строки +4 байта
            int number_str = find_index(set_words, doubl_arr[j][k]); // используем функцию ,чтобы понять индекс этого элемента по множеству и построить все результаты на подобии данного множества
            results_string[number_str] = doubl_arr[j][k]; // заменяем строку ноль на значение строки ,для которой ы должны будем найти количество вхождений
        }
        doubl_arr[j] = results_string;
    }
    test(arr, set_words);

    for (int j = 0; j < doubl_arr.size(); ++j) { // цикл проходящий по массивам слов входящих в строку+4байта
        for (int k = 0; k < doubl_arr[j].size(); ++k) { // цикл проходящийся внутри массива строки +4 байта
            std::vector<int> results(set_words.size(), 0); // создаем вектор где будет хранится сколько раз встречается слово в строке; 4 байта(int) * 3   ,возможно до 1е2 * 4 байта
            //Так как строк 3 в конце будет 4*3*3 <=> 4*O(l)*O(n)
            if (set_words.contains(doubl_arr[j][k])) {//если "ключ" существует ,то считаем 
                ++results[k];
                std::cout << results[k] << ' ';
            }
            else {
                std::cout << results[k] << ' ';
            }
        }
        std::cout << '\n';
    }
}
//Итого на нашем примере: 21+21+21+4+4+4+4+4+3*4*3=133 байт
//Итого если n-кол-во строк ,m-максимальная длинна строки, l-кол-во уникальных слов , 5 - кол-во перменных : 3*O(n*m) + (4 байта *5) + 4*O(l)*O(n).







