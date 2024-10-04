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
        // https://stackoverflow.com/questions/1041620/whats-the-most-efficient-way-to-erase-duplicates-and-sort-a-vector
        std::set<std::string> s(categories.begin(), categories.end());
        classes_.assign(s.begin(), s.end());
        std::sort(classes_.begin(), classes_.end());

            for (size_t i = 0; i < classes_.size(); ++i) {
            class_to_index_[classes_[i]] = static_cast<T>(i);  // idx -> T
        }
    }

    std::vector<T> transform(const std::vector<std::string> &categories) {
        std::vector<T> encoded_labels;
        for (const auto &category : categories) {
            encoded_labels.push_back(class_to_index_[category]);
        }
        return encoded_labels;
    }

    std::vector<std::string> inverse_transform(const std::vector<T> &labels) {
        std::vector<std::string> decoded_categories;
        for (const auto &label : labels) {
            decoded_categories.push_back(classes_[label]);
        }
        return decoded_categories;
    }

   private:
    std::vector<std::string> classes_;
    std::map<std::string, T> class_to_index_;
};