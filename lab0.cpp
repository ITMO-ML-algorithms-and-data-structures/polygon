// Найти все подмассивы, которые являются палиндромами
#include <iostream>
#include <vector>
bool palindrome(const std::vector<int> p);

bool palindrome(const std::vector<int> p) {
  int len_p = p.size();
  for (int i = 0; i < len_p; i++) {
    if (p[i] != p[len_p - i - 1]) {
      return 0;
    }
  }
  return 1;
}
int main() {
  std::vector<std::vector<int>> v{{1, 2},         {2, 3, 2}, {1, 2, 1, 2, 1},
                                  {1, 1, 1, 1},   {7, 8, 9}, {7, 8, 9, 8, 7},
                                  {0, 1, 5, 5, 0}};
  int n = v.size();
  int k;
  bool palindrome(const std::vector<int> p);
  for (int i = 0; i < n; i++) {
    if (palindrome(v[i]) == 1) {
      int k = v[i].size();
      for (int j = 0; j < k; j++) {
        std::cout << v[i][j] << " ";
      }
      std::cout << "\n";
    }
  }
}
