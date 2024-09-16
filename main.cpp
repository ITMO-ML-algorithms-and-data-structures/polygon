using namespace std;
#include <iostream>
#include <vector>

int main()
{
  int n = 6;
  vector<int> vec(n);
  int sum = 0;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> vec[i];
  }

  for (int i = 0; i < n; i++)
  {
    if (vec[i] % 3 == 0)
    {
      sum = sum + vec[i];
    }
  }

  cout << sum;
}
