#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <cassert>

std::vector<int> counter(const std::string arr[], const int size){  //функция, считающая количество повторений элемента в списке

    std::vector<int> out(size, 0); //O(N)

    std::unordered_map<std::string, int> quantities_map; //O(1)

    for(int i = 0; i < size; i++){ //O(N)

        std::string word = arr[i]; //O(1+1+1) * O(N)

        if (quantities_map.find(word) == quantities_map.end()){ //O(1+1+1)

                quantities_map[word] = 1; //O(1+1)

        }
        
        else{

            quantities_map[word] += 1; //O(1+1)

        }
    }

    for(int i = 0; i < size; i++){ //O(N)

        out[i] = quantities_map[arr[i]]; //O(1+1+1)

    } // заполняет вектор, заменяя каждый элемент на количество его повторений

    return out;

}

int main(){

    const std::string arr[] = {"Red", "Green", "Yellow", "Yellow", "Yellow", "Red", "White", "Black", "Black", "Yellow"}; //O(1+1+1)
    const int size = sizeof(arr)/sizeof(arr[0]);//O(1+1+1)

    auto res_matrix = counter(arr, size); //O(1=1)
    for (int i = 0; i < res_matrix.size(); i++) { //O(N), печатаем вектор
        std::cout << " " << res_matrix[i];
    }

    return 0;
}

