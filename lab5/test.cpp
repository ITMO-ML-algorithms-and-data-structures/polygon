#define _CRT_SECURE_NO_DEPRECATE


#include <iostream>

#include <sstream>

#include <unordered_map>

#include <string>
#include <vector>

#include <cstdint>

#include <fstream>

#include <random>

#include <cmath>
#include <limits>

#include <algorithm>
#include <numeric>

using namespace std;

#define ASSERT_MSG(condition, message) \
    do { \
        if (!(condition)) { \
            cerr << "Assertion failed: (" #condition "), function " << __FUNCTION__ \
                      << ", file " << __FILE__ << ", line " << __LINE__ << "." << endl; \
            cerr << "Error in test: " << message << endl; \
            abort(); \
        } \
    } while (false)

#include <vector>
#include <algorithm>

using namespace std;

vector<int> BubbleSort(vector<int> inp) {
    int n = inp.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (inp[j] > inp[j + 1]) {
                swap(inp[j], inp[j + 1]);
            }
        }
    }

    // Memory usage - N, where N - inp.size

    return inp;
}

vector<int> QuickSortHelper(vector<int>& inp, int low, int high) {
    if (low < high) {
        int pivot = inp[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (inp[j] < pivot) {
                i++;
                swap(inp[i], inp[j]);
            }
        }
        swap(inp[i + 1], inp[high]);
        int pi = i + 1;
        QuickSortHelper(inp, low, pi - 1);
        QuickSortHelper(inp, pi + 1, high);
    }

    // Memory usage - N, where N - inp.size; doesn't get any bigger since we use pointer.

    return inp;
}

vector<int> QuickSort(vector<int> inp) {
    return QuickSortHelper(inp, 0, inp.size() - 1);
}

vector<int> BucketSort(vector<int> inp) {
    int n = inp.size();
    int maxVal = *max_element(inp.begin(), inp.end());
    int minVal = *min_element(inp.begin(), inp.end());
    int bucketCount = max(1, n / 5);
    vector<vector<int>> buckets(bucketCount);

    for (int num : inp) {
        int index = (num - minVal) * bucketCount / (maxVal - minVal + 1);
        buckets[index].push_back(num);
    }

    vector<int> sortedArray;
    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
        sortedArray.insert(sortedArray.end(), bucket.begin(), bucket.end());
    }

    // Memory usage - buckets*bucket_size (N*k); N - sorted array

    return sortedArray;
}


bool isSorted(vector<int> A) {

    for (int i = 0; i < A.size() - 1; i++) {
        if (A[i] > A[i + 1]) {
            return false;
        }
    }

    return true;
}

#include <chrono>

using namespace std::chrono;

void saveFloatsToFile(const std::string& filename, const std::vector<double>& array, size_t size) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file '" << filename << "'" << std::endl;
        return;
    }

    // Set precision to 2 decimal places
    //file << std::fixed << std::setprecision(2);

    for (size_t i = 0; i < size; ++i) {
        file << array[i];
        // Add a space after each number, except for the last one
        if (i < size - 1) {
            file << " ";
        }
    }

    file.close();
}

#include <iomanip>

