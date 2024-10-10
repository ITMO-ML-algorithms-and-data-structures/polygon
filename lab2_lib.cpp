#include "lab2_lib.h"

bool IsIsomorphic(string str1, string str2) {
    //�� ���� str1 � str2 - ��� ������������������ ��������, ��� ������ ������ - 1 ����

    //auto s1 = sizeof(str1); ������ 40 ���� � �� ������� �� �����
    //auto s2 = sizeof(str1); ������ 40 ���� � �� ������� �� �����

    unordered_map<char, char> map1;    //+80 ����
    unordered_map<char, char> map2;    //+80 ����

    //auto s3 = sizeof(map1); ������ 80 ���� � ��� ���������� ��������� �� �������������
    //auto s4 = sizeof(map2); ������ 80 ���� � ��� ���������� ��������� �� �������������


    size_t str1Length = str1.length(); //+8 ����    
    size_t str2Length = str2.length(); //+8 ����

    if (str1Length != str2Length) {
        return false;
    }

    for (int i = 0; i < str1Length; ++i) { //+4 ����
        char str1_char = str1[i]; //+1 ����
        char str2_char = str2[i]; //+1 ����

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