// Ежов Дмитрий 471242
// Лаба 3 
// Перемешать массив сложность HARD

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <map>
#include <random>
#include <vector>
template <typename T> void std_shuffle(T *arr, std::size_t size) {
  std::shuffle(arr, arr + size, *new std::mt19937());
}

template <typename T> void shuffle(T *arr, std::size_t size, size_t iters = 1) {
  for (size_t iter = 0; iter < iters; ++iter)
    for (size_t i = 0; i < size; ++i) {
      std::swap<T>(*(arr + i), *(arr + rand() % size));
    }
}

template <typename T> void shuffle(T *first, T *last, size_t iters = 1) {
  for (size_t iter = 0; iter < iters; ++iter)
    for (T *i = first; i != last; i++) {
      std::swap<T>(*i, *(first + rand() % (last - first)));
    }
}

template <typename T, typename RndGen>
void shuffle(T *arr, std::size_t size, RndGen &gen,
             std::uniform_int_distribution<T> *dist = nullptr,
             size_t iters = 1) {
  if (dist == nullptr)
    dist = new std::uniform_int_distribution<T>(0, size - 1);
  for (size_t iter = 0; iter < iters; ++iter)
    for (size_t i = 0; i < size; ++i) {
      std::swap<T>(*(arr + i), *(arr + (*dist)(gen)));
    }
}

template <typename T, typename RndGen>
void shuffle(T *first, T *last, RndGen &gen,
             std::uniform_int_distribution<T> *dist = nullptr,
             size_t iters = 1) {
  if (dist == nullptr)
    dist = new std::uniform_int_distribution<T>(0, last - first - 1);
  for (size_t iter = 0; iter < iters; ++iter)
    for (T *i = first; i != last; i++) {
      std::swap<T>(*i, *(first + (*dist)(gen)));
    }
}

template <typename T, typename RndGen = std::default_random_engine>
void shuffle(std::vector<T> v, RndGen &gen = *new std::default_random_engine,
             std::uniform_int_distribution<T> *distr = nullptr,
             size_t iters = 1) {
  if (distr == nullptr)
    distr = new std::uniform_int_distribution<T>(0, v.size() - 1);
  for (size_t iter = 0; iter < iters; ++iter)
    for (size_t i = 0; i < v.size(); ++i) {
      std::swap<T>(v[i], v[(*distr)(gen)]);
    }
}
void printarr(int *arr, std::size_t size) {
  for (std::size_t i = 0; i < size; i++)
    std::cout << arr[i] << '\t';
  std::cout << std::endl;
}
template <typename T> bool is_shuffle(T *arr, size_t size, T *shuffled_arr) {
  if (arr == shuffled_arr)
    return false;
  std::map<T, size_t> marr, mshuffled_arr;
  for (size_t i = 0; i < size; i++) {
    marr[*(arr + i)]++;
    mshuffled_arr[*(shuffled_arr + i)]++;
  }
  if (marr == mshuffled_arr)
    return true;
  return false;
}

int main() {
  srand(time(NULL));
  size_t size = 10;
  int arr[size];
  for (size_t i = 0; i < size; ++i)
    arr[i] = rand() % 100;

  int copy_arr[size];
  std::copy(arr, arr + size, copy_arr);
  std::mt19937 gen(rand());
  {
    shuffle(copy_arr, size);
    assert(is_shuffle(arr, size, copy_arr));

    shuffle(copy_arr, copy_arr + size);
    assert(is_shuffle(arr, size, copy_arr));

    shuffle(copy_arr, size, gen);
    assert(is_shuffle(arr, size, copy_arr));

    shuffle(copy_arr, copy_arr + size, gen);
    assert(is_shuffle(arr, size, copy_arr));

    std::vector<int> v(size);
    std::copy(arr, arr + size, v.begin());
    std::vector<int> vc(size);
    std::copy(copy_arr, copy_arr + size, vc.begin());
    shuffle(vc);
    assert(is_shuffle(&v[0], size, &vc[0]));
  }
}
