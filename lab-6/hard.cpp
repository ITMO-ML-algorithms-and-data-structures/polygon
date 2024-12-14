class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        // Массивы для хранения максимальной прибыли для одной транзакции
        vector<int> leftProfit(n, 0);  // Максимальная прибыль от 0 до i
        vector<int> rightProfit(n, 0); // Максимальная прибыль от i до n-1

        // Вычисляем максимальную прибыль от 0 до i (левая часть)
        int minPrice = prices[0];
        for (int i = 1; i < n; ++i) {
            minPrice = min(minPrice, prices[i]);
            leftProfit[i] = max(leftProfit[i - 1], prices[i] - minPrice);
        }

        // Вычисляем максимальную прибыль от i до n-1 (правая часть)
        int maxPrice = prices[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            maxPrice = max(maxPrice, prices[i]);
            rightProfit[i] = max(rightProfit[i + 1], maxPrice - prices[i]);
        }

        // Комбинируем результаты для двух транзакций
        int maxProfit = 0;
        for (int i = 0; i < n; ++i) {
            maxProfit = max(maxProfit, leftProfit[i] + rightProfit[i]);
        }

        return maxProfit;
    }
};