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
