#ifndef Count_vectorizer_tests_h
#define Count_vectorizer_tests_h
#include "Count_vectorizer.h"
class Count_vectorize_tests {
  public:
  static void print_matrix(const std::vector<std::vector<int>> &matrix) {

    std::cout<<matrix.size() << " lines in vector." << std::endl;
    for (const auto &line : matrix) {
      for (const auto &unique_word : line) {
        std::cout << unique_word << " ";
      }
      std::cout << std::endl;
    }
  }
  static void test1 () {
    std::vector<std::string> words {
      "Hello world !",
      "Hello",
      "world",
      "!"
    };
    std::vector<std::vector<int>> matrix = Count_vectorizer::count_vectorizer(words);
    std::cout<< "Test 1. С примера в таблице" << std::endl;
    print_matrix(matrix);
    std::cout<< std::endl;
  }
  static void test2 () {
    std::vector<std::string> words {
      "Hello",
    };
    std::vector<std::vector<int>> matrix = Count_vectorizer::count_vectorizer(words);
    std::cout<< "Test 2.  просто одно слово" << std::endl;
    print_matrix(matrix);
    std::cout<< std::endl;
  }
  static void test3() {
    std::vector<std::string> strings = {
        "duplicate words words",
        "test test",
        "test duplicate words"
    };

    std::vector<std::vector<int>> matrix = Count_vectorizer::count_vectorizer(strings);
    std::cout << "Test 3. разные слова в разных последовательностях" << std::endl;
    print_matrix(matrix);
    std::cout << std::endl;
  }
  static void test4() {
    std::vector<std::string> strings = {""};
    std::vector<std::vector<int>> matrix = Count_vectorizer::count_vectorizer(strings);
    std::cout << "Test 4. пустая строка" << std::endl;
    print_matrix(matrix);
    std::cout << std::endl;
  }
  static void test5 () {
    std::vector<std::vector<int>> matrix = Count_vectorizer::count_vectorizer("data.txt");
    std::cout << "Test 5. пример с гугл таблиц только читаю с файла" << std::endl;
    print_matrix(matrix);
    std::cout << std::endl;
  }
  static void test6 () {
    std::vector<std::vector<int>> matrix = Count_vectorizer::count_vectorizer("dataset.txt");
    std::cout << "Test 6. тест скорости компиляции(хз как это правильно вывести в консоль,но вроде это нужно для проверки скорости так что пофиг)" << std::endl;
    print_matrix(matrix);
    std::cout << std::endl;
  }
  static void tests () {
    test1();
    test2();
    test3();
    test4();
    test5();
  }
};
#endif