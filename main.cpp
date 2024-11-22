#include <iostream>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    const int tam = 5;
    int arr[tam]={9,2,4,4,12};

    // Imprimir arreglo antes de ordenar
    for (int i = 0; i < tam; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Ordenar el arreglo
    insertionSort(arr, tam);

    // Imprimir arreglo después de ordenar
    for (int i = 0; i < tam; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}