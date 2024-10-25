#include <string>
#include <vector>

using namespace std;

string compress(string src_string) 
{
    int len_string = src_string.size(); // O(1) + O(1) + O(1) выделяю память, присваиваю размер и вытаскиваю размер из строки
    string result_string = ""; // O(1) + O(1) выделил память, присвоил значение
    string letter; // O(1) выделил память
    string compressed_letter = ""; // O(1) + O(1) выделил память, присвоил значение
    int compress_length = 0; // O(1) + O(1) выделил память, присвоил значение
    for(int i = 0; i < len_string; i++) 
    // на первой итерации O(1) + O(1) + O(1) выделил память, присвоил начальное значение i,  сравнил с граничным значением len_string
    // на последующих итерациях O(1) + O(1) + O(1) сравниваю значение, увеличиваю его на единицу, присваиваю
    {
        letter = src_string[i] + string(); // O(1) + O(1) + O(1) + O(1) беру значение по индексу, выделил память под строку, записал значение в память, записываю всё в letter
        if (letter == compressed_letter) // O(1) сравнение элементов
        {
            compress_length++; // O(1) + O(1) увеличение на единицу, присваивание нового значения
        }
        else
        {
            if (compress_length > 1) // O(1) сравнение элементов
            {
                result_string += compressed_letter + to_string(compress_length); // O(1) + O(1) + O(1) + O(K) + O(L при L<=n) + O(1) беру compressed_letter, to_string, присваивание, выделение памяти, выделяю новую память под новую строку и записываю туда новое значение
            }
            if (compress_length == 1) // O(1) сравнение элементов
            {
                result_string += compressed_letter; // O(n) в худшем случае + O(1) так как выделение памяти + присваивание
            }
            compress_length = 1; // O(1) присваивание
            compressed_letter = letter; // O(1) присваивание
        }
    }
    if (compress_length > 1) // O(1) сравнение элементов
    {
        result_string += compressed_letter + to_string(compress_length); // O(1) + O(1) + O(1) + O(K) + O(L при L<=n) + O(1) беру compressed_letter, to_string, присваивание, выделение памяти, выделяю новую память под новую строку и записываю туда новое значение
    }
    if (compress_length == 1) // O(1) сравнение элементов
    {
        result_string += compressed_letter; // O(N) в худшем случае + O(1) так как выделение памяти + присваивание
    }
    // Слосжность алгоритма составляет:
    // O(N^2) в худшем случае, если ни одна буква не повторяется
    // O(N*(K+L)), K+L< N (где K сколько элементов я записываю при сжатии)б L - выделение памяти по итоговую строку
    // O(N) в лучшем случае, если одна буква повторяется во все строке
    return result_string;
}