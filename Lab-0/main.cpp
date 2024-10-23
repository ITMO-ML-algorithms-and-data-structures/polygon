#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<pair<int, int>> f( vector<int>& e, int s) {


     set<pair<int, int>> res;
     set<int>numb;
     for (size_t i = 0; i < e.size(); ++i){
       numb.insert(e[i]);
     }


      for (size_t i = 0; i < e.size(); ++i) {
       int numb1= s- e[i];
       if (numb.count(numb1)){
         if (res.count(make_pair(numb1,e[i])) == 0){
             res.insert(make_pair(e[i],numb1));}
           }
    }

    return res;

}


int main() {
    int s;
    cout << "Введите сумму пары:";
    cin >> s;

    int arraySize;
    cout << "Введите размер массива: ";
    cin >> arraySize;

    vector<int> e(arraySize);
    cout << "Введите элементы массива: ";
    for (int i = 0; i < e.size(); i++){
        cin >> e[i];
    }



    set<pair<int, int>> pairs;

    pairs = f(e, s);


    for (const auto pair : pairs) {
        cout << "(" << pair.first << ", " << pair.second << ")" << endl;
    }

    return 0;
}