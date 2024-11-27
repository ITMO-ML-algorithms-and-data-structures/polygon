#include <fstream>
#include <vector>

using namespace std;


long int getMinrun(long int n){
  long int r = 0; 
  while (n>=64){
    r |= n & 1; 
    n >>= 1
  }
  return n + r;
}


void timsort(vector<long int> &data){
  long int n = data;
  long int minrun = getMinrun(n);
  long int el = 0;

  for (int i=0; i<n; i+minrun){
    if (data[i] <= data[el])
  }
} 


int main(){
  return 0;
}
