#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int maxScoreWords(const vector<string>& words, const vector<char>& letters, const vector<int>& score) {
    // Step 1: Считаем частоту каждой буквы
    unordered_map<char, int> letterCount;
    for (char letter : letters) {
        letterCount[letter]++;
    }

    // Step 2: Считаем word scores и проверяем валидность
    vector<int> wordScores;
    vector<vector<int>> wordLetterCounts(words.size(), vector<int>(26, 0));

    for (const string& word : words) {
        int currentScore = 0;
        bool canForm = true;

        for (char c : word) {
            currentScore += score[c - 'a'];
            // wordScores.size() - индекс слова (добавляем туда новое слово на каждом шаге)
            wordLetterCounts[wordScores.size()][c - 'a']++;
        }

        // Проверяем можем ли мы составить это слово из наших букв
        for (char c : word) {
            if (wordLetterCounts[wordScores.size()][c - 'a'] > letterCount[c]) {
                canForm = false;
                break;
            }
        }

        if (canForm) {
            wordScores.push_back(currentScore);
        } else {
            wordScores.push_back(0); // Для невалидных слов ставим скор 0
        }
    }

    // Step 3: Используем ДП чтобы найти максимальный скор
    int maxScore = 0;
    int numWords = wordScores.size();

    // Есть 2^numWords комбинаций слов, 1-слово в комбинации, 0-нет
    for (int mask = 0; mask < (1 << numWords); ++mask) {
        unordered_map<char, int> usedLetters;
        int currentScore = 0;

        for (int i = 0; i < numWords; ++i) {
            if (mask & (1 << i)) { // Если i-ое слово в комбинации
                currentScore += wordScores[i];
                for (char c : words[i]) {
                    usedLetters[c]++;
                }
            }
        }

        // Проверяем что эта комбинация валидна по возможным буквам
        bool validCombination = true;
        for (const auto& entry : usedLetters) {
            if (entry.second > letterCount[entry.first]) {
                validCombination = false;
                break;
            }
        }

        if (validCombination) {
            maxScore = max(maxScore, currentScore);
        }
    }

    return maxScore;
}

int main() {
    vector<string> words1 = {"dog", "cat", "dad", "good"};
    vector<char> letters1 = {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
    vector<int> score1 = {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0};

    cout << "Maximum Score: " << maxScoreWords(words1, letters1, score1) << endl;

    return 0;
}
