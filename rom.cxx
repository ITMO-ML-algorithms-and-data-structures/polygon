#include <iostream>
#include <vector>
using namespace std;
int main() 
{
int size ; 
int i;
int n;
 cout << "give me the size of the table ";
  cin >> size ;
  vector<int> table(size);
  for (i=1;i< size+1 ;i++)
  {
   cout << "give me the number of the " <<i<< " position ";
   cin >> table[i];
  }
    for (i=1;i< size+1 ;i++) 
    {
    cout <<  table[i];
    }
cout << "\n give the number that you want to shake in the table ";
cin >> n;
for (i=1;i<size+1;i++){
    if (table[i]==n)
    {
      cout << "your number is in the " << i << " position ";;
    
    }
  }
  return -1;

}
