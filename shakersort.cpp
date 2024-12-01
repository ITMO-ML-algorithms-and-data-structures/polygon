#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<ctime>
#include<iomanip>

void ShakerSort(std::vector<int> &arr) {
    // 1 байт из-за ссылки
    for (int iter=0; iter < arr.size()/2 ; iter++) {
        //+4 байта в цикле
        bool is_edit = false; //1 байт
        for (int i=iter; i < (arr.size() - iter - 1) ; i++) { //O(len_data - iter)
            //+4 байта в цикле
            // здесь будет затрачено больше всего памяти 9 байт
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                is_edit = true;
            }
        }
        for (int i=(arr.size() - iter - 1); i > iter ; i--) { //O(len_data - iter)
            //+4 байта в цикле
            // здесь будет затрачено больше всего памяти 9 байт
            if (arr[i - 1] > arr[i]) {
                std::swap(arr[i - 1], arr[i]);
                is_edit = true;
            }
        }
        if (!is_edit) {
            return;
        }
        // итерация работает за O(len_data - iter)
        // итого все итерации отработают за O(len_data * len_data) в худшем случаи
    }
}


bool tests() {
    std::ifstream findata, fin_ans;
    findata.open("unit_tests\\shakersort_bad_test.txt");
    fin_ans.open("unit_tests\\shakersort_bad_test_answers.txt");
    for (int test=0; test < 1000 ; test++) {
        int len_data;
        int input_val;
        std::vector<int> data(0);
        findata >> len_data;
        for (int i=0; i < len_data ; i++) {
            findata >> input_val;
            data.push_back(input_val);
        }
        ShakerSort(data);
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

    findata.open("unit_tests\\shakersort_average_test.txt");
    fin_ans.open("unit_tests\\shakersort_average_test_answers.txt");
    for (int test=0; test < 1000 ; test++) {
        int len_data;
        int input_val;
        std::vector<int> data(0);
        findata >> len_data;
        for (int i=0; i < len_data ; i++) {
            findata >> input_val;
            data.push_back(input_val);
        }
        ShakerSort(data);
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

    findata.open("unit_tests\\shakersort_good_test.txt");
    fin_ans.open("unit_tests\\shakersort_good_test_answers.txt");
    for (int test=0; test < 1000 ; test++) {
        int len_data;
        int input_val;
        std::vector<int> data(0);
        findata >> len_data;
        for (int i=0; i < len_data ; i++) {
            findata >> input_val;
            data.push_back(input_val);
        }
        ShakerSort(data);
        for (int i=0; i < len_data ; i++) {
            fin_ans >> input_val;
            if (input_val != data[i]) {
                std::cout << "failed on good test " << i + 1 << '\n';
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
    std::ofstream out("time_proc_shaker.txt");
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
        ShakerSort(data);
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
        ShakerSort(data);
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
        ShakerSort(data);
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
        ShakerSort(data);
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
    std::ofstream out("box_tests\\time_box_shaker.txt");
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
        ShakerSort(data);
        unsigned long long t_end =  clock();
        double execution_time = (double)(t_end - t_start) / 1000;
        std::cout << len_data << ' ' << std::setprecision(10) << execution_time << '\n';
        out << std::setprecision(10) << execution_time << '\n';
    }
    findata.close();
    out.close();

    findata.open("box_tests\\random_tests_long.txt");
    out.open("box_tests\\time_box_shaker2.txt");
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
        ShakerSort(data);
        unsigned long long t_end =  clock();
        double execution_time = (double)(t_end - t_start) / 1000;
        std::cout << len_data << ' ' << std::setprecision(10) << execution_time << '\n';
        out << std::setprecision(10) << execution_time << '\n';
    }
    findata.close();
    out.close();
}

int main() {
    std::vector<int> data(0); //24 + 4 * len_data байт
    int len_data, input_val; // 8 байт
    std::cin >> len_data;
    for (int i=0; i < len_data ; i++) { //O(len_data)
        //+4 байта в цикле
        std::cin >> input_val;
        data.push_back(input_val);
    }
    ShakerSort(data);
    for (int i=0; i < len_data ; i++) {
        //+4 байта в цикле
        std::cout << data[i] << ' ';
    }
    return 0;
}
