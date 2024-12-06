#include <bits/stdc++.h>//директива препроцессора, которая включает в себя все стандартные библиотеки C++
using namespace std;


vector<int> countSort(vector<int>& inputArray)//ф-ция countSort:принимает ссылку на vector<int>& inputArray и возвращает вектор, содержащий отсортированные числа
{

    int N = inputArray.size();//метод size.() для опред. размера входного массива
    int M = 0;//переменная, которая будет хранить max значение из входного массива. Изначально она равна 0.


    for (int i = 0; i < N; i++)
        M = max(M, inputArray[i]);//цикл.проходится по всем эл-там массива и обновляет M, если текущий элемент больше текущего значения M(с помощью функции max)


    vector<int> countArray(M + 1, 0);//массив размером (М+1),все его эл-ты нули
    //нужен для подсчета количества вхождений каждого элемента из входного массива


    for (int i = 0; i < N; i++)//Проходит по каждому элементу inputArray и увеличивает соответствующий индекс в countArray . Так, мы подсчитываем количество вхождений каждого элемента
        countArray[inputArray[i]]++;

   
    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];//Накапливает значения в countArray (префиксная сумма), чтобы каждый элемент countArray[i] стал содержать количество элементов, меньших или равных i . Это необходимо для правильной позиционирования в выходном массиве

    
    vector<int> outputArray(N);//выходной массив размером N , который будет содержать отсортированные значения

    for (int i = N - 1; i >= 0; i--)//Проходит по входному массиву inputArray в обратном порядке. 
    //После размещения элемента мы уменьшаем соответствующее значение в countArray, чтобы учесть, что этот элемент уже был размещен.

    {
        outputArray[countArray[inputArray[i]] - 1]
            = inputArray[i];

        countArray[inputArray[i]]--;
    }

    return outputArray;//возвращает отсортированный массив
}


int main()

{

    vector<int> inputArray = {-9, -5, -11};

    vector<int> outputArray = countSort(inputArray);

    for (int i = 0; i < inputArray.size(); i++)
        cout << outputArray[i] << " ";

    return 0;
}