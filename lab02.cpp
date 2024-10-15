#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    map<char, char> alpha;
    vector<char> alredy_in_map;


    if (str1.size() != str2.size()) {
        cout << "False";
        return 0;
    }


    for (int i = 0; i <= str1.size(); i++) {
        if (alpha.count(str1[i])) {
            if (alpha[str1[i]] != str2[i]) {
                cout << "False";
                return 0;
            }
        }
        else {
            if (std::count(alredy_in_map.begin(), alredy_in_map.end(), str2[i])) {
                cout << "False";
                return 0;
            }

            alpha[str1[i]] = str2[i];
            alredy_in_map.push_back(str2[i]);
        }
    }
    cout << "True";




    return 0;
}
