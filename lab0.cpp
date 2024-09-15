#include <vector>
#include <iostream>
#include <set>

using namespace std;

bool is_prime(long long x){
    if (x < 2) {
        return false;
    }
    for (long long i=2; (i*i)<=x; i++){
        if ((x % i) == 0){
            return false;
        }
    }
    return true;
}

int main() {
    vector<long long> nums(0);
    long long a;
    while (cin >> a){
        nums.push_back(a);
    }
    set<long long> primes={};
    for (int i=0; i < nums.size() ; i++){
        if (is_prime(nums[i])) {
            primes.insert(nums[i]);
        }
    }
    for (long long el:primes){
        cout << el << " ";
    }
   return 0;
}
