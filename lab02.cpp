#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;

tuple<string, string> TEST_isomorhic_TRUE(int size){
    string s1 = "abcdefghijklmnopqrstuvwxyz1234567890";
    string s2 = "abcdefghijklmnopqrstuvwxyz1234567890";
    random_shuffle(s2.begin(), s2.end());
    
    
    srand(time(0)); // rand seed 
    
    vector<int> str0(size);
    for (int i = 0; i<size; i++){
        str0[i] = rand()% 36;
    }
    
    string str1(size,' ');
    string str2(size,' ');
    
    for (int i = 0; i<size; i++){
        str1[i]= s1[str0[i]];
        str2[i]= s2[str0[i]];
    }
    return make_tuple(str1,str2);
}

tuple<string, string> TEST_isomorhic_FALSE(int size){
    string s = "abcdefghijklmnopqrstuvwxyz1234567890";
    
    srand(time(0)); // rand seed 
    
    string str1(size,' ');
    string str2(size,' ');
    
    for (int i = 0; i<size; i++){
        str1[i]= s[rand()% 36];
        str2[i]= s[rand()% 36];
    }
    
    return make_tuple(str1,str2);
}

bool AreIsomorphic(const string &str1, const string &str2){
    if (str1.size() != str2.size()) return false; // Разная длина = не изоморфны
    unordered_map<char, char> mapping; //для хранения сопоставления символов из первой строки с символами второй строки
    unordered_map<char, bool> mapped; // для хранения проверенных символов
    
    for (int i = 0; i < str1.size(); i++) {
        char l1 = str1[i], l2 = str2[i]; // l - letter 
        if (mapping.find(l1) != mapping.end()) {    // сопоставление есть 
            if (mapping[l1] != l2) return false; //не совпало с базой

        } else {                                    // сопоставления нет 
            if (mapped[l2]) return false; //если проверенно 
            mapping[l1] = l2;             //если не проверенно 
            mapped[l2] = true;
        }
    }

    return true;
}

int main(){
    // string str1, str2;
    // cin >> str1 >> str2;

    // if (AreIsomorphic(str1, str2)) cout << "isomorphic";
    // else cout << "not isomorphic";
    
    int size = 50;
    
    
    //int size;
    //cout<<"num: ";
    //cin>>size;
    
    //TEST TRUE
    auto result = TEST_isomorhic_TRUE(size); 
    auto str1_1 = get<0>(result);
    auto str1_2 = get<1>(result);
    cout<< str1_1<<endl<<str1_2<<endl<<AreIsomorphic(str1_1,str1_2)<<endl<<endl<<endl;
    
    
    
    //TEST FALSE 
    auto result2 = TEST_isomorhic_FALSE(size);
    auto str2_1 = get<0>(result2);
    auto str2_2 = get<1>(result2);
    cout<<str2_1<<endl<<str2_2<<endl<<AreIsomorphic(str2_1,str2_2);
    return 0;
}

