#include "shuffle_list.cpp"

int main() {
    vector<int> input = {1, 2, 3, 4, 5, 0};
    if (shuffle(input) == vector<int> {3, 0, 2, 1, 5, 4}) {
        cout << "Тесты прошли успешно, солнышко! <3";
    } else {
        cout << "Ахахах, тесты завалены.. Ищи себя в прошмандовках тестирования)";
    }
    return 0;
}