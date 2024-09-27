#include <iostream>
#include <map>
#include <string>  

using namespace std;

int isomorf(string st1, string st2) {
    // на вход размер строки на размер одного символа(1 байт) => n + m байт
    if (st1.size() != st2.size()) {
        return 0;
    }
    int len_str = st1.size(); //  + 4 байта

    map<char, char> slov1; 
    map<char, char> slov2;

    slov1[st1[0]] = st2[0]; // + 2 байта 
    slov2[st2[0]] = st1[0]; // + 2 байта 
    for (int i = 1; i <= len_str; i++){
        // + 1 байт
        if (slov1.find(st1[i]) != slov1.end()) {
            if (slov1[st1[i]] != st2[i]) return 0;
        }
        if (slov2.find(st2[i]) != slov2.end()) {
            if (slov1[st1[i]] != st2[i]) return 0;
        }
        if (slov1.find(st1[i]) != slov1.end() && slov2.find(st2[i]) != slov2.end()) {
            slov1[st1[i]] = st2[i]; // + 2 байта 
        }
    }
    return 1;
}

int main() {
    isomorf("aaaa", "bbb");
    cout <<  isomorf("aafa", "bhhb");
    return 0;
}
// в общем случае(в худшем) по памяти программа занимает (n+m) + 4 + 1 + 4 * (n+m), 
// где m и n размер входных строк в байтах