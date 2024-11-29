#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<char> read_file(string name){ // O(1) 
    //vector<int> values[n];
    string line; // O(1) 
    std::ifstream in(name); 
    getline(in, line); // O(1) 
    int n = stoi(line); // O(1) + O(1)
    //cout<<n<<endl;
    vector<char> values(n); // O(1) 
    if (in.is_open()) {
        int i = -1; // O(1) + O(1)
        while (getline(in, line)) { // O(1) ;O(n+1)
            i = i+1; // O(1)
            int int1 = stoi(line); // O(1) + O(1)
            cout<<int1<<"arbuz"<<endl;
            values[i] = int1; // O(1) 
        }
    }
    return values;
}

vector<int> cocsort(vector<int> arr){
    int last = arr.size();
    bool flag = true;
    
    while(flag){
        flag = false;
        for(int i = 0;i<last-1;i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
                flag = true;
            }
        }
        --last;
    }
    return arr;
}

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;       // Корень
    int left = 2 * i + 1;  // Левый потомок
    int right = 2 * i + 2; // Правый потомок

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

vector<int> heapsort(vector<int> arr){
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    return arr;
}

vector<int> countsort(vector<int> arr){
    //int maxVal = *max_element(arr.begin(), arr.end());
    int max1 = arr[0];
    for(int i = 0;i<arr.size();i++){
        if(arr[i]>max1){max1 = arr[i];}
    }
    vector<int> count(max1 + 1, 0);
    for (int num : arr) {
        count[num]++;
    }
    int index = 0;
    for (int i = 0; i <= max1; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
    return arr;
}

int main(int argc, char *argv[])
{
	cout<<"Неотсортированный: ";
	vector<int> arr = {4,8,2,6,3,9,1,2};
	for(int i= 0;i<arr.size();i++){
	    cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"Коктель: ";
	vector<int> cocarr = cocsort(arr);
	for(int i= 0;i<cocarr.size();i++){
	    cout<<cocarr[i]<<" ";
	}
	cout<<endl;
	cout<<"Кучей: ";
	vector<int> heaparr = heapsort(arr);
	for(int i= 0;i<heaparr.size();i++){
	    cout<<heaparr[i]<<" ";
	}
	cout<<endl;
	cout<<"Подсчëт: ";
	vector<int> countarr = countsort(arr);
	for(int i= 0;i<countarr.size();i++){
	    cout<<countarr[i]<<" ";
	}
	cout<<endl<<endl;
	
	cout<<"Неотсортированный 2: ";
	arr = {0,0,9,86,-6,23,6,0,-7,-48,63,4,90,2};
	for(int i= 0;i<arr.size();i++){
	    cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"Коктель: ";
	cocarr = cocsort(arr);
	for(int i= 0;i<cocarr.size();i++){
	    cout<<cocarr[i]<<" ";
	}
	cout<<endl;
	cout<<"Кучей: ";
	heaparr = heapsort(arr);
	for(int i= 0;i<heaparr.size();i++){
	    cout<<heaparr[i]<<" ";
	}
	cout<<endl;
	cout<<"Подсчëт: ";
	countarr = countsort(arr);
	for(int i= 0;i<countarr.size();i++){
	    cout<<countarr[i]<<" ";
	}
	cout<<endl;
	cout<<"подсчëт не работает с отрицательными, но можно поставить начало не с 0, а с минимального элемента и тогда всë будет работать.";
}
