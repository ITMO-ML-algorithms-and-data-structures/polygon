#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score, int k = 26) {//  временная сложность - O(2^n * l), пространственная сложность - O(2^n * k + n), где n - кол-во слов в words, l - длина наибольшего слова
        vector<int> count(k, 0); // пространственная сложность - O(k)
        for (char symb: letters) { //  временная сложность - O(p), где p - длина letters
            count[symb - 'a']++;
        }
        return findScoreWords(words, score, count, 0); //  временная сложность - O(2^n * l), пространственная сложность - O(2^n * k + n), где n - кол-во слов в words, l - длина наибольшего слова
    }

private:
    int findScoreWords(vector<string> words, vector<int> score, vector<int> count, int index) { //  временная сложность - O(2^(n - index) * l), пространственная сложность - O(2^(n - index) * k + n - index), где n - кол-во слов в words, l - длина наибольшего слова
        if (index == words.size()) {
            return 0;
        }
        int maxScore = findScoreWords(words, score, count, index + 1); //  временная сложность - O(2^(n - index - 1) * l), пространственная сложность - O(2^(n - index - 1) * k + n - index - 1), где n - кол-во слов в words, l - длина наибольшего слова
        int wordScore = 0;
        bool canUse = true;
        vector<int> newCount = count; // пространственная сложность - O(k)
        for (char symb: words[index]) { // временная сложность - O(l)
            if (newCount[symb - 'a'] == 0) {
                canUse = false;
                break;
            }
            newCount[symb - 'a']--;
            wordScore += score[symb - 'a'];
        }

        if (canUse) { //  временная сложность - O(2^(n - index - 1) * l), пространственная сложность - O(2^(n - index - 1) * k + n - index - 1), где n - кол-во слов в words, l - длина наибольшего слова
            int scoreWithWord = wordScore + findScoreWords(words, score, newCount, index + 1);
            maxScore = max(maxScore, scoreWithWord);
        }
        return maxScore;
    }
};

int main() {
    vector<string> words = {"leetcode"};
    vector<char> letters = {'l', 'e', 't', 'c', 'o', 'd'};
    vector<int> score = {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
    Solution solution;
    int result = solution.maxScoreWords(words, letters, score);
    cout << result;
    return 0;
}
