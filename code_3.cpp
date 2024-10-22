#include <iostream>
#include <fstream>
#include <string>

// str = "aaabb"
// "a3b2"

using namespace std;

// это пием чтобы дать понять что не будем изменять входную строку 
// const string& input
// & - чтобы была ссылка, а не копия == память 
string reshalo_mother(const string& input) {
    int count = 1;           
    string new_stng_ans = "";  

    for (int i = 1; i <= input.length(); i++) {
        if (i < input.length() && input[i] == input[i - 1]) {
            count++; 
        } else {
            new_stng_ans += (input[i - 1] + to_string(count));
            count = 1;  
        }
    }

    return new_stng_ans;
}

int main() {
    ifstream laba_3_f("laba3_input.txt");  // Открываем 
    string stroka_from_fle;

    getline(laba_3_f, stroka_from_fle);  // Читаем 
    laba_3_f.close();  

    string my_result = reshalo_mother(stroka_from_fle);  // Сжимаем строку
    cout << "Отет " << my_result << endl;  
    return 0;
}
