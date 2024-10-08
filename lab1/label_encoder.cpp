#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

// fit: преобразуем в set чтобы удалить дубликаты и пушим в classes_ и сортируем
// transform: метчим вход с class_to_index_
// inverse_transform: ну очев емае
template <typename T>
class LabelEncoder {
   public:
    void fit(const std::vector<std::string> &categories) {
        // input: N * 24 (clang https://devblogs.microsoft.com/oldnewthing/20240510-00/?p=109742)
        // -----
        // https://stackoverflow.com/questions/1041620/whats-the-most-efficient-way-to-erase-duplicates-and-sort-a-vector
        // -----
        // ну тут может быть от +(1*24) до +(N*24), зависит от колва уникальных
        std::set<std::string> s(categories.begin(), categories.end());
        classes_.assign(s.begin(), s.end());
        std::sort(classes_.begin(), classes_.end());

        // size_t == unsigned int: 4
        for (size_t i = 0; i < classes_.size(); ++i) {
            class_to_index_[classes_[i]] = static_cast<T>(i);  // idx -> T
        }
    }

    std::vector<T> transform(const std::vector<std::string> &categories) {
        // input: N * 24 
        // encoded_labels: N * 4 (предположим что T это int)
        std::vector<T> encoded_labels;
        // category: 24 
        for (const std::string &category : categories) {
            encoded_labels.push_back(class_to_index_[category]);
        }
        return encoded_labels;
    }

    std::vector<std::string> inverse_transform(const std::vector<T> &labels) {
        // input: N * 4 
        // decoded_categories: N * 24
        std::vector<std::string> decoded_categories;
        // label: 4 (T == int)
        for (const auto &label : labels) {
            decoded_categories.push_back(classes_[label]);
        }
        return decoded_categories;
    }

   private:
    // N * 24
    std::vector<std::string> classes_;
    // N * (24 + 4[int])
    std::map<std::string, T> class_to_index_;
};

// sum = N * (24 + N + 24 + 4 + 4 + 24 + 24 + 24 + 4) + 4 + 24 + 4 = 
// = N^2 * 132 + 32 байт 
