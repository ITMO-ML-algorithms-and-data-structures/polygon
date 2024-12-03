#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <sstream>
#include <unordered_map>

void countRepeat(const std::string& input, std::ostringstream& output) {
    std::string word; //40 bytes
    std::istringstream stream(input); 
    std::vector<std::string> begin_list;// n*40 bytes
    std::vector<int> end_list;
    

    // Читаем числа из входной строки и добавляем их в begin_list
    while (stream >> word) { 
        begin_list.push_back(word); 
    }
    
    std::unordered_map<std::string, int> countRep;

    // Подсчитываем количество повторений каждого элемента
    for (const std::string& num : begin_list) {//n*44 bytes
        countRep[num]++;
    }
    
    // Заполняем end_list количеством повторений каждого элемента
    for (std::string& num : begin_list) {
        if (countRep.find(num) != countRep.end()) {
            end_list.push_back(countRep[num]); //n*4 bytes
        }
    }

    // Вывод конечного списка с количеством повторов
    for (int num : end_list) {
        output << num << " ";
    }
}

void testCountRepeat() {
    {
        std::ostringstream output;
        countRepeat("Orange Red Green Orange", output);
        assert(output.str() == "2 1 1 2 ");
        std::cout << "PASSED" << std::endl;
    }
    {
        std::ostringstream output;
        countRepeat("", output);
        assert(output.str() == "");
        std::cout << "PASSED" << std::endl;
    }
    {
        std::ostringstream output;
        countRepeat("11 klk .,", output);
        assert(output.str() == "1 1 1 ");
        std::cout << "PASSED" << std::endl;
    }
}

int main() {
    testCountRepeat();
    std::ostringstream output;
    countRepeat("gg gg g", output);
    std::cout << output.str();
    //на выходе мы имеем 40 + n*40 + n*44 + n*4 байт где n - кол-во слов на входе
    return 0;
}
