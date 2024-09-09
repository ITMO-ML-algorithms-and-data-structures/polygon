#include <stdbool.h>
#include <stdio.h>

// Функция для проверки, является ли массив отсортированным по возрастанию
bool isAscendingSorted(const int *array, int size) {
  for (int i = 1; i < size; i++) {
    if (array[i] < array[i - 1]) { // если текущий элемент меньше предыдущего
      return false; // массив не отсортирован
    }
  }
  return true; // массив отсортирован
}

// пример локального тестирования

// int main() {
//     int arr[] = {1, 2, 3, 4, 5};
//     int size = sizeof(arr) / sizeof(arr[0]);

//     if (isAscendingSorted(arr, size)) {
//         printf("Этот массив отсортирован по возрастанию\n");
//     } else {
//         printf("Этот массив не отсортирован по возрастанию\n");
//     }

//     return 0;
// }