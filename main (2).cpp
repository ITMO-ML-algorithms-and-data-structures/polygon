#include <iostream>
#include <vector>
using namespace std;//позволяет не проставлять std каждый раз
vector<int> find_singular(vector<int>& elements)
{
    vector<int> singular_arr;
    vector<bool> seen(10000, false);
    for (int num : elements)
    {
        if (not(seen[num]) == true)
        {
            singular_arr.push_back(num);
            seen[num] = true;
        }
    }
    return singular_arr;
}
int main()
{
    int size;
    int num;
    vector<int> elements;//задаём список
    cin >> size;//присваиваем size (размер массива) значение первого введённого числа
    for (int i; i < size; i++)//пока значение индекса меньше, чем размер массива,увеличивать индекс на 1)
    {
        cin >> num;//присваиваем num значение следующего введённого числа
        elements.push_back(num);//добавление элемента в вектор
    }
    vector<int> singular_arr = find_singular(elements);//значения в списке равны результатам функции find_singular
    cout << "Singular elements: ";//вывод ответа
    for (int element : singular_arr) 
    {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}