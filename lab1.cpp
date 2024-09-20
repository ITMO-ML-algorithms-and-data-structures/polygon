#include <iostream>
#include <unordered_map>

using namespace std;


bool IsIsomorphism(const std::string& word1,const std::string& word2){
    std::unordered_map<char,char> symbols1;
    std::unordered_map<char,char> symbols2;
    if (word1.size() != word2.size()){
        return false;
    }
    for (int i = 0;i < word1.size();i++){
        if (symbols1.count(word1[i]) == 0){
            if (symbols2.count(word2[i]) != 0){
                return false;
            }
            symbols1[word1[i]] = word2[i];
            symbols2[word2[i]] = word1[i];
        }else{
            if (symbols2.count(word2[i]) == 0){
                return false;
            }
            char s1 = symbols1[word1[i]];
            char s2 = symbols2[word2[i]];
            if ((s1 != word2[i]) || (s2 != word1[i])){
                return false;
            }
        }

    }
    return true;
}



int main() {
    for (int i = 0;i < 10;i++){
        std::string w1,w2;
        std::cin >> w1 >> w2;
        if (IsIsomorphism(w1,w2)){
            std::cout << "true\n";

        } else{
            std::cout << "false\n";
        }
    }
    return 0;
}

