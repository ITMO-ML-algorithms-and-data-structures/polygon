#include "lab2_lib.h"

bool IsIsomorphic(string str1, string str2) {
    //на вход str1 и str2 - это последовательность символов, где каждый символ - 1 байт

    //auto s1 = sizeof(str1); всегда 40 байт и не зависит от длины
    //auto s2 = sizeof(str1); всегда 40 байт и не зависит от длины

    unordered_map<char, char> map1;    //+80 байт
    unordered_map<char, char> map2;    //+80 байт

    //auto s3 = sizeof(map1); всегда 80 байт и при добавлении элементов не увеличивается
    //auto s4 = sizeof(map2); всегда 80 байт и при добавлении элементов не увеличивается


    size_t str1Length = str1.length(); //+8 байт    
    size_t str2Length = str2.length(); //+8 байт

    if (str1Length != str2Length) {
        return false;
    }

    for (int i = 0; i < str1Length; ++i) { //+4 байт
        char str1_char = str1[i]; //+1 байт
        char str2_char = str2[i]; //+1 байт

        if (map1[str1_char] && map1[str1_char] != str2_char)
            return false;
        
        if (map2[str2_char] && map2[str2_char] != str1_char)
            return false;
        
        map1[str1_char] = str2_char;
        map2[str2_char] = str1_char;

        //s3 = sizeof(map1);
        //s4 = sizeof(map2);

    }
    return true;
}