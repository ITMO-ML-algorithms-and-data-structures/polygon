class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size();
        int moves = 0;

        // Два указателя для обработки строки
        int left = 0, right = n - 1;

        while (left < right) {
            // Если символы слева и справа совпадают, переходим к следующим
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                // Найти ближайший символ справа, который совпадает с s[left]
                int k = right;
                while (k > left && s[k] != s[left]) {
                    k--;
                }

                if (k == left) { // Если совпадение не найдено
                    // Переместить s[left] к центру
                    swap(s[left], s[left + 1]);
                    moves++;
                } else {
                    // Переместить s[k] к позиции right
                    for (int j = k; j < right; j++) {
                        swap(s[j], s[j + 1]);
                        moves++;
                    }
                    left++;
                    right--;
                }
            }
        }

        return moves;
    }
};