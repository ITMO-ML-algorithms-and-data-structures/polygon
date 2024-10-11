#ifndef variant_1_h
#define variant_1_h
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
class Variant_1 {
  public:
  static bool palindrome (const  std::string  &massive) {
    if (massive.size() <= 1) return true;
    for (int i = 0; i < massive.size() / 2; i++) {
      if (massive[i] != massive[massive.size() - i - 1])  return false;
      }
    return true;
  }
  static int binary_search (const std::vector<int> &massive, int N) {
    int low = 0;
    int high = massive.size() - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      int guess = massive[mid];
      if (guess == N) return mid;
      if (guess > N) high = mid - 1;
      else low = mid + 1;
    }
    return -1;
  }
  static bool is_massive_sorted (const std::vector<int> &massive) {
    if(massive.size() <= 1) return true;
    for (int i = 1; i < massive.size(); i++) {
      if (massive[i] < massive[i-1]) return false;
    }
    return true;
  }
  static int sum_div_by_3 (const std::vector<int> &massive) {
    int sum = 0;
    for (int i = 0; i < massive.size(); i++) {
      if ((massive[i] % 3) == 0) sum += massive[i];
    }
    return sum;
  }
  // я не буду тесты делать для этого алгоритма так как я скорее всего сделал его неправильно
  // static std::vector<std::vector<int>> submassives_of_S (const std::vector<int> massive, const int S) {
  //  std::vector<std::vector<int>> unique_submassives;
  //  std::set<std::vector<int>> unique_submassives_sets;
  //  for (int i = 0; i < massive.size(); i++) {
  //   int sum = massive[i];
  //   std::vector<int> sub_massive {massive[i]};
  //   if (sum == S) unique_submassives_sets.insert(sub_massive);
  //   for (int j = i+1; j < massive.size(); j++) {
  //     sum += massive[j];
  //     sub_massive.push_back(massive[j]);
  //     if(sum == S) {
  //       unique_submassives_sets.insert(sub_massive);
  //     }
  //   }
  //  }
  //  for (std::vector<int> vec : unique_submassives_sets)unique_submassives.push_back(vec);
  //  return unique_submassives;
  // }
  // те-же самые ошибки
  static std::vector<std::vector<int>> submassives_of_S (const std::vector<int> &massive, const int S) {
    std::vector<std::vector<int>> super_massive;
    if (massive.empty()) return super_massive;
    std::vector<int> prefix(massive.size());
    prefix[0] = massive[0];
    for(int i = 1; i < massive.size(); i++){
      prefix[i] = massive[i] + prefix[i - 1];
      }
    if ((massive.size() == 1) && (massive[0] == S)){
      super_massive.push_back({massive[0]});
      return super_massive;
    }
    for (int i = 0;i < massive.size();i++) {
      for (int j = i; j < massive.size();j++) {
        int sum = prefix[j] - (i > 0 ? prefix[i - 1] : 0);
        if (sum == S) {
           std::vector<int> sub_massive(massive.begin() + i, massive.begin() + j + 1);
           super_massive.push_back(sub_massive);
        }
        }
      }
    return super_massive;
  }
};
#endif