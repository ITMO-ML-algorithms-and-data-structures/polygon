#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int max_rectangle(vector <vector <int>> &matrix){
    // Память: O(row * col)
    // Время: O(row * col)

    vector <vector<int>> temp = matrix; // O(row * col) + O(row * col) - выделение памяти под вектор и копирование элементов
    int row = matrix.size(); // O(1) + O(1) - выделение памяти и присваивание
    int col = matrix[0].size(); // O(1) + O(1) - выделение памяти и присваивание

    for (int r = 1; r < row; r++){ // O(row)
        for (int c = 0; c < col; c++){ // O(col)
            // Операции внутри цикла: O(1)
            if (matrix[r][c] == 1) temp[r][c] += temp[r-1][c]; // O(1) + O(1) - сравнение и сложение + присваивание
            else temp[r][c] = 0; // O(1) + O(1) - сравнение + присваивание
        }
    }

    vector <int> test; // O(1) - выделение памяти под пустой вектор
    int max_size = 0; // O(1) + O(1) - выделение памяти и присваивание
    for(int j = 0; j < row; j++){ // O(row)
        for (int i = 0; i < col; i++){ // O(col)
            if (temp[j][i]){ // O(1) + O(1) - доступ к элементу и сравнение
                // left
                int kk = 1; // O(1) + O(1) - выделение памяти и присваивание
                int ind_l = i; // O(1) + O(1) - выделение памяти и присваивание
                int ind_r = i; // O(1) + O(1) - выделение памяти и присваивание

                while(ind_l > 0){ // В худшем случае суммарно O(col) для каждой строки
                    if (temp[j][ind_l - 1]){ // O(1) + O(1) - доступ к элементу и сравнение
                        if (temp[j][ind_l - 1] >= temp[j][i]){ // O(1) + O(1) - доступ к элементам и сравнение
                            kk++; // O(1) + O(1) - инкремент и присваивание
                            ind_l--; // O(1) + O(1) - декремент и присваивание
                        }
                        else break; 
                    }
                    else break;
                }
                // right
                while(ind_r + 1 < col){ // В худшем случае суммарно O(col) для каждой строки
                    if (temp[j][ind_r + 1]){ // O(1) + O(1) - доступ к элементу и сравнение
                        if (temp[j][ind_r + 1] >= temp[j][i]){ // O(1) + O(1) - доступ к элементам и сравнение
                            kk++; // O(1) + O(1) - инкремент и присваивание
                            ind_r++; // O(1) + O(1) - инкремент и присваивание
                        }
                        else break;
                    }
                    else break;
                }
                if (kk * temp[j][i] > max_size) max_size = kk * temp[j][i]; // O(1) + O(1) - умножение, сравнение и присваивание
            }
            else test.push_back(0); // O(1) амортизированно, но может вызывать перераспределение памяти
        }
    }

    return max_size; // O(1) - возврат значения
}

int main(){ // O(1)
    vector <vector<int>> ass = {{1, 0, 1, 0, 0},
                                {1, 0, 1, 1, 1},
                                {1, 1, 1, 1, 1},
                                {1, 0, 0, 1, 0}}; // O(1) + O(row * col) - выделение памяти и инициализация
    cout << "Answer: " << max_rectangle(ass); // O(row * col) - вызов функции

}
