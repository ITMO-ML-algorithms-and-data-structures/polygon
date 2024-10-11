// Ежов Дмитрий j3113 471242
// Lab2 Hard lvl :  
// Реализовать функцию, которая определяет, являются ли две строки изоморфными
// a-z A-Z а-я А-Я 0-9
#include <cassert>
#include <map>
#include <string>
#include <locale>

bool is_isomorf(const std::wstring& a,const std::wstring& b)
{
    
/*
Память: a.size()*4 байт + b.size()*4 байт + в худшем случае a.size()*2*4 байт в map (+ доп данные в string, map) = O(n)
Сложность: O(n)
*/
    if(a.size() != b.size())
        return false;
    std::map<wchar_t, wchar_t> isomorf;
    for(int i = 0; i < a.size(); ++i)
    {
        if(isomorf.find(a[i]) == isomorf.end())
            isomorf[a[i]] = b[i];
        else if(isomorf[a[i]] != b[i])
        {
            return false;
        }
    }
    return true;
}

#include <iostream>
int main()
{    
    std::locale::global(std::locale("ru_RU.UTF-8"));

    assert(is_isomorf(L"", L"") == true);
    assert(is_isomorf(L"11", L"1") == false);
    assert(is_isomorf(L"1", L"11") == false);
    assert(is_isomorf(L"aaa", L"aaa") == true);
    assert(is_isomorf(L"abc", L"rgt") == true);
    assert(is_isomorf(L"rrrtttyyy", L"bbbmmmnnn") == true);
    assert(is_isomorf(L"zxcvb", L"asdfg") == true);
    assert(is_isomorf(L"Giiittt 123", L"Caaattt 654") == true);
    assert(is_isomorf(L"УРААА 123", L"УКЕЕЕ 654") == true);


    std::wstring a, b;
    std::wcin >> a >> b;
    std::cout << (is_isomorf(a, b)?"True":"False") << std::endl;
}