void test() {

    struct {
        vector<int> input;
    } tests[] = {
        {{3, 2, 3, 5, 5, 6, 7, -1, 1, 1}},
        {{-4230, -30871, 8350, 31573, -4560, 26867, 7963, -14825, -30320, -25886, -3425, 21796, -5926, -4723, 28773, -14113, 4422, 31343, -7459, -17973, 23938, 16471, -28152, 3044, 21589, 2582, -25409, 30792, -10096, 24302, -3271, -28029, 17770, 17602, 19072, -16750, 8470, -12205, -3753, -29649, 22343, 25237, 9822, 26580, 27124, 24818, -31721, -6089, -28305, -18236, -32321, -4097, -31937, -7501, 24250, 27201, 1820, 23891, -9748, -12179, 11921, 20436, -12740, -2681, -16588, 10278, -29079, 8776, 19381, -25970, -30158, 9672, 16489, -29555, -15454, 31007, -29291, -9714, -22160, 11475, -7259, -13835, -1413, -7617, -22962, -27311, -6394, 28188, -7382, -15572, 27736, -13731, 23561, 7357, -14508, 23727, 1976, 29582, 15943, -1329}},
        {{-18675, 26171, -19566, -10297, -18893, -31235, 20211, -29781, -6975, -9936, 18278, 6861, 21210, -4145, -11465, 26834, 24823, -16473, 27044, 4065, -29965, 15492, 21317, -7442, 8253, 23139, 21179, 11688, -12002, 14107, -29847, 29869, -32600, 8601, -23882, -8822, 13673, 8730, 11090, 7034, 1524, 24886, 12782, 5279, 11667, 5956, -25290, 3241, 2406, 5675, 4177, -19470, 17492, -10898, 29917, 2124, -8828, -10021, 28283, -12772, -18027, 32893, -20952, -12616, -24862, 30564, -7781, -29687, -27468, -2353, -29765, -14445, -30253, 4208, 13694, 24549, -24563, 7326, -14588, 28731, -6512, -30871, -17140, 5981, 20486, -14897, 19797, 19790, -31429, 14535, 22993, 25887, 11013, 12530, -10423, 14038, 10546, -4716, 10457, -12306, -9548, 1674, -19284, -1752, 245, 2398, 25757, 26220, 25893, -9485, 21744, -20238, -1448, -4681, -27724, 27366, -15770, 11582, 6412, -12415, -9708, 22551, -22012, -4451, -19688, 29541, -21100, -11023, 5293, 9140, 31268, 12831, 24560, -27066, 2574, -23642, -2320, 30741, -22295, 29745, 25429, -24715, 31772, 1719, 13752, -19515, 6354, -24951, -31145, -29776, -22943, 16785, -32626, 8889, -7312, 16388, 8795, -27327, 30827, -26352, -32385, -14180, 10685, 22325, 27614, 8233, 19913, 15824, 26467, -10696, 26708, -5645, 12286, -21207, 2114, -21656, -19156, 30243, 8281, -26154, 22205, 1207, -24013, -2063, 644, 3474, -17463, -19737, -20133, 17063, 1187, -2714, 16933, 2631, -3256, -19395, 29360, 27308, -26867, -26169, -3636, 14872, -16614, -27506, -7768, -7574, -27689, 24417, -30832, 681, 23344, 23238, -26995, 15018, 10678, 13265, 16896, 10087, 29966, -14221, 21878, 22761, 11430, -13231, 11505, -1547, 26232, 5896, 19198, -25593, 18560, -22543, 11463, 17616, 24420, -2491, -5001, -4808, 23315, 15180, 26321, 21009, -17373, 11232, 30210, -3734, 11263, -201, 19177, -17325, -13503, -13718, -14743, -5260, 30008, -19931, -29435, 32293, -18132, 2362, 23849, -26111, 15267, -25609, 2735, 23181, 2688, 15009, 7481, 20682, 2616, 23819, -30117, 17517, -5025, 3174, 15168, -15288, -8610, -9602, -15778, -16980, -9952, -24419, 7668, 6894, -11141, 32476, 9287, -1505, -20711, 32898, 11081, 26353, -21522, 11680, 11645, -11312, 30704, 2589, 17149, -5393, 14985, 3518, 8557, 18939, 9014, 19551, 24559, 11331, 30048, -13061, -7995, -6246, -2365, 19910, -31380, 20260, 30467, 32599, 3238, -438, 2666, -16306, 354, 15948, 12278, 23691, -11813, -944, -15453, -31595, -1871, -22672, -8153, 9215, -28829, -25348, 8878, -6622, -22288, -29695, -10817, 22969, 40, 32144, 25112, -24768, -31211, 8122, -16544, 6566, 29245, 1993, -3749, 1470, -20373, 14025, -30159, 2817, 9700, -11366, 22905, -2204, -5895, -4280, 3834, -19345, 18584, 31186, -5821, -2259, 2033, 7338, 14358, 16254, 4454, 13001, 29598, -5046, 16540, 19427, 32067, -9879, 5082, 32518, 4570, -9308, 1921, -26081, 14571, -23733, 15068, 17470, 19188, -12495, -7430, -6115, -32576, -9541, -23233, -6936, -4846, 7070, -24055, -7732, -2394, 11184, 25047, -9252, -26572, 2709, 25226, 268, -22672, -29884, -23004, -24854, 14990, 2261, -22431, -16117, 29641, 9230, 86, 20949, -24559, -789, 18998, -14530, -23033, -30226, -27123, -27830, -31454, -27680, 60, -6229, -1536, -24955, -2185, 20057, 29152, 19050, 22426, 4114, -26043, -27987, -19712, -11323, 24026, 13766, 155, -719, -5829, -20350, 8375, -21619, 15375, -640, -12232, 32274, 4856, -21310, -15513, 14271, -19381, 1183, 68, -30165, -30193, 24778, -22855, 5668, -19646, 16243, 32441, -16487, 803, -20096, 7318, 27736, 9671, -21628, 7978, 25361, 19587, 30263, 28558, -28186, -15318, 1510, 19529, 14438, 21524, 6606, -27656, -8184, 8311, -13746}},
        //{{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 9, 9}, {{1, 2, 3}, {4}, {5}, {6}, {7}, {8}, {9, 9, 9}, {10, 10, 10}}},
    };

    vector<string> files = { "test1.txt", "test2.txt", "test3.txt", "test4.txt", "test5.txt", "test6.txt", "test7.txt", "test8.txt", "test9.txt", "test10.txt", "test11.txt", "test12.txt", "test13.txt", "test14.txt", "test15.txt", "test16.txt", "test17.txt", "test18.txt", "test19.txt", "test20.txt", "test21.txt", "test22.txt", "test23.txt", "test24.txt", "test25.txt", "test26.txt", "test27.txt", "test28.txt", "test29.txt", "test30.txt", "test31.txt", "test32.txt", "test33.txt", "test34.txt", "test35.txt", "test36.txt", "test37.txt", "test38.txt", "test39.txt", "test40.txt", "test41.txt", "test42.txt", "test43.txt", "test44.txt", "test45.txt", "test46.txt", "test47.txt", "test48.txt", "test49.txt", "test50.txt", "test51.txt", "test52.txt", "test53.txt", "test54.txt", "test55.txt", "test56.txt", "test57.txt", "test58.txt", "test59.txt", "test60.txt", "test61.txt", "test62.txt", "test63.txt", "test64.txt", "test65.txt", "test66.txt", "test67.txt", "test68.txt", "test69.txt", "test70.txt", "test71.txt", "test72.txt", "test73.txt", "test74.txt", "test75.txt", "test76.txt", "test77.txt", "test78.txt", "test79.txt", "test80.txt", "test81.txt", "test82.txt", "test83.txt", "test84.txt", "test85.txt", "test86.txt", "test87.txt", "test88.txt", "test89.txt", "test90.txt", "test91.txt", "test92.txt", "test93.txt", "test94.txt", "test95.txt", "test96.txt", "test97.txt", "test98.txt" };

    vector<double> Bubbles;
    vector<double> Bucket;
    vector<double> Quick;

    int size = sizeof(tests) / sizeof(tests[0]);
    

    for (int i = 0; i < files.size(); i++) {

        std::ifstream file(files[i]);

        if (!file.is_open()) {
            std::cerr << "Error: Could not open the file '" << files[i] << "'" << std::endl;
            return;
        }

        vector<int> integers;

        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            int value;
            while (ss >> value) {
                integers.push_back(value);
            }
        }

        file.close();

        auto t = integers;

        auto start = high_resolution_clock::now();

        vector<int> out = BubbleSort(integers);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << duration.count() / 1000 << endl;

        double durationInSeconds = static_cast<double>(duration.count()) / 1'000;

        Bubbles.push_back(durationInSeconds);

        ASSERT_MSG(isSorted(out), i + 1);

        //


        start = high_resolution_clock::now();

        out = QuickSort(integers);

        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);

        cout << duration.count() / 1000 << endl;

        durationInSeconds = static_cast<double>(duration.count()) / 1'000;

        Quick.push_back(durationInSeconds);

        ASSERT_MSG(isSorted(out), i + 1);

        //

        start = high_resolution_clock::now();

        out = BucketSort(integers);

        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);

        cout << duration.count() / 1000 << endl;

        durationInSeconds = static_cast<double>(duration.count()) / 1'000;

        Bucket.push_back(durationInSeconds);

        ASSERT_MSG(isSorted(out), i + 1);

        if (i == 10) {
            break;
        }

        //break;

    }

    saveFloatsToFile("bubbles.txt", Bubbles, Bubbles.size());
    saveFloatsToFile("quick.txt", Quick, Bubbles.size());
    saveFloatsToFile("Bucket.txt", Bucket, Bubbles.size());

    cout << "All tests Passed!";

}

int main() {

    test();

    return 0;
}