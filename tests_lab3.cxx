#include <iostream>
#include <fstream>
#include <string>  
#include <vector>
#include "lab3main.h"
using namespace std;
 
int main(int argc, char *argv[]){
	srand(time(0));
	// test 1
	cout<<"тест 1"<<endl;
	string name = "lab3test1";
	vector<char> arr = read_file(name);
	vector<char> arr1 = randomize(arr);
	vector<char> arr2 = randomize(arr);
	/*
	vector<char> ar1 = {1,2,3,4};
	vector<char> ar2 = {1,2,4,3};
	bool a = ar1 == ar2;
	cout<<a;
	*/
	bool a = arr1 == arr2;
	if(a == 1){cout<<"равны, не пройден !"<<endl;} else {cout<<"не равны, пройден !"<<endl;}
	
	cout<<"тест 2"<<endl;
	//string name = "lab3test1";
	//vector<char> arr = read_file(name);
	vector<char> arr3 = randomize(arr);
	vector<char> arr4 = randomize(arr3);
	/*
	vector<char> ar1 = {1,2,3,4};
	vector<char> ar2 = {1,2,4,3};
	bool a = ar1 == ar2;
	cout<<a;
	*/
	bool a2 = arr3 == arr4;
	if(a2 == 1){cout<<"равны, не пройден !"<<endl;} else {cout<<"не равны, пройден !"<<endl;}
	
	cout<<"тест 3"<<endl;
	string name2 = "lab3test2";
	vector<char> arr0 = read_file(name2);
	vector<char> arr5 = randomize(arr0);
	//vector<char> arr6 = randomize(arr);
	/*
	vector<char> ar1 = {1,2,3,4};
	vector<char> ar2 = {1,2,4,3};
	bool a = ar1 == ar2;
	cout<<a;
	*/
	bool a3 = arr0 == arr5;
	bool a4 = arr0[0] == arr5[0];
	bool a5 = arr0[12] == arr5[12];
	if(a3 == 1 & a4 == 1 & a5 == 1){cout<<"равны, не пройден !"<<endl;} else {cout<<"не равны, пройден !"<<endl;}
	
	
	return 0;
}
