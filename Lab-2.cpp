#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <unordered_map>
using namespace std;
int main(){
    vector<string> rows = {"58", "321", "null", "581", "581", "null","30","71","87","81","null","86","4","null","21","74","117","null","19","90","7","null","34","44","88","54","null","42","84","10","null","86","117","114","44","null","6","80"}; // (24 + n)*l байт; l - количетсво строк, n - длина строки
    vector<int> nums; //24 + 4*n(длина строки) байт
    for (int i = 0; i < rows.size(); i++) //4 байт
    {
        if (rows[i] == "null")
        {
            nums.push_back(0);
        }
        else
        {
            nums.push_back(std::stoi(rows[i]));
        }
    }
    size_t vcsize = nums.size();
    map <int, int> Mymap; // (4 + 4)*n+48байт (n-количество строк)
    for (int i = 0; i<vcsize; i++){ //4 байта
        if (nums[i]>0){
            Mymap[i] = nums[i];
        }
    }
    unordered_map<int, int> frequency; //(4 + 4)*n+56 байт(n-количество строк)
    
    for (const auto& pair :Mymap){
        frequency[pair.second]++;
    }
    
    int mostFrequentValue = 0; //4 байт
    int maxFrequency = 0; //4 байт
    
    for (const auto& pair : frequency){
        if (pair.second > maxFrequency){
            maxFrequency = pair.second;
            mostFrequentValue = pair.first;
        }
    }
    replace(nums.begin(), nums.end(), 0, mostFrequentValue);
    for (const auto& num: nums){
        cout << num << " ";
    }
    
}
