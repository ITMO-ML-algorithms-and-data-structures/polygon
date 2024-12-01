#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<ctime>
#include<iomanip>


int get_radix(int a) {
    // + 4 ����� ���������� a
    int ans = 1; // + 4 �����
    a /= 10;
    while (a) { // O(���-�� �������� a)
        ans += 1;
        a /= 10;
    }
    // ����� ����� ������������� ������ ����� ������ - 8 + 8 + 8 + 24 + 10*24 + 4*len_data + 1 ����
    return ans;
}

void RadixSort(std::vector<int> &arr) {
    // + 1 ���� &arr
    std::vector<std::vector<int>> radixes = std::vector<std::vector<int>> (10, std::vector<int>(0)); // 24 + 10*24 + 4*len_data ����
    int max_ln = 0, k = 1; // + 8 ����
    for (int i=0; i < arr.size() ; i++) { // O(len_data * ���� ���-�� ��������)
        // + 4 ����� ������ �����
        max_ln = std::max(max_ln, get_radix(arr[i]));
    }
    for (int r=0; r < max_ln ; r++) {
        // + 4 ����� ������ �����
        for (int i=0; i < arr.size() ; i++) { // O(len_data)
            // + 4 ����� ������ �����
            radixes[(arr[i]/k) % 10].push_back(arr[i]);
        }
        arr.clear();
        for (int digit=0 ; digit < 10 ; digit++) { // O(len_data)
            // + 4 ����� ������ �����
            for (int i=0; i < radixes[digit].size() ; i++) {
                // + 4 ����� ������ �����
                arr.push_back(radixes[digit][i]);
            }
        }
        radixes = std::vector<std::vector<int>> (10, std::vector<int>(0));
        k *= 10;
        // ���� ���������� �� O(max_ln * len_data)
    }
    //� ����� ��� ������� ���������� �� O(���� ���-�� �������� * len(data))
}


bool tests() {
    std::ifstream findata, fin_ans;
    findata.open("unit_tests\\radixsort_bad_test.txt");
    fin_ans.open("unit_tests\\radixsort_bad_test_answers.txt");
    for (int test=0; test < 1000 ; test++) {
        int len_data;
        int input_val;
        std::vector<int> data(0);
        findata >> len_data;
        for (int i=0; i < len_data ; i++) {
            findata >> input_val;
            data.push_back(input_val);
        }
        RadixSort(data);
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

    findata.open("unit_tests\\radixsort_average_test.txt");
    fin_ans.open("unit_tests\\radixsort_average_test_answers.txt");
    for (int test=0; test < 1000 ; test++) {
        int len_data;
        int input_val;
        std::vector<int> data(0);
        findata >> len_data;
        for (int i=0; i < len_data ; i++) {
            findata >> input_val;
            data.push_back(input_val);
        }
        RadixSort(data);
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
    std::ofstream out("time_proc.txt");
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
        RadixSort(data);
        unsigned long long t_end =  clock();
        double execution_time = (double)(t_end - t_start) / 1000;
        std::cout << len_data << ' ' << std::setprecision(20) << execution_time << '\n';
        out << std::setprecision(20) << execution_time << '\n';
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
        RadixSort(data);
        unsigned long long t_end =  clock();
        double execution_time = (double)(t_end - t_start) / 1000;
        std::cout << len_data << ' ' << std::setprecision(20) << execution_time << '\n';
        out << std::setprecision(20) << execution_time << '\n';
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
        RadixSort(data);
        unsigned long long t_end =  clock();
        double execution_time = (double)(t_end - t_start) / 1000;
        std::cout << len_data << ' ' << std::setprecision(20) << execution_time << '\n';
        out << std::setprecision(20) << execution_time << '\n';
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
        unsigned long long t_start = clock();
        RadixSort(data);
        unsigned long long t_end = clock();
        double execution_time = (double)(t_end - t_start) / 1000;
        std::cout << len_data << ' ' << std::setprecision(20) << execution_time << '\n';
        out << std::setprecision(20) << execution_time << '\n';
    }
    findata.close();
    out.close();
}

void box_tests() {
    std::fstream findata("box_tests\\random_tests.txt");
    std::ofstream out("box_tests\\time_box_radix.txt");
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
        RadixSort(data);
        unsigned long long t_end =  clock();
        double execution_time = (double)(t_end - t_start) / 1000;
        std::cout << len_data << ' ' << std::setprecision(10) << execution_time << '\n';
        out << std::setprecision(10) << execution_time << '\n';
    }
    findata.close();
    out.close();

    findata.open("box_tests\\random_tests_long.txt");
    out.open("box_tests\\time_box_radix2.txt");
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
        RadixSort(data);
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
    RadixSort(data);
    for (int i=0; i < len_data ; i++) {
        //+4 ����� � �����
        std::cout << data[i] << ' ';
    }
    return 0;
}
