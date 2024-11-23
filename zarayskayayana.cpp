class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
            }
        int n = height.size();
        std::vector<int> left_max(n); - // O(n) - пространственная сложность
        std::vector<int> right_max(n); // O(n) - пространственная сложность 

        // Заполнение массива left_max
        left_max[0] = height[0];
        for (int i = 1; i < n; i++) { // O(n) - временная сложность
            left_max[i] = std::max(left_max[i - 1], height[i]);
        }
        
        // Заполнение массива right_max
        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) { // O(n) - временная сложность
            right_max[i] = std::max(right_max[i + 1], height[i]);
        }
        
        // Вычисляем количество воды
        int water_trapped = 0; // O(1) - пространственная сложность
        for (int i = 0; i < n; i++) { // O(n) - временная сложность
            water_trapped += std::min(left_max[i], right_max[i]) - height[i];
            }
        return water_trapped;
    }
};
