#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

void removeDuplicates(const std::string& input, std::ostringstream& output) {
    std::vector <std::string> begin_list;
    std::istringstream stream(input);
    std::string word;
    std::vector <std::string> end_list;

    //считываем входную строку и закидываем в begin_list
    while (stream >> word) { //O(n)
        begin_list.push_back(word);
    }

    std::unordered_map<std::string, int> uniq_els;

    //пробегаемся по begin_list и заносим в хэш таблицу кол-во повторений каждого элемента
    for (const std::string num : begin_list) { //O(n)
        uniq_els[num]++;
    }
    //выводим элементы без дубликатов
    for (const auto& pair : uniq_els) {//O(n)
        output << pair.first << " ";
    }
}

void testremoveDuplicates() {
    {
        std::ostringstream output;
        removeDuplicates("1 2 2 3", output);
        assert(output.str() == "1 2 3 ");
    }
    {
        std::ostringstream output;
        removeDuplicates("", output);
        assert(output.str() == "");
    }
    {
        std::ostringstream output;
        removeDuplicates("1 2 3 1", output);
        assert(output.str() == "1 2 3 ");
    }
}

int main() {
    std::ostringstream output;
    removeDuplicates("1 2 2 3", output);
    std::cout << output.str();
    //в общем случае O(n)=O(n)+O(n)+O(n)
    //в лучшем O(1) если n=1

    return 0;
}