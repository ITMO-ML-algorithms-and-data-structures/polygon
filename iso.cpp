#include <iostream> 
#include <unordered_map> 
#include <string> 
#include <cassert>

 
bool Iso(const std::string& a, const std::string& b) {
    // Если длины строк не равны, они не могут быть изоморфными
    if (a.length() != b.length()) {
        return false; 
    }

    // Создаем двe хеш-таблицы для отслеживания соответствий символов
    std::unordered_map<char, char> one; //O(n) 
    std::unordered_map<char, char> reverseone;
    // O(n) + 3 * 1 байт * 2 мапы

    // Итерируемся по каждому символу строк
    for (size_t i = 0; i < a.length(); ++i) {
        char charA = a[i]; 
        char charB = b[i]; 
        // + 1 байт * 2
        
        if (one.count(charA)) { 
            if (one[charA] != charB) { // Проверяем, совпадает ли с charB
                return false; 
            }
        } else { 
            one[charA] = charB; // Устанавливаем новое соответствие так как его еще нет
        }

        
        if (reverseone.count(charB)) { // Если уже есть соответствие для charB
            if (reverseone[charB] != charA) { // Проверяем, совпадает ли оно с charA
                return false; 
            }
        } else { 
            reverseone[charB] = charA; 
        }
    }

    return true; // Если все проверки пройдены, строки изоморфны
}
void runTests() {
    // Тесты с обычными значениями
    assert(Iso("egg", "add") == true);
    assert(Iso("foo", "bar") == false);
    // (3 * 1 + 1 (за ноль) + 4 (за длину)) * 2

    // Пограничные значения
    assert(Iso("", "") == true); // Пустые строки
    assert(Iso("a", "a") == true); // Одна буква, совпадающая
    assert(Iso("a", "b") == true); // Одна буква, разные

    // Проверка на разные длины строк
    assert(Iso("abc", "defg") == false); 
}

int main() {
    runTests();
    return 0;
}

// в итоге память это 2 * O(4) + 3 * 1 байт * 2 мапы + 1 байт * 2 + (3 * 1 + 1 (за ноль) + 4 (за длину)) * 2 = 32 байта


