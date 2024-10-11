#ifndef POLYGON_LABELENCODER_H
#define POLYGON_LABELENCODER_H

#include <unordered_map>
#include <vector>
#include <string>


template<typename LabelType, typename ClassType>
class LabelEncoder {
private:
    std::unordered_map<LabelType, ClassType> labels_to_classes;
    std::unordered_map<ClassType, LabelType> classes_to_labels;
    int class_count = 0;
public:
    LabelEncoder() = default;

    void fit(const std::vector<LabelType> &labels);

    std::vector<ClassType> transform(const std::vector<LabelType> &labels);

    std::vector<ClassType> fit_transform(const std::vector<LabelType> &labels);

    std::vector<LabelType> inverse_transform(const std::vector<ClassType> &classes);

    ClassType fit_transform_by_one_label(const LabelType &label);

    void fit_by_one_label(const LabelType &label);

    ClassType transform_by_one_label(const LabelType &label);

    int get_class_count();

    void clear();
};


#include "LabelEncoder.cpp"


#endif //POLYGON_LABELENCODER_H
