#include <iostream>
#include <vector>

unsigned short find_most_frequent(std::vector<unsigned short>& data) { //unsigned short - 2 байта, всего n элементов сам std::vector - 24 байт, итого 2*n + 24 байт
    unsigned short frequency[30000]; //unsigned short - 2 байта, всего 30000 элементов, итого 2*30000 = 60000 байт
    unsigned short most_frequent_value = 0; //unsigned short - 2 байта
    unsigned short max_count = 0; //unsigned short - 2 байта

    for (unsigned short num = 0; num < data.size(); num++) {
        if (data[num] != 0) {
            frequency[data[num]]++; 
            if (frequency[data[num]] > max_count) {
                max_count = frequency[data[num]];
                most_frequent_value = data[num];
            }
        }
    }

    return most_frequent_value;
}

void SimpleImputer(std::vector<unsigned short>& data) {
    unsigned short most_frequent_value = find_most_frequent(data); //unsigned short - 2 байта

    for (unsigned short& num : data) {
        if (num == 0) {
            num = most_frequent_value;
        }
    }
}

//всего выходит: 2*n + 24 + 60000 + 2 + 2 + 2 = 2*n + 60030 байт
//можем также подсчитать память временных переменных (например num в обеих функциях), обе unsigned short, то есть 2 + 2 = 4 байта, 
//вместе с временными переменными получаем 2*n + 60030 + 4 = 2*n + 60034 байт

//теперь подсчитаем в небольшом примере
int main() {
    std::vector<unsigned short> data = {5, 0, 5, 0, 3, 4, 1, 0, 1, 4, 7, 0, 3, 6, 2, 9, 102, 300, 10000, 0, 1, 2, 5, 7, 1}; 
    //тип unsigned short - 2 байта, всего 25 элементов, сам std::vector занимает 24 байта, итого: 2*25 + 24 = 74 байта

    std::cout << "Before processing: ";
    for (unsigned short num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    SimpleImputer(data);

    std::cout << "After processing: ";
    for (unsigned short num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

//воспользуемся ранее выведенной формулой: 2*n + 60030 + 4, выходит 2*25 + 60030 + 4 = 60084 байта 
