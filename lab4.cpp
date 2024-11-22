#include <iostream>
#include <vector>
#include <limits>

double distance(double a, double b) {
    return std::abs(a - b);
}

double score_cluster(const std::vector<double>& cluster) {
    double mean = 0.0;
    for (auto& item : cluster) {
        mean += item;
    }
    mean /= cluster.size();

    double metric = 0.0;
    for (auto& item : cluster) {
        metric += distance(item, mean);
    }
    return metric;
}

void setPartitionAsBest(std::vector<std::vector<double>>& bestPartition, std::vector<std::vector<double>> partition) {
    bestPartition = partition;
}

// Функция для генерации всех возможных разбиений на K подмножеств
void generatePartitions(
    const std::vector<double>& arr, 
    std::vector<std::vector<double>>& partition, 
    int start, 
    int k, 
    std::vector<std::vector<double>>& bestPartition,
    double& currentMinDistance) {
    if (start == arr.size()) {
        // Если количество подмножеств соответствует K, сохраняем разбиение в общий массив
        if (partition.size() == k) {
            double scoresTotal = 0;
            for (int i = 0; i < k; i++) {
                scoresTotal += score_cluster(partition[i]);
            }
            double partitionTotalDistance = scoresTotal / k;
            if (currentMinDistance > partitionTotalDistance) {
                setPartitionAsBest(bestPartition, partition);  // Берем разбиение
                currentMinDistance = partitionTotalDistance;
            }
        }
        return;
    }
 
    int remainingLength = arr.size() - start;
    if ((partition.size() + remainingLength) < k) {
        return; // Если элементов не хватит - не продолжаем итерацию
    }
    else {
        // Либо создаём новое подмножество для текущего элемента, если их меньше чем требуемое количество
        partition.push_back({arr[start]});
        generatePartitions(arr, partition, start + 1, k, bestPartition, currentMinDistance);
        partition.pop_back();  // Убираем последнее подмножество
    }

    if ((partition.size() + remainingLength) <= k) {
        return; // Если элементов не хватит - не продолжаем итерацию
    }

    for (int i = partition.size() - 1; i >= 0; i--) {
        partition[i].push_back(arr[start]);
        generatePartitions(arr, partition, start + 1, k, bestPartition, currentMinDistance);  // Рекурсивно обрабатываем следующий элемент
        partition[i].pop_back();  // Убираем элемент из текущего подмножества
    }
}

std::vector<std::vector<double>> generateAndFindBestPartition(std::vector<double>& arr, int k) {
    std::vector<std::vector<double>> bestPartition;
    double distanceInitial = std::numeric_limits<double>::infinity();

    std::vector<std::vector<double>> partition;  // Вектор для хранения текущих подмножеств
    generatePartitions(arr, partition, 0, k, bestPartition, distanceInitial);  // Генерация разбиений на K подмножеств

    return bestPartition;
}