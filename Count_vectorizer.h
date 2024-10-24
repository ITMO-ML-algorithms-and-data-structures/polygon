#ifndef Count_vectorizer_h
#define Count_vectorizer_h
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <unordered_map>
#include <fstream>
class Count_vectorizer {
  public:
  //функция для разделения строки в массив по пробелу 
  static std::vector<std::string> split_string(const std::string &str, char delim) {
    std::vector<std::string> splitted_string; // 24 байта
    int start = 0,end; // 4 байта у start и 4 у end
    while ((end = str.find(delim,start)) != std::string::npos) { 
      if (end != start) splitted_string.push_back(str.substr(start, end - start));// тут мы каждый раз удваивам емкость вектора и добавляем 32 байта для строки и + количество в строке
      start = end + 1;
    }
    if(str[str.size() -1] != ' ') splitted_string.push_back(str.substr(start));
    // то-есть мы выделяем 8 байт для end/start и каждый елемент в векторе (32 байта + i) * n гду i это кол-во символов а n это колво елементов в векторе
    // В итоге  8 + (32  + i) * n байта
    return splitted_string;
  }
  // функция с вектором в качестве аргумента 
  static std::vector<std::vector<int>> count_vectorizer(const std::vector<std::string> &strings_ar) {
    std::vector<std::vector<int>> table; //  24 байта на приколы для внешнего вектора, так как внутренний еще не создан
    std::unordered_map<std::string,int> unique_index; // 40 байт
    int index = 0; // 4
    for (const std::string &outer_string : strings_ar){ // рефференс 8 байт
      std::vector<std::string> splitted_string = split_string(outer_string,' '); // 24 вектор и (32 + i) * n где n кол-во елем и i символы в строке
      for (const std::string &inner_string : splitted_string) { // рефференс 8 байт
        if(inner_string == "") break;
        if(unique_index.find(inner_string) == unique_index.end()) {
          unique_index[inner_string] = index; // 32 за ключ и 4 за значение за каждый елемент
          index++;
        }
        }
      }
    table.resize(strings_ar.size(), std::vector<int>(index, 0)); // для внутреннего index * 4 (кол-во интов на размер инта). то есть strings_ar.size() * (index * 4)
    for (int i = 0; i < strings_ar.size();i++) { // 4 байт на инт
      std::vector<std::string> str = split_string(strings_ar[i],' '); // 24 вектор и (32 + i) * n где n кол-во елем и i символы в строке
      for(const std::string &s : str) { // на рефференс 8 байт
        if (unique_index.find(s) != unique_index.end()) {
          table[i][unique_index[s]]++; 
        }
      }
    }
    // (table + unique_index + index + i) = 68 байт потом 24 байт на рефференсы. ((32 + i) * n *) * 2 за создание двух массивов (только не знаю что делать с 16 байтами которые в функции, которую мы используем), потом (36 * кол-во) для мапы. потом strings_ar.size() * (index * 4) для таблицы.
    // В итоге 68 + ((32 + i) * n *) * 2 + (36 * кол-во) + strings_ar.size() * (index * 4)
    return table;
  }
  // функция с названием файла в качестве аргумента
  static std::vector<std::vector<int>> count_vectorizer(const std::string &filename) {
    std::ifstream file_read(filename); //тут в зависимости от файла. например у файла data.txt 472 байта
    std::vector<std::vector<int>> table; // 24 байта
    std::unordered_map<std::string,int> unique_index; // 40 байт
    std::string line; // 32
    int index = 0; // 4
    int count_of_lines = 0; // 4
    while (std::getline(file_read,line)) { // тут 32 байта за каждую строку 
      count_of_lines++;
      std::vector<std::string> splitted_string = split_string(line,' '); // 24 вектор и (32 + i) * n где n кол-во елем и i символы в строке
      for (const std::string &inner_string : splitted_string) { // просто 8 байт на рефференс
        if(inner_string == "") break;
        if(unique_index.find(inner_string) == unique_index.end()) {
          unique_index[inner_string] = index;// 32 за ключ и 4 за значение за каждый елемент
          index++;
        }
        }
    }
    table.resize(count_of_lines, std::vector<int>(index, 0)); // для внутреннего index * 4 (кол-во интов на размер инта). то есть count_of_lines * (index * 4)
    std::string line_1; // 32
    std::ifstream file_read1(filename); //тут в зависимости от файла. например у файла data.txt 472 байта
    for (int i = 0; i < count_of_lines;i++) { // 4 за i
      std::getline(file_read1,line_1); // тут 32 байта за каждую строку
      std::vector<std::string> str = split_string(line_1,' '); // 24 вектор и (32 + i) * n где n кол-во елем и i символы в строке
      for(const std::string &s : str) { // за рефференс 8 байта
        if (unique_index.find(s) != unique_index.end()) {
          table[i][unique_index[s]]++;
        }
      }
    }
    // Размер файла  156 байт(table + unique_index + line + insdex + count_of_lines + i + line_1 + 16 2реффа) + (32 байта * количество строк) * 2 + ((32 + i) * n *) * 2 за создание двух массивов + 46 * кол-во елементов в мапе
    // В итоге 156 + (32 байта * количество строк) * 2 + ((32 + i) * n *) * 2 + (46 * кол-во елементов)
    return table;
  }
};
#endif