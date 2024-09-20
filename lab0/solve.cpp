#include <iostream>
#include <vector>
#include <map>

using namespace std;

int find_max(const vector<int>& nums) {
    int max_num = nums[0];
    for (int num : nums) {
        if (num > max_num) {
            max_num = num;
        }
    }
    return max_num;
}

vector<int> eratosthenes(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;
    
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return primes;
}

bool in_primes(int num, const vector<int>& primes) {
    for (int prime : primes) {
        if (prime == num) {
            return true;
        }
    }
    return false;
}

void find_even_occurrence_primes(const vector<int>& nums) {
    int max_num = find_max(nums);
    vector<int> primes = eratosthenes(max_num);
    map<int, int> prime_count;

    for (int num : nums) {
        if (in_primes(num, primes)) {
            prime_count[num]++;
        }
    }

    for (const pair<int, int>& pair : prime_count) {
        if (pair.second % 2 == 0) {
            cout << pair.first << " - " << pair.second << "\n";
        }
    }
}

int main() {
    std::vector<int> nums = {2, 3, 5, 2, 3, 7, 5, 5, 11, 11, 11, 11, 13};
    find_even_occurrence_primes(nums);
}