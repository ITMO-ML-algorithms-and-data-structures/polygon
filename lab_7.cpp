#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;


int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
    int n = growTime.size();
    vector<pair<int, int>> times(n);
    for (int i = 0; i < n; i++) {
        times[i].first = -growTime[i];
        times[i].second = plantTime[i];
    }
    sort(times.begin(), times.end());

    int current = 0;
    int total = 0;
    for (int i = 0; i < n; i++) {
        total = max(current + times[i].second - times[i].first, total);
        current += times[i].second;
    }
    return total;
}


void time_tests() {
    std::vector<int> test_sizes = { 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000 };

    for (const int sz : test_sizes) {
        std::vector<int> random_vec_1(sz, 0);
        std::vector<int> random_vec_2(sz, 0);
        srand(time(0));
        generate(random_vec_1.begin(), random_vec_1.end(), rand);
        generate(random_vec_2.begin(), random_vec_2.end(), rand);

        clock_t start = clock();
        earliestFullBloom(random_vec_1, random_vec_1);

        std::cout << "На обработку массива длины " << sz << " ушло " << double(clock() - start)/CLOCKS_PER_SEC*1000 << " мс" << std::endl;
    }
}


int main()
{   
    time_tests();
    std::vector<int> plantTime_example = {1,2,3,2};
    std::vector<int> growTime_example = {2,1,2,1};
    std::cout << earliestFullBloom(plantTime_example, growTime_example) << std::endl;
    return 0;
}