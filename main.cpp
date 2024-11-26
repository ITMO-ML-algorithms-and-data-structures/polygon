#include <iostream>
#include <vector>
#include <chrono> //to know the time
#include <unordered_set>
using namespace std;

const int MAX_VALUE = 100000;//4 bytes

vector<int> eliminarDuplicados(int arr[], int size) {
    vector<bool> encontrados(MAX_VALUE + 1, false); //vector, max+1 because we have to compare the 0 position, we start every position with false
    //MAX_VAlUE / 8 bytes
    vector<int> unicos;//24 bytes


    for (int i = 0;i < size;i++) {
        //4 bytes for i
        int ing = arr[i];
        //4 bytes for ing

        if(ing<0||ing>MAX_VALUE){
            throw out_of_range("dont allowed number: " + to_string(ing));
        }

        if (!encontrados[ing]) { // we compare encontrados with ing, and change the logic
            encontrados[ing] = true; // to save in the memory that we found that number
            unicos.push_back(ing); // add that number to unicos
            //every int use 4 bytes
        }


    }

    return unicos;

    /* Imprimir los elementos únicos
    cout << "Without doubles: ";
    for (int num : unicos) {
        cout << num << " ";
    }
    cout << endl;*/
}

/*int main() {

    //dataset
    int arr[] = {1, 2, 3, 1, 100000, 100000};
    int size = 5;

    //test
   vector <int> unicos = eliminarDuplicados(arr, size);

    // Imprimir los elementos únicos
    cout << "Without doubles: ";
    for (int num : unicos) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}*/

int main(){

    auto inicio = chrono::high_resolution_clock::now();

    //common test
   try {
       int arr1[] = {1, 2, 3, 3, 5, 6, 6};
       vector<int> resultado1 = eliminarDuplicados(arr1, 7);


       cout << "test1:  ";
       for (int num: resultado1)
           cout << num << " ";
       cout << endl;



       //test with empty
       int arr2[] = {};
       vector<int> resultado2 = eliminarDuplicados(arr2, 0);
       cout << "test2:  ";
       for (int num: resultado2)
           cout << num << " ";
       cout << endl;

       //test with limit case
       int arr3[] = {0, MAX_VALUE, 0};
       vector<int> resultadao3 = eliminarDuplicados(arr3, 3);
       cout << "test3:  ";
       for (int num: resultadao3)
           cout << num << " ";
       cout << endl;
   }
       catch (const exception &e){
           cout << "error";
       }


    auto fin = chrono::high_resolution_clock::now();
    auto duracion = chrono::duration_cast<chrono::seconds>(fin-inicio).count();

    cout << "time to process the dataset:"<< duracion <<"  sec."<<endl;

       //error test
       int arr4[] = {-1, 1};
       vector<int> resultados4 = eliminarDuplicados(arr4, 2);
       cout << "test4:  ";
       for (int num: resultados4)
           cout << num << " ";
       cout << endl;

    return 0;
}


