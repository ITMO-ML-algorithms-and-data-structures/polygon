#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<ctime>
#include<iomanip>



int Partition(std::vector<int> &arr, const int l, const int r) {
    // 1 + 4 + 4 ����� ������ �������
    const int x = arr[r]; // +4 �����
    int small_part_ln = 0; // + 4 �����

    for (int i=l; i <= r ; i++) { // O(r-l)
        // + 4 ����� ������ �����
        // ����� ����� �������� ������������ ���-�� ������
        // � ������ ������ 9 + 13*len_data ����
        if (arr[i] <= x) {
            std::swap(arr[l+small_part_ln], arr[i]);
            small_part_ln += 1;
        }
    }

    return l + small_part_ln - 1;
}

void SortPart(std::vector<int> &arr, const int l, const int r) {
    // 1 + 4 + 4 ����� ������ �������
    if (l >= r) {
        return;
    }
    const int separator = Partition(arr, l, r); // + 4 �����, O(r-l)
    SortPart(arr, l, separator - 1);
    SortPart(arr, separator + 1, r);
    // ������������ ������� �������� - len_data, ������ � ������ ������ �� SortPart ����� ��������� 13 * len_data ����
}


void QuickSort(std::vector<int> &arr) {
    // 1 ���� ��-�� ������
    SortPart(arr, 0, arr.size() - 1);
}

bool tests() {
    std::ifstream findata, fin_ans;
    findata.open("unit_tests\\quicksort_bad_test.txt");
    fin_ans.open("unit_tests\\quicksort_bad_test_answers.txt");
    for (int test=0; test < 1000 ; test++) {
        int len_data;
        int input_val;
        std::vector<int> data(0);
        findata >> len_data;
        for (int i=0; i < len_data ; i++) {
            findata >> input_val;
            data.push_back(input_val);
        }
        QuickSort(data);
        for (int i=0; i < len_data ; i++) {
            fin_ans >> input_val;
            if (input_val != data[i]) {
                std::cout << "failed on bad test " << i + 1 << '\n';
                std::cout << "Program out:\n";
                for (int j=0; j < len_data ; j++) {
                    std::cout << data[j] << ' ';
                }
                return false;
            }
        }
    }
    findata.close();
    fin_ans.close();

    findata.open("unit_tests\\quicksort_average_test.txt");
    fin_ans.open("unit_tests\\quicksort_average_test_answers.txt");
    for (int test=0; test < 1000 ; test++) {
        int len_data;
        int input_val;
        std::vector<int> data(0);
        findata >> len_data;
        for (int i=0; i < len_data ; i++) {
            findata >> input_val;
            data.push_back(input_val);
        }
        QuickSort(data);
        for (int i=0; i < len_data ; i++) {
            fin_ans >> input_val;
            if (input_val != data[i]) {
                std::cout << "failed on average test " << i + 1 << '\n';
                std::cout << "Program out:\n";
                for (int j=0; j < len_data ; j++) {
                    std::cout << data[j] << ' ';
                }
                return false;
            }
        }
    }
    findata.close();
    fin_ans.close();
    return true;
}

