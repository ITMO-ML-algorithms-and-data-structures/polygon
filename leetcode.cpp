class Solution {
public:
    string minInteger(string num, int k) {
        int length = num.length();
        if (k > length * (length + 1) / 2) {
            sort(num.begin(), num.end());
            return num;
        }
        for (int i = 0; i < length - 1 && k > 0; i++) {
            int current_position = i;
            for (int j = i + 1; j < length; j++) {
                if (j - i > k)
                    break;
                if (num[j] < num[current_position])
                    current_position = j;
            }
            for (int j = current_position; j > i; j--)
                swap(num[j], num[j - 1]);
            k -= (current_position - i);
        }
        return num;
    }
};