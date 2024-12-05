#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

template <typename Iter> void gnome_sort(Iter first, Iter last) {
  // Gnome sort O(n^2)
  auto cur = first;
  while (cur + 1 != last) {

    if (*cur <= *(cur + 1)) {
      cur++;
    } else {
      std::swap(*cur, *(cur + 1));
      cur--;
    }
  }
}
template <typename Iter> void bin_sort(Iter first, Iter last) {}
template <typename Iter> void radix_sort(Iter first, Iter last) {}

template <typename T> void print_vec(const std::vector<T> v) {
  for (auto i : v) {
    std::cout << i << '\t';
  }
  std::cout << std::endl;
}
int main() {
  std::vector<int> vec = {
      3, 6, 1, 3, 56, 78, 9, 12, 24, 5,

  };
  void (*sort)(std::vector<int>::iterator, std::vector<int>::iterator) =
      gnome_sort<std::vector<int>::iterator>;

  print_vec(vec);
  sort(vec.begin(), vec.end());
  print_vec(vec);
}
