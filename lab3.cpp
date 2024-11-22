#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
string Inoutputer(string FILE_INPUT_FOLDER)
{
    ifstream in(FILE_INPUT_FOLDER);
    if (in.is_open())
    {
        string line;
        getline(in, line);
        in.close();
        return(line);
    }
    else
    {
        cout << "Error" << endl;
        in.close();
        return ("not detected file");
    }
}
void Inoutputer(const string& text, const string& filename) {
    ofstream outFile(filename);  // Открываем файл для записи

    if (outFile.is_open()) {
        outFile << text;  // Записываем строку в файл
        outFile.close();  // Закрываем файл
        cout << "Строка успешно записана в файл: " << filename << endl;
    }
    else {
        cout << "Ошибка: Не удалось открыть файл " << filename << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "Rus");
    string s_main1;
    string FILE_INPUT_FOLDER;
    cout << "ENTER THE FILE PATH" << endl;
    cin >> FILE_INPUT_FOLDER;
    s_main1 = Inoutputer(FILE_INPUT_FOLDER);
    string s_re;
    int c = 1;
    for (int i=0; i < s_main1.size()-1; i++)
    {
        if (s_main1[i] == s_main1[i + 1])
        {
            c++;
        }
        else
        {
            s_re += s_main1[i]+to_string(c);
            c = 1;
        }
    }
    Inoutputer(s_re, "C:\\Users\\Я\\Documents\\cpp_tests\\output.txt");
}
