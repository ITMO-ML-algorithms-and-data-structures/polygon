#include "lab.c"

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    if (isAscendingSorted(arr, size)) {
        printf("Этот массив отсортирован по возрастанию\n");
    } else {
        printf("Этот массив не отсортирован по возрастанию\n");
    }
    
    return 0;
}