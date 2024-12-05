#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int max_rectangle(vector <vector <int>> &matrix){
    
    vector <vector<int>> temp = matrix;
    int row = matrix.size(), col = matrix[0].size();

    for (int r = 1; r < row; r++){
        for (int c = 0; c < col; c++){
            if (matrix[r][c] == 1) temp[r][c] += temp[r-1][c];
            else temp[r][c] = 0;
        }
    }

    vector <int> test;
    int max_size = 0;
    for(int j = 0; j < row; j++){
        for (int i = 0; i < col; i++){
            
            if (temp[j][i]){
                // left
                int kk = 1, ind_l = i, ind_r = i;
                while(ind_l > 0){
                    if (temp[j][ind_l - 1]){
                        if (temp[j][ind_l - 1] >= temp[j][i]){
                            kk++;
                            ind_l--;
                        }
                        else break;
                    }
                    else break;
                }
                // right
                while(ind_r + 1 < col){
                    if (temp[j][ind_r + 1]){
                        if (temp[j][ind_r + 1] >= temp[j][i]){ 
                            kk++;
                            ind_r++;
                        }
                        else break;
                    }
                    else break;
                }
                if (kk * temp[j][i] > max_size) max_size = kk * temp[j][i];
            }
            else test.push_back(0);
        }
    }

    return max_size;
}

 int main(){
    vector <vector<int>> ass = {{1, 0, 1, 0, 0},   
                                {1, 0, 1, 1, 1},    
                                {1, 1, 1, 1, 1},    
                                {1, 0, 0, 1, 0}};   
    cout << "Answer: " << max_rectangle(ass);
    
 }