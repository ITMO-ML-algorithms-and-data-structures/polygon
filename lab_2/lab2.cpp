#include <iostream> 
#include <vector>
#include <string>
#include <locale>
#include <stdio.h>
#include <fstream>
#include <unordered_map>

using namespace std; 

// Это функция определяет, являются ли две строки изоморфными medium
//
//
// O(n)
bool is_string_isomorph(string a, string b, int n){
  
//  std::wstring wa(a.begin(), a.end());
//  std::wstring wb(b.begin(), b.end());



  unordered_map< char, char> iso_map; // 4 * n

  for (int i=0; i<n; i++){
    if (iso_map.find(a[i]) == iso_map.end() && iso_map.find(b[i]) == iso_map.end()){
      iso_map[a[i]] = b[i];
      iso_map[b[i]] = a[i];
      
    }
    else{
      if (iso_map[a[i]] != b[i])
        return 0;
    }
    
  }
  
  return true;
}


int main(){
  ifstream fin("input.txt");
  ofstream fout("output.txt");
  int n = 0; // 4 байта
  int test_m = 0; // 4 
  fin >> test_m;
  for (int i = 0; i<test_m; i++){
    fin >> n;

    string a; // 2 * n байта
    string b; // 2 * n байта

    fin >> a >> b;
  
    
    fout << is_string_isomorph(a, b, n) << endl;
    
  }
  fin.close();
  fout.close();
  return 0;
}
