#include<iostream>
using namespace std;

int getNextGap(int gap)
{
    gap = (gap * 10) / 13;

    if (gap < 1)
        return 1;
    return gap;
}

void combSort(int a[], int n)
{
    int gap = n;

    bool swapped = true;

    while (gap != 1 || swapped == true)
    {
        gap = getNextGap(gap);

        swapped = false;

        for (int i = 0; i < n - gap; i++)
        {
            if (a[i] > a[i + gap])
            {
                swap(a[i], a[i + gap]);
                swapped = true;
            }
        }
    }
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
    int a[] = {60, 20, 40, 70, 30, 10};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Исходный массив\n");
    printArray(a, n);

    combSort(a, n);
    printf("Отсортированный массив\n");
    printArray(a, n);

    return 0;
}