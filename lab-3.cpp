#include <iostream>
#include <fstream>
#include <unordered_set>

using namespace std;
int main(){
    ifstream File("/Users/thevaldemar/PycharmProjects/dugun/numbers1.tsv");
    unordered_set<int> dubli;
    int number;
    while(File >> number){
        dubli.insert(number);
    }
    File.close();
    for (auto number : dubli){
        cout << number << " ";
    }
}
