#include <vector>
#include <string>
#include <cassert>
#include <unordered_map>


bool isomorphString(const std::string& string1,const std::string& string2){
    if (string1.size() != string2.size()) // O(1)
        return 0;
    const unsigned short& stringSize = string1.size(); // O(1) (макс. длина 1e4 * 2 ~= 2 байт)
    std::unordered_map <char, char> mapMatch; // O(1) Хэш-таблица соотв элементов первой строки и второй строки
    for (unsigned short i = 0; i < stringSize; ++i){ // O(n)
        const char& symbstring1 = string1[i], symbstring2 = string2[i]; // O(1)
        bool symb1find = mapMatch.find(symbstring1) == mapMatch.end(); // O(1)
        bool symb2find = mapMatch.find(symbstring2) == mapMatch.end(); // O(1)
        if (symb1find && symb2find){
            mapMatch[symbstring1] = symbstring2; // O(1)
            mapMatch[symbstring2] = symbstring1; // O(1)
        }
        else if (!symb1find && !symb2find){ // O(1)
            if (mapMatch[symbstring1] != symbstring2) // O(1)
                return false;
        }
        else 
            return false;
    }
    return true;
}


bool check(const std::string& inputString1, const std::string& inputString2, bool ans){
    if (ans == isomorphString(inputString1, inputString2)) return true;
    else return false;
}


void test(){
    std::string inputString1, inputString2;
    bool ans;

    inputString1 = "egg";
    inputString2 = "add";
    ans = true;
    assert(check(inputString1, inputString2, ans));
    
    inputString1 = "foo";
    inputString2 = "bar";
    ans = false;
    assert(check(inputString1, inputString2, ans));
    
    inputString1 = "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxx";
    inputString2 = "xxYYzzAABBCCDDEEFFGGHHIIJJKKLLMMNNOOPPQQRRSSTTaa";
    ans = true;
    assert(check(inputString1, inputString2, ans));
    
    inputString1 = "11223344556677889900aabbccddeeffgghhiijjkkllmmnn";
    inputString2 = "mmnnooppqqrrssttuuvvwwxxyyzzAABBCCDDEEFFGGHH1122";
    ans = true;
    assert(check(inputString1, inputString2, ans));

    inputString1 = "ppqqrrssttMMNNwwppYYzzAABBUUDDWWXXGGZZIIJJCCttM";
    inputString2 = "ttMMNNwwppqqrrssttUUVVWWXXYYZZAABBCCDDEEFFGGppq";
    ans = true;
    assert(check(inputString1, inputString2, ans));

    inputString1 = "fffggghhhiiijjjkkklllmmmnnnooopppqqqrrrsssttuuu";
    inputString2 = "uuuvvvwwwxxxyyyzzzAAABBBCCCDDEEEFFFGGGHHHIIJJJJ";
    ans = false;
    assert(check(inputString1, inputString2, ans));
}


int main(){
    test();
    return 1;
}