#include "CountVectorizer.h"

std::set<std::string> BuildUnique(const std::vector<std::vector<std::string>>& text)
{
    std::set<std::string> unique; // 32-40 байт
    for (const std::vector<std::string>& row : text)
    {
        for (const std::string& word : row)
        {
            unique.insert(word);
        }
    }
    // Итог: 32-40 байт (без учета размера строк в unique)
    return unique;
}

std::vector<std::string> SplittingWords(const std::string& text)
{
    std::vector<std::string> splitWords; // 24-28 байт (без учета размера строк)
    std::stringstream ss(text); // 24-32 байта
    std::string word; // 24-32 байта
    while (ss >> word)
    {
        std::ranges::transform(word, word.begin(), tolower);
        splitWords.push_back(word);
    }
    // Итог: 72-92 байт (плюс размер всех разделенных слов в splitWords)
    return splitWords;
}

std::vector<std::vector<int>> BuildCountMatrix(const std::vector<std::vector<std::string>>& text, const std::set<std::string>& unique)
{
    std::vector<std::vector<int>> countMatrix = std::vector<std::vector<int>>(text.size(), std::vector<int>(unique.size(), 0)); // 24-28 байт (плюс размер вложенных векторов и их элементов)
    std::unordered_map<std::string, int> wordToIndex;  // 32-48 байт (плюс количество вставленных слов)
    int index = 0; // 4 байта
    for (const std::string& word : unique)
    {
        wordToIndex[word] = index++;
    }
    for (int i = 0; i < text.size(); i++) // 4 байта
    {
        for (const std::string& word : text[i])
        {
            if (wordToIndex.find(word) != wordToIndex.end())
            {
                int localIndex = wordToIndex[word]; // 4 байта
                countMatrix[i][localIndex]++;
            }
        }
    }
    // // Итог: 72-88 байт с учетом вложенных векторов + размер строк и количества уникальных слов
    return countMatrix;
}

std::vector<std::vector<int>> CountVectorizer(const std::string& path)
{
    std::vector<std::vector<std::string>> splitText; // 24-28 байт (без учета вложенных структур)
    std::fstream fileInput; // 24-32 байта
    try
    {
        fileInput.open(path);

        std::string row; // 24-32 байта
        while (!fileInput.eof())
        {
            std::getline(fileInput, row);
            splitText.push_back(SplittingWords(row));
        }
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
        std::cout << "Error open file!" << std::endl;
    }
    fileInput.close();
    std::set<std::string> uniqueSet = BuildUnique(splitText); // 32-40 байт
    std::vector<std::vector<int>> countMatrix = BuildCountMatrix(splitText, uniqueSet); // 72-88 байт (с учетом вложенных векторов)
    // Итог: 176-220 байт без учета вложенных структур + суммарный размер строк в splitText и количества уникальных слов.
    return countMatrix;
}