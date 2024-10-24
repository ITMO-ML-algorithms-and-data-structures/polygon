#include <iostream>
#include <vector>
#include <random>
#include <unordered_set>
#include <ctime>
using namespace std;
 unordered_set<int> massive_sample(const std::vector<int> &massive, int &k) {
  unordered_set<int> set_checker(massive.begin(), massive.end());// 0(n) выделяем память для каждого елемента
  unordered_set<int> unique_massive; // 0(1) просто сделали дифинишн
  if(massive.size() == 0 || k <= 0) return unique_massive; // 0(1) за размер + 0(1) за сравнение + 0(1)
  if (set_checker.size() <= k) { // 0(1) за размер + 0(1) за сравнение
   k = set_checker.size(); // 0(1) + 0(1)  за присваивание и за размера массива
  }
  random_device rd; // 0(1) за присваивание
  mt19937 gen((time(0)));// 0(1) за time(0), а также  0(1) за присваивание конструктору.
  uniform_int_distribution<> distr(0, massive.size() - 1); // тут по 0(1) за: 1)размер -1. 2) за 0. 3) и за вставку в дистрибьюшн
  int random_index; // 0(1) за дифинишн
  while (unique_massive.size() < k) { // 0(1) за размер + 0(1) за сравнение + k за кол-во итераций и надо смотреть какая сложность внутри,
  // а внутри сложность 0(n) или 0(1), так что или 0(k) или 0(n * k)
   random_index = distr(gen);// 0(1) за функцию дистрибьюшена и 0(1) за присваивание
   unique_massive.insert(massive[random_index]); // наверное 0(1) просто как присваение (но я не знаю за сколько оно каждый раз расширяет сет) = 0(1) или 0(n)
  }
  // сложность в худшем случае: 0(n^2), но я не учитываю что рандом число будет часто бить в одинаковые или теже елементы
  // сложность в лучшем случае: 0(1) когда нет елементов вообще или 0(n + k) за создание и за цикл
  // сложность в среднем случаем: 0(n^2) когда есть повторы у рандом чисел и когда мы тыкаемся в сет просто так
  // алгоритм кал, но ничего лучше я не придумал
  return unique_massive;
}
// это просто тест функция (она работает для 1e9, но не работает для ситуаций когда кол-во елементов меньше чем K). я просто не придумал как сделать так,
// чтобы она работала для 3 теста
//  unordered_set<int> massive_sample1(const std::vector<int> &massive, int &k) {
//   unordered_set<int> unique_massive;
//   if(massive.size() == 0) return unique_massive;
//   if(massive.size() < k) k = massive.size();
//   random_device rd;
//   mt19937 gen(static_cast<unsigned int>(time(0)));
//   uniform_int_distribution<> distr(0, massive.size() - 1);
//   int random_index;
//   while (unique_massive.size() < k) {
//    random_index = distr(gen);
//    unique_massive.insert(massive[random_index]);
//   }
//   return unique_massive;
// }
void print_set(unordered_set<int> &input_set) {
 for (const int &elem : input_set) cout << elem << " ";
 cout << endl << endl;
}
int main () {
 vector<int> test1{1,100,10,2}; // тест из примера
 int k1 = 3;
 vector<int> test2{1,2,3,4,5}; // тест со всем массивом
 int k2 = 5;
 vector<int> test3{1,1,1,1,1}; // тест где все елементы одинаковые и к равно размеру массива
 int k3 = 5;
 vector<int> test4{1,2,3,4,5}; // тест где к больше чем количество елементов
 int k4 = 7;
 vector<int> test5{}; // тест с пустым массивом
 int k5 = 1;
 std::vector<int> test6; // тест с пределами
 test6.reserve(1e4);
 for (int  i = 1; i <= 1e4; ++i) {
  test6.push_back(i);
  }
 int k6 = 10;
 unordered_set<int> set1 = massive_sample(test1,k1);
 unordered_set<int> set2 = massive_sample(test2,k2);
 unordered_set<int> set3 = massive_sample(test3,k3);
 unordered_set<int> set4 = massive_sample(test4,k4);
 unordered_set<int> set5 = massive_sample(test5,k5);
 unordered_set<int> set6 = massive_sample(test6,k6);
 cout<<"test 1: from example" << endl << endl;
 print_set(set1);
 cout<<"test 2: full massive" << endl << endl;
 print_set(set2);
 cout<<"test 3: ful massive with equal elements" << endl << endl;
 print_set(set3);
 cout<<"test 4: k bigger than massive size" << endl << endl;
 print_set(set4);
 cout<<"test 5: empty massive" << endl << endl;
 print_set(set5);
 cout<<"test 6: speed test" << endl << endl;
 print_set(set6);
}