#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// я понимаю что класс тут избыточен, но так тестить удобнее
class ArrayProcessor {
   public:
    // работает за амортизированное O(N), тк по вектору проходим один раз
    // и далее какое то колво раз за O(1) меняем nan'ы
    void fillna_mean(std::vector<int>& array) {
        int sum = 0;
        std::vector<size_t> null_elements;

        for (size_t i = 0; i < array.size(); ++i) {
            int num = array[i];
            if (num != -1) {
                sum += num;
            } else {
                null_elements.push_back(i);
            }
        }

        // явное округление вниз
        int mean = static_cast<int>(sum / array.size());

        // https://en.cppreference.com/w/cpp/container/vector/operator_at
        for (size_t i : null_elements) {
            array.at(i) = mean;
        }
    }

    std::vector<int> read_array() {
        std::string input;
        std::getline(std::cin, input);
        std::stringstream ss(input);
        std::string item;
        std::vector<int> array;

        // за O(N) тк не было условия про чтение, только про сам алгоритм
        while (std::getline(ss, item, ',')) {
            item.erase(std::remove_if(item.begin(), item.end(), isspace), item.end());
            if (item == "null" || item == "none" || item == "nan" || item.empty()) {
                array.push_back(-1);
            } else {
                array.push_back(std::stoi(item));
            }
        }
        return array;
    }
};
