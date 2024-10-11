#include <vector>
#include "LabelEncoder.h"

template<typename LabelType, typename ClassType>
void LabelEncoder<LabelType, ClassType>::fit(const std::vector<LabelType> &labels) {
    for (auto &label: labels) {
        if (labels_to_classes.find(label) == labels_to_classes.end()) {
            labels_to_classes[label] = class_count;
            classes_to_labels[class_count] = label;
            class_count++;
        }
    }
}

template<typename LabelType, typename ClassType>
std::vector<ClassType> LabelEncoder<LabelType, ClassType>::transform(const std::vector<LabelType> &labels) {
    std::vector<ClassType> output_classes;

    for (auto &label: labels) {
        output_classes.push_back(labels_to_classes[label]);
    }

    return output_classes;
}

template<typename LabelType, typename ClassType>
std::vector<ClassType> LabelEncoder<LabelType, ClassType>::fit_transform(const std::vector<LabelType> &labels) {
    fit(labels);
    return transform(labels);
}

template<typename LabelType, typename ClassType>
std::vector<LabelType> LabelEncoder<LabelType, ClassType>::inverse_transform(const std::vector<ClassType> &classes) {
    std::vector<LabelType> output_labels;

    for (auto &current_class: classes) {
        output_labels.push_back(classes_to_labels[current_class]);
    }

    return output_labels;
}

template<typename LabelType, typename ClassType>
ClassType LabelEncoder<LabelType, ClassType>::fit_transform_by_one_label(const LabelType &label) {
    if (labels_to_classes.find(label) == labels_to_classes.end()) {
        labels_to_classes[label] = class_count;
        classes_to_labels[class_count] = label;
        class_count++;
    }
    return labels_to_classes[label];
}

template<typename LabelType, typename ClassType>
ClassType LabelEncoder<LabelType, ClassType>::transform_by_one_label(const LabelType &label) {
    return labels_to_classes[label];
}

template<typename LabelType, typename ClassType>
void LabelEncoder<LabelType, ClassType>::fit_by_one_label(const LabelType &label) {
    if (labels_to_classes.find(label) == labels_to_classes.end()) {
        labels_to_classes[label] = class_count;
        classes_to_labels[class_count] = label;
        class_count++;
    }
}

template<typename LabelType, typename ClassType>
int LabelEncoder<LabelType, ClassType>::get_class_count() {
    return class_count;
}

template<typename LabelType, typename ClassType>
void LabelEncoder<LabelType, ClassType>::clear() {
    class_count = 0;
    classes_to_labels.clear();
    labels_to_classes.clear();
}
