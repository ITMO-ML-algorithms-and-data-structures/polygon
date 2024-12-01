#include<iostream>
#include<vector>
#include<math.h>
#include<cassert>


double mean(const std::vector<double> &arr) {
    //���������� ��������������������� � �������
    double ans = 0;
    for (int i=0; i < arr.size() ; i++) {
        ans += arr[i] / arr.size();
    }
    return ans;
}

void find_best_clusters(std::vector<std::vector<double>> &curr_clusters, std::vector<std::vector<double>> &best_clusters, double &best_result, const std::vector<double> &data,const short k, short step) {
    // ������� ����� ������� 2 * (k ** n) ���
    // ������� ���� ��������� ���������
    if (step == data.size()) { // ���� ��� �������� ������������
        for (short i=0; i < k ; i++) { // O(n)
            // ����� ����� � ������ �������� ��� ���� �� 1 �������
            if (curr_clusters[i].size() == 0) {
                return;
            }
        }
        double curr_result = 0; // �������� ������� �� ������� ���������
        for (short i=0; i < k ; i++) { // �������� ��� ��� ��������� ����� �������� �� O(n)
            double cluster_mean = mean(curr_clusters[i]);
            for (short j=0; j < curr_clusters[i].size() ; j++) {
                curr_result += abs(cluster_mean - curr_clusters[i][j]);
            }
        }
        if (curr_result < best_result) {
            // ���������� ����������
            best_result = curr_result;
            best_clusters = curr_clusters; // ����������� �� O(n)
        }
    } else {
        for (short to=0; to < k ; to++) {
            // ������� �������� � ������� ��������� �������
            curr_clusters[to].push_back(data[step]);
            find_best_clusters(curr_clusters, best_clusters, best_result, data, k, step + 1);
            curr_clusters[to].pop_back();
        }
    }
}

bool tests() {
    short k = 6;
    std::vector<double> data(0);
    std::vector<std::vector<double>> clusters(k, std::vector<double>(0));
    std::vector<std::vector<double>> best_clusters(k, std::vector<double>(0));
    double best_ans_result = double('inf');
    data = {1, 2, 3, 4, 5, 6};
    find_best_clusters(clusters, best_clusters, best_ans_result, data, k, 0);
    assert((best_ans_result == 0));


    clusters.clear();
    best_clusters.clear();
    for (int i=0; i < k ; i++) {
        clusters.push_back(std::vector<double>(0));
        best_clusters.push_back(std::vector<double>(0));
    }
    best_ans_result = double('inf');
    data = {-1.2, 945, 945, -1.2, 945, -1, -2, 4};
    find_best_clusters(clusters, best_clusters, best_ans_result, data, k, 0);
    assert((best_ans_result == 0));
}

int main() {
    short k = 6; // ���-�� ���������
    tests();
    std::vector<double> data(0); // ������� ������
    std::vector<std::vector<double>> clusters(k, std::vector<double>(0)); // ���������� ��� �������� ��������� ��������� ���������
    std::vector<std::vector<double>> best_clusters(k, std::vector<double>(0)); // ������ �� ��������� ���������
    double best_ans_result = double('inf'); // �������� ������� �� ������ ��������� ���������
    double input_val;
    while (std::cin >> input_val) { //���� �������� �� O(n)
        data.push_back(input_val);
    }
    find_best_clusters(clusters, best_clusters, best_ans_result, data, k, 0); // � ����� ������� �������� �� O(k**n)
    for (short i=0; i < k ; i++) {
        for (short j=0; j < best_clusters[i].size() ; j++) {
            std::cout << best_clusters[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    std::cout << best_ans_result;
    return 0;
}
