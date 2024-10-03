#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    int quantity, s; // количество элементов в массиве и значение s по усовию
    cin >> quantity;
    cin >> s;
    vector <int> nums(quantity);
    for (int i = 0; i < quantity; i++) { // заполнение массива
        cin >> nums[i];
    }
    // сортировка массива
    for (int j = 0; j < quantity; j++) {
        int num_min = j;
        for (int i = j; i < quantity; i++) {
            if (nums[i] < nums[num_min]) {
                num_min = i;                // присваиваем индекс меньшего числа
            }
        }
        int temp;                   //меняем j элемент и самый маленьки который     нашли из оставшихся
        temp = nums[j];
        nums[j] = nums[num_min];
        nums[num_min] = temp;
    }
    // нахождение пар чисел
    int last = quantity - 1;
    for (int i = 0; i <= last; i++) { // проходимся по начальным элементам массива
        int last = quantity - 1;
        while (i <= last) {         // для элемента из начала подбираем элементы с конца
            if  (nums[i] + nums[last] < s) {    // если сумма меньше: выходим из   цикла
                break;
            }
            else if (nums[i] + nums[last] > s) { //если сумма больше то            уменьшаем элемент
                last--;
            }
            else if (nums[i] + nums[last] == s) { // если подошло то выводим и выходим из цикла тк дальше значения будут меньше
                cout << nums[i] << " " << nums[last] << endl;
                break;
            }
        }
    }
    return 0;
}
