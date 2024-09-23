#include <iostream>
#include <vector>
#include <map>
#include <list>




bool isPrime(int number) // ‘ункци€ определ€юща€ простое число или нет
{
	if (number == 1)
	{
		return false;
	}
	for (int i = 2; i < number; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int ar[] = { 1, 2, 5, 22, 3, 3, 2, 5, 5, 3, 52, 3}; // ¬ходной масив 
	int Size = int(sizeof(ar) / sizeof(int));
	std::map<int, int> Prime; // map в котором будет хранитс€ <простое число, его количесвто в масиве> 
	for (int i = 0; i < Size; i++)
	{
		if (isPrime(ar[i]) == true)
		{
			if (Prime.count(ar[i]) == 1)
			{
				Prime[ar[i]] += 1;
			}
			else
			{
				Prime.insert(std::make_pair(ar[i], 1));
			}
		}
	}
	int res = 0;
	for (auto& element : Prime)
	{
		if (element.second % 2 == 0)
		{
			res += 1;
		}
	}
	
	std::cout << res;
}