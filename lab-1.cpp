#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>

using namespace std;

bool isMappedvalue(unordered_map<char, char> &biection, const char &curr_el2) {

        for (const auto& [key, value] : biection) {

        if (value == curr_el2) {
            return true;
        }
    }

    return false;
}

bool isIsomorphic(const string &str1, const string &str2) {

    unordered_map<char, char> biection;

    //1 (char по 1 байту) * n + 1 * n + хранение цепочек 
    //+ незначительные затраты на хэш-функцию + 8 байт на указатель (64-битная)

     if (str1.empty() || str2.empty()) {
        return str1.empty() && str2.empty();
    }

    int size1 = str1.size(); //4 bytes

    if (size1 != str2.size()) {
        return false;
    }

    //проходим по элементам строки и проверяем,
    //можно ли построить биекцию между элементами двух строк

    for (size_t i = 0; i != size1; ++i) {
            
        char curr_el1 = str1[i]; //1 byte
        char curr_el2 = str2[i]; //1 byte


        //если элемента из строки 1 нет в ключах,
        //то проверяем есть ли элемент из строки 2 в значениях или нет
        //по сути проверка на инъективность нашего отображения

        if (biection.find(curr_el1) == biection.end()) {
            if (!isMappedvalue(biection, curr_el2)) {
                biection[curr_el1] = curr_el2;
            }
            else {
                return false;
            }

        //если такой ключ уже есть,
        //то проверяем не сопоставлено ли ему какое-то другое значение

        }
        else {
            if (biection[curr_el1] != curr_el2) {
                return false;
            }
        }
    }

    return true;
}


#include <gtest/gtest.h>

TEST(Tests, BaseTrue1){

    string str1 = "egg";
    string str2 = "add";

    ASSERT_TRUE(isIsomorphic(str1, str2));

}


TEST(Tests, BaseTrue2){

    string str1 = "paper";
    string str2 = "title";

    ASSERT_TRUE(isIsomorphic(str1, str2));

}

TEST(Tests, BaseFalse1){

    string str1 = "eg";
    string str2 = "add";

    ASSERT_FALSE(isIsomorphic(str1, str2));

}

TEST(Tests, BaseFalse2){

    string str1 = "hoops";
    string str2 = "horse";

    ASSERT_FALSE(isIsomorphic(str1, str2));

}

TEST(Big, True){

    string str1 = "abcdefghijklmnopqrstuvwxyz"; 
    string str2 = "zyxwvutsrqponmlkjihgfedcba";

    ASSERT_TRUE(isIsomorphic(str1, str2));

}

TEST(Big, False){

    string str1 = "abcdefghijklmnopqrstuvwxyz";
    string str2 = "zyxwvutsrqponmlkjihgfedcbz";

    ASSERT_FALSE(isIsomorphic(str1, str2));

}

TEST(NewCases, BothEmpty){

    string str1 = "";
    string str2 = "";

    ASSERT_TRUE(isIsomorphic(str1, str2));

}

TEST(NewCases, OneEmpty){

    string str1 = "";
    string str2 = "txt";

    ASSERT_FALSE(isIsomorphic(str1, str2));
}

TEST(NewCases, IdenticalChars){

    string str1 = "ada";
    string str2 = "dad";

    ASSERT_TRUE(isIsomorphic(str1, str2));

}

TEST(NewCases, OneIdenticalChar){

    string str1 = "adddampt";
    string str2 = "errreafq";

    ASSERT_TRUE(isIsomorphic(str1, str2));

}

int main(int argc, char **argv) {

    string str1, str2; //примерно n+1 байт, где n длина строки + 8 байт указатель + 8 байт длина на каждую

    ifstream file("../filename.txt");

    if (file.is_open()) {
        
        getline(file, str1);
        getline(file, str2); 
        
        file.close();
    }

    cout << boolalpha << isIsomorphic(str1, str2);

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();

}
