#include <iostream>
#include <set>
#include <fstream>
using namespace std;
int main(){
    set<int> MySet;///O(n)
    ifstream File("/Users/thevaldemar/PycharmProjects/dugun/numbers1.tsv");///O(1)
    int numbers;
    while (File >> numbers){///O(n)
        MySet.insert(numbers);///O(n)
    }
    File.close();///O(1)
    for (auto numbers : MySet){///O(n)
        cout << numbers << " ";///O(n)
    }
}
