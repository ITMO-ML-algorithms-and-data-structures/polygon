class Solution {
public:
    int numDistinct(string sourceString, string targetString) {
        int sourceLength = sourceString.size();
        int targetLength = targetString.size();
        // Если длина targetString больше длины sourceString, невозможно создать такую подпоследовательность
        if (targetLength > sourceLength) {
            return 0;
        }

        // Одномерный массив, количество способов
        vector<long long> waysToFormSubstring(targetLength + 1, 0);
        waysToFormSubstring[0] = 1;

        const long long MODULO = 1e9 + 7;

  
        for (int i = 1; i <= sourceLength; i++) {
            
            for (int j = targetLength; j >= 1; j--) {
                
                if (sourceString[i - 1] == targetString[j - 1]) {
                    waysToFormSubstring[j] = (waysToFormSubstring[j] + waysToFormSubstring[j - 1]) % MODULO;
                }
            }
        }

        return waysToFormSubstring[targetLength];
    }
};
