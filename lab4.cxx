#include <iostream>
#include <fstream>
#include <string>  
#include <vector>
using namespace std;

vector<int> read_file(string name){ // O(1) 
    //vector<int> values[n];
    string line; // O(1) 
    std::ifstream in(name); 
    getline(in, line); // O(1) 
    int n = stoi(line); // O(1) + O(1)
    //cout<<n<<endl;
    vector<int> values(n); // O(1) 
    if (in.is_open()) {
        int i = -1; // O(1) + O(1)
        while (getline(in, line)) { // O(1) ;O(n+1)
            i = i+1; // O(1)
            int int1 = stoi(line); // O(1) + O(1)
            //cout<<int1<<"arbuz"<<endl;
            values[i] = int1; // O(1) 
        }
    }
    //for(int i = 0;i<=25;i++){cout<<values[i]<<endl;}
    return values;
}

int main(int argc, char *argv[])
{
	//cout<<6<<endl;
	vector<vector<int>> arr2(10000); // больше
	vector<vector<int>> arr21(10000); // можно заменить на вектор пуш
	vector<int> arr3(4);
	vector<int> arr31(4);
	string name = "lab4test2";
	vector<int> arr = read_file(name);
	//for(int i = 0;i<=25;i++){cout<<arr[i]<<endl;}
	int n = arr.size();
	int p = -1;
	for(int i = 0;i<n;i++){
	    for(int j = 0;j<n;j++){
	        if(i != j){
	        for(int k = 0;k<n;k++){
	            if(i != k & j != k){
	            for(int l = 0;l<n;l++){
	                if(i != l & j != l & k != l){
	                    //cout<<i<<j<<k<<l<<endl;
	                    int summ = arr[i] + arr[j] + arr[k] + arr[l];
	                    int o1 = arr[i];
	                    //cout<<o1<<endl;
	                    //cout<<summ<<endl;
	                    if(summ == 0){p = p + 1;arr3[0] = arr[i];arr3[1] = arr[j];arr3[2] = arr[k];arr3[3] = arr[l];arr2[p] = arr3;
	                    arr31[0] = i;arr31[1] = j;arr31[2] = k;arr31[3] = l;arr21[p] = arr31;}
	                }
	            }}
	        }}
	    }
	}
	//vector<int> t = arr2[1];
	//cout<<t[0]<<endl;
	int a;
	for(int i = 0;i<=p;i++){a = arr2[i][0];cout<<a<<" "<<arr2[i][1]<<" "<<arr2[i][2]<<" "<<arr2[i][3]<<endl;}
	
	//arr21
}
