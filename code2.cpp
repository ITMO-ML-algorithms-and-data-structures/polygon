#include <iostream>
using namespace std;
// зачем нужен  std:: 
# include <limits>

int main() {
    int num_lenght;
    cout << "Введите длину массива)) ";
    cin >> num_lenght;
    int arr_0[num_lenght];

    int min_ans = numeric_limits<int>::max();
    
    cout << "Введите числа,которые будут в массиве " << endl;
    for (int i = 0; i < num_lenght; i++) {
        cin >> arr_0[i];
    }

    for (int i=1; i<num_lenght; i++) {
        if (arr_0[i] < min_ans) {
            min_ans = arr_0[i];  
        }
    }
    cout << "Ответ " << min_ans << endl;

}
