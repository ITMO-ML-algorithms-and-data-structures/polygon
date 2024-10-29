#include <iostream>
#include <set>
#include <fstream>

using namespace std;
int main(){
    set<int> bezdoubl;///O(n)
    ifstream File("/Users/vitamija/Desktop/vita.tsv"); ///обратилась к файлу  O(1)
    int numbers;
    while (File >> numbers){///O(n)
        bezdoubl.insert(numbers);///O(log n)
    }
    File.close();///O(1)
    for (auto numbers : bezdoubl){ ///O(n)
        cout << numbers << ", "; ///O(n)
    }
}