void time_tests() {
    std::fstream findata("time_tests\\time_tests0.txt");
    std::ofstream out("time_proc_quick.txt");
    for (int test=0; test < 400 ; test++) {
        int len_data;
        int input_val;
        std::vector<int> data(0);
        findata >> len_data;
        for (int i=0; i < len_data ; i++) {
            findata >> input_val;
            data.push_back(input_val);
        }
        unsigned long long t_start =  clock();
        QuickSort(data);
        unsigned long long t_end =  clock();
        double execution_time = (double)(t_end - t_start) / 1000;
        std::cout << len_data << ' ' << std::setprecision(20) << execution_time << '\n';
        out << len_data << ' ' << std::setprecision(20) << execution_time << '\n';
    }
    findata.close();

    findata.open("time_tests\\time_tests1.txt");
    for (int test=0; test < 300 ; test++) {
        int len_data;
        int input_val;
        std::vector<int> data(0);
        findata >> len_data;
        for (int i=0; i < len_data ; i++) {
            findata >> input_val;
            data.push_back(input_val);
        }
        unsigned long long t_start =  clock();
        QuickSort(data);
        unsigned long long t_end =  clock();
        double execution_time = (double)(t_end - t_start) / 1000;
        std::cout << len_data << ' ' << std::setprecision(20) << execution_time << '\n';
        out << len_data << ' ' << std::setprecision(20) << execution_time << '\n';
    }
    findata.close();

    findata.open("time_tests\\time_tests2.txt");
    for (int test=0; test < 150 ; test++) {
        int len_data;
        int input_val;
        std::vector<int> data(0);
        findata >> len_data;
        for (int i=0; i < len_data ; i++) {
            findata >> input_val;
            data.push_back(input_val);
        }
        unsigned long long t_start =  clock();
        QuickSort(data);
        unsigned long long t_end =  clock();
        double execution_time = (double)(t_end - t_start) / 1000;
        std::cout << len_data << ' ' << std::setprecision(20) << execution_time << '\n';
        out << len_data << ' ' << std::setprecision(20) << execution_time << '\n';
    }
    findata.close();

    findata.open("time_tests\\time_tests3.txt");
    for (int test=0; test < 150 ; test++) {
        int len_data;
        int input_val;
        std::vector<int> data(0);
        findata >> len_data;
        for (int i=0; i < len_data ; i++) {
            findata >> input_val;
            data.push_back(input_val);
        }
        unsigned long long t_start =  clock();
        QuickSort(data);
        unsigned long long t_end =  clock();
        double execution_time = (double)(t_end - t_start) / 1000;
        std::cout << len_data << ' ' << std::setprecision(20) << execution_time << '\n';
        out << len_data << ' ' << std::setprecision(20) << execution_time << '\n';
    }
    findata.close();
    out.close();
}

void box_tests() {
    std::fstream findata("box_tests\\random_tests.txt");
    std::ofstream out("box_tests\\time_box_quick.txt");
    for (int test=0; test < 50 ; test++) {
        int len_data;
        int input_val;
        std::vector<int> data(0);
        findata >> len_data;
        for (int i=0; i < len_data ; i++) {
            findata >> input_val;
            data.push_back(input_val);
        }
        unsigned long long t_start =  clock();
        QuickSort(data);
        unsigned long long t_end =  clock();
        double execution_time = (double)(t_end - t_start) / 1000;
        std::cout << len_data << ' ' << std::setprecision(10) << execution_time << '\n';
        out << std::setprecision(10) << execution_time << '\n';
    }
    findata.close();
    out.close();

    findata.open("box_tests\\random_tests_long.txt");
    out.open("box_tests\\time_box_quick2.txt");
    for (int test=0; test < 50 ; test++) {
        int len_data;
        int input_val;
        std::vector<int> data(0);
        findata >> len_data;
        for (int i=0; i < len_data ; i++) {
            findata >> input_val;
            data.push_back(input_val);
        }
        unsigned long long t_start =  clock();
        QuickSort(data);
        unsigned long long t_end =  clock();
        double execution_time = (double)(t_end - t_start) / 1000;
        std::cout << len_data << ' ' << std::setprecision(10) << execution_time << '\n';
        out << std::setprecision(10) << execution_time << '\n';
    }
    findata.close();
    out.close();
}


int main() {
    std::vector<int> data(0); //24 + 4 * len_data ����
    int len_data, input_val; // 8 ����
    std::cin >> len_data;
    for (int i=0; i < len_data ; i++) { //O(len_data)
        //+4 ����� � �����
        std::cin >> input_val;
        data.push_back(input_val);
    }
    QuickSort(data);
    for (int i=0; i < len_data ; i++) {
        //+4 ����� � �����
        std::cout << data[i] << ' ';
    }
    return 0;
}
