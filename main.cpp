#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, int>> seeds(n);

        // Создаем пары (plantTime[i], growTime[i])
        for (int i = 0; i < n; ++i) {
            seeds[i] = {plantTime[i], growTime[i]};
        }

        // Сортируем по времени роста в порядке убывания
        sort(seeds.begin(), seeds.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });

        int t = 0; // Общее время посадки
        int ans = 0; // Наименьший день цветения

        for (const auto& seed : seeds) {
            t += seed.first; // Увеличиваем общее время посадки
            ans = max(ans, t + seed.second); // Обновляем наименьший день цветения
        }

        return ans;
    }
};

int main() {
    Solution solution;

    // Тестовые случаи
    vector<vector<int>> plantTimes = {
        {1, 4, 3},
        {1,2,3,2},
        {1}
    };

    vector<vector<int>> growTimes = {
        {2, 3, 1},
           {2,1,2,1},
        {1}
    };

    for (size_t i = 0; i < plantTimes.size(); ++i) {
        cout << "Test case " << (i + 1) << ":" << endl;
        cout << "Plant times: ";
        for (int time : plantTimes[i]) {
            cout << time << " ";
        }

        cout << "\nGrow times: ";
        for (int time : growTimes[i]) {
            cout << time << " ";
        }

        int result = solution.earliestFullBloom(plantTimes[i], growTimes[i]);
        cout << "\nEarliest full bloom day: " << result << endl;
        cout << "-----------------------------------" << endl;
    }

    return 0;
}